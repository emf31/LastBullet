#include <SensorySystem\SensoryMemory.h>
#include <Enemy_Bot.h>
#include <Vec2f.h>

SensoryMemory::SensoryMemory(Enemy_Bot* myBot, double span):m_bot(myBot),m_memorySpan(span)
{
}

SensoryMemory::~SensoryMemory()
{
}

void SensoryMemory::updateVision()
{
	std::list<Entity*>lista = EntityManager::i().getCharacters();
	for (std::list<Entity*>::iterator it = lista.begin(); it != lista.end(); ++it) {
		if (m_bot != (*it)) {
			updateNewEnemies(*it);
			Memory& mymemory = m_botMemory[*it];

			if (!isRaycastObstructed(*it)) {
				std::cout << "Raycast OK" << std::endl;
				
				if (isInFOV(*it)) {
					std::cout << "Te veo" << std::endl;
				}

			}


		}
	}
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
	btVector3 start = btVector3(m_bot->getRenderPosition().getX(), m_bot->getRenderPosition().getY(), m_bot->getRenderPosition().getZ());
	btVector3 target = btVector3(ent->getRenderPosition().getX(), ent->getRenderPosition().getY(), ent->getRenderPosition().getZ());

	btCollisionWorld::ClosestRayResultCallback ray(start, target);

	PhysicsEngine::i().m_world->rayTest(start, target, ray);

	if (ray.hasHit())//si ray ha golpeado algo entro
	{
		//Veo la entity que colisiona
		Entity* ent = static_cast<Entity*>(ray.m_collisionObject->getUserPointer());
		if (ent != EntityManager::i().getEntity(PLAYER))
		{
			return true;
		}
	}
	return false;
}

bool SensoryMemory::isInFOV(Entity * ent) const
{
	Vec3<float>aux = m_bot->getFacing();
	Vec2f facing = Vec2f(aux.getX(), aux.getY());
	Vec2f pos1 = Vec2f(m_bot->getRenderPosition().getX(), m_bot->getRenderPosition().getZ());
	Vec2f pos2 = Vec2f(ent->getRenderPosition().getX(), ent->getRenderPosition().getZ());

	Vec2f vector = Vec2f(pos2 - pos1).Normalize();

	return facing.Dot(vector) >= cos(DegToRad(90) / 2.0);
}

std::list<Entity*> SensoryMemory::GetListOfRecentlySensedEnemies() const
{
	std::list<Entity*>myEnemies;
	double currentTime;
	return myEnemies;
}

void SensoryMemory::updateNewEnemies(Entity* ent)
{
	if (m_botMemory.find(ent) == m_botMemory.end()) {
		m_botMemory[ent] = Memory();
	}
}


