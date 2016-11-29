#include "RocketBullet.h"
#include "../Handlers/MessageHandler.h"
#include "../Motor/GraphicEngine.h"
#include "../Motor/PhysicsEngine.h"
#include "../Otros/Util.h"
#include "../Motor de Red/Cliente.h"


#include <list>



RocketBullet::RocketBullet(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation) : Entity(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(65), m_rotation(rotation), radioExplosion(40)
{

	//NOTA: llevar cuidado con esto puede que pete aqui
	cargarContenido();
}


RocketBullet::~RocketBullet()
{
}

void RocketBullet::inicializar()
{
}

void RocketBullet::update(Time elapsedTime)
{
		btVector3 aux(m_direction.getX(), m_direction.getY(), m_direction.getZ());
		m_rigidBody->setLinearVelocity(aux*m_velocity);

		btVector3 Point = m_rigidBody->getCenterOfMassPosition();
		m_renderState.updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));

		// Set rotation
		vector3df Euler;
		const btQuaternion& TQuat = m_rigidBody->getOrientation();
		quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
		q.toEuler(Euler);
		Euler *= RADTODEG;

		m_renderState.updateRotations(Vec3<float>(Euler.X, Euler.Y, Euler.Z));
}

void RocketBullet::handleInput()
{
}

void RocketBullet::cargarContenido()
{
	m_nodo = std::shared_ptr<SceneNode>(GraphicEngine::i().createNode(m_position, Vec3<float>(1, 1, 1), "../media/redTexture.jpg", ""));
	m_renderState.setPosition(m_position);
	m_renderState.setRotation(m_rotation);


	m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(1.f, 1.f, 1.f), 1);
	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Rocket;
	proxy->m_collisionFilterMask =  col::rocketCollidesWith;
	//Sin respuesta a la colision mejor asi porque es mas optimo
	m_rigidBody->setCollisionFlags(4);
	radioExplosion = 40.f;
}

void RocketBullet::borrarContenido()
{
}

void RocketBullet::handleMessage(const Message & message)
{
	float damage = 0;

	if (message.mensaje == "COLLISION") {

		//if (static_cast<Entity*>(message.data)->getClassName() != "Player") {
			
			if (estado == DISPONIBLE) {
				/*m_explosion = PhysicsEngine::i().createSphereShape(this, 40.f);
				m_explosion = PhysicsEngine::i().createSphereShape(this, radioExplosion);*/
				list<Entity*>characters = EntityManager::i().getCharacters();
				///Explosion
				for (list<Entity*>::Iterator it = characters.begin(); it != characters.end(); it++) {

					Entity* myentity = *it;
					
					damage = explosion(myentity,cons(m_rigidBody->getCenterOfMassPosition()), myentity->getRenderPosition(), radioExplosion);
					//std::cout << "Le resto " << damage << " a " << myentity->getName() << std::endl;
					std::cout << "Le resto " << damage << " a " << myentity->getName() << std::endl;

					if (Cliente::i().isConected() ) {
						if (damage > 0) {
							std::cout << "entro en el if con damage=" << damage << "y la entity es: " << myentity->getName() << std::endl;
							Cliente::i().impactoRocket(myentity->getGuid(), damage);
						}
					}else {
						std::cout << "entro en el else con damage=" << damage << std::endl;
						myentity->restaVida(damage);

						//TODO: si estas jugando en un solo player aqui tendras que quitarle vida a la IA
					}

				}

				btVector3 Point = m_rigidBody->getCenterOfMassPosition();
				m_renderState.updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));

				PhysicsEngine::i().removeRigidBody(m_rigidBody);

				EntityManager::i().removeEntity(this);
			}
			
		//}

	}

}

std::string RocketBullet::getClassName()
{
	return "RocketBullet";
}

float RocketBullet::explosion(Entity* player,Vec3<float> posExplosion, Vec3<float> posCharacter, float radio)
{
	float vidaRestada = 0;

	Vec3<float> vector = posExplosion - posCharacter;
	float distancia = vector.Magnitude();
	if (distancia < radio) {
		//printf("Te ha dado la explosion\n");
		if (distancia < radio / 3) {
			vidaRestada = 100;
		}
		else {
			//(radio-distancia)/((2*radio)/3)
			vidaRestada = 100 * ((radio - distancia) / ((2 * radio) / 3));
		}


		btVector3 FUERZA(vidaRestada/2.3, vidaRestada/2.3, vidaRestada/2.3);

		Vec3<float> posExplosion = cons(m_rigidBody->getCenterOfMassPosition());
		Vec3<float> posPlayer = player->getRenderPosition();

		Vec3<float> direccion = posPlayer - posExplosion;

		direccion.normalise();

		btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

		btVector3 force = direccion2 * FUERZA;

		/*m_rigidBody = PhysicsEngine::i().createCapsuleRigidBody(this, 1.25f, 0.5f, 1.f);
		btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
		proxy->m_collisionFilterGroup = col::Collisions::Rocket;
		proxy->m_collisionFilterMask = col::rocketCollidesWith;*/

		static_cast<Player*>(player)->p_controller->applyImpulse(force);
	}
	else {
		//printf("NO te ha dado la explosion\n");

	}

	return vidaRestada;

}
