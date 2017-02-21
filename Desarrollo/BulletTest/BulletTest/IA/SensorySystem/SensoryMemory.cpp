#include <SensorySystem\SensoryMemory.h>
#include <Enemy_Bot.h>
#include <Vec2f.h>

#include "../IA/StatesIA/Perseguir.h"


SensoryMemory::SensoryMemory(Enemy_Bot* myBot, double span):m_bot(myBot),m_memorySpan(span)
{
}

SensoryMemory::~SensoryMemory()
{
}

void SensoryMemory::updateVision()
{
	try {

		std::list<Entity*>lista = EntityManager::i().getCharacters();
		for (std::list<Entity*>::iterator it = lista.begin(); it != lista.end(); ++it) {
			if (m_bot != (*it)) {
				updateNewEnemies(*it);
				Memory& mymemory = m_botMemory[*it];


				if (!isRaycastObstructed(*it)) {
					//std::cout << "Raycast OK" << std::endl;
					mymemory.m_isShootable = true;

					if (isInFOV(*it)) {
						//mymemory.m_inFOV = true;
						mymemory.m_lastTimeSensed = sensoryClock.getElapsedTime().asSeconds();
						mymemory.m_lastTimeVisible = sensoryClock.getElapsedTime().asSeconds();
						mymemory.m_lastPosition = (*it)->getRenderState()->getPosition();
						if (!mymemory.m_inFOV) {
							mymemory.m_inFOV = true;
							mymemory.m_TimeBecameVisible = mymemory.m_lastTimeSensed;
						}

					}
					else {
						mymemory.m_inFOV = false;
						//std::cout << "Entro en fov false" << std::endl;
					}
				}
				else {
					//std::cout << "Entro en raycast false" << std::endl;
					mymemory.m_inFOV = false;
					mymemory.m_isShootable = false;
				}


			}
		}
	}
	catch (std::runtime_error e) {
		//Se sale de la ejecucion en caso de que de un error matematico en el angulo porque da NAN
	}
}

void SensoryMemory::updateSound(Entity * ent)
{
	updateNewEnemies(ent);
	Memory& mymemory = m_botMemory[ent];
	if (!isRaycastObstructed(ent)) {
		mymemory.m_isShootable = true;
		mymemory.m_lastPosition = ent->getRenderState()->getPosition();
	}
	else {
		mymemory.m_isShootable = false;
	}
	mymemory.m_lastTimeSensed = sensoryClock.getElapsedTime().asSeconds();
}

bool SensoryMemory::isEnemyShootable(Entity * ent) const
{
	if (m_botMemory.find(ent) != m_botMemory.end()) {
		Memory mem = m_botMemory.find(ent)->second;
		return mem.m_isShootable;
	}
	return false;
}

bool SensoryMemory::isEnemyInFOV(Entity * ent) const
{
	if (m_botMemory.find(ent) != m_botMemory.end()) {
		Memory mem = m_botMemory.find(ent)->second;
		return mem.m_inFOV;
	}
	return false;
}

bool SensoryMemory::isRaycastObstructed(Entity * ent) const
{
	//****************************RayCast central***************************************
	btVector3 start = btVector3(m_bot->getRenderState()->getPosition().getX(), m_bot->getRenderState()->getPosition().getY(), m_bot->getRenderState()->getPosition().getZ());
	btVector3 target = btVector3(ent->getRenderState()->getPosition().getX(), ent->getRenderState()->getPosition().getY(), ent->getRenderState()->getPosition().getZ());
	btVector3 vector = target - start;
	vector.normalize();

	start = start + (vector * 5);

	btCollisionWorld::ClosestRayResultCallback ray(start, target);
	

	PhysicsEngine::i().m_world->rayTest(start, target, ray);

	if (ray.hasHit())//si ray ha golpeado algo entro
	{
		//Veo la entity que colisiona
		Entity* ent = static_cast<Entity*>(ray.m_collisionObject->getUserPointer());
		if (ent->getClassName()=="PhysicsEntity")
		{
			return true;
		}
	}
	return false;
}

bool SensoryMemory::isInFOV(Entity * ent) const
{

	//std::cout << "facing= " << m_bot->getFacing() << std::endl;

	Vec3<float> positionBot = m_bot->getRenderState()->getPosition();
	Vec3<float> positionEnt = ent->getRenderState()->getPosition();

	Vec2f facing = m_bot->getFacing().Normalize();
	Vec2f pos1 = Vec2f(positionBot.getX(), positionBot.getZ());
	Vec2f pos2 = Vec2f(positionEnt.getX(), positionEnt.getZ());

	Vec2f vector = Vec2f(pos2 - pos1).Normalize();



	double angle = acos(facing.Dot(vector));

	//std::cout << "facing= " << facing << std::endl;
	//std::cout << "vector= " << (vector) << std::endl;
	

	if (std::isnan(angle)) {
		throw std::runtime_error("SENSORYMEMORY::isInFOV: Da un numero NAN");
	}

	//std::cout << "Angulo= " << (angle) << std::endl;
	//if(angle!= -1#IND)
	return angle <= m_bot->getFOV();
}

Vec3<float> SensoryMemory::GetLastRecordedPositionOfOpponent(Entity *ent) const
{
	auto it=m_botMemory.find(ent);
	if (it != m_botMemory.end()) {
		return (*it).second.m_lastPosition;
	}

	throw std::runtime_error("SENSORYMEMORY::GetLastRecordedPositionOfOpponent>: Intentando conseguir posicion de un bot que no has guardado");
}

double SensoryMemory::GetTimeOpponentHasBeenVisible(Entity * ent) const
{
	auto it = m_botMemory.find(ent);
	if (it != m_botMemory.end() && (*it).second.m_inFOV == true) {
		return sensoryClock.getElapsedTime().asSeconds() - (*it).second.m_TimeBecameVisible;
	}

	return 0.0;
}

double SensoryMemory::GetTimeSinceLastSensed(Entity * ent) const
{
	auto it = m_botMemory.find(ent);
	if (it != m_botMemory.end() && (*it).second.m_inFOV == true) {
		return sensoryClock.getElapsedTime().asSeconds() - (*it).second.m_lastTimeSensed;
	}

	return 0.0;
}

double SensoryMemory::GetTimeOpponentHasBeenOutOfView(Entity * ent) const
{
	auto it = m_botMemory.find(ent);
	if (it != m_botMemory.end()) {
		return sensoryClock.getElapsedTime().asSeconds() - (*it).second.m_TimeBecameVisible;
	}

	return 0.0;
}

std::list<Entity*> SensoryMemory::GetListOfRecentlySensedEnemies() const
{
	//TODO
	std::list<Entity*>myEnemies;
	double currentTime = sensoryClock.getElapsedTime().asSeconds();
	for (auto it = m_botMemory.begin(); it != m_botMemory.end(); ++it) {
		if (currentTime - (*it).second.m_lastTimeSensed <= m_memorySpan){
			myEnemies.push_back((*it).first);
		}
	}
	return myEnemies;
}

void SensoryMemory::updateNewEnemies(Entity* ent)
{
	if (m_botMemory.find(ent) == m_botMemory.end()) {
		m_botMemory[ent] = Memory();
	}
}


