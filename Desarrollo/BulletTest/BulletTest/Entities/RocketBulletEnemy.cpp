
#include <RocketBulletEnemy.h>
#include <MessageHandler.h>
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <Util.h>


#include <list>

//Esta clase representa un rocket bullet disparado desde un enemigo. La diferencia con el rocket bullet
//normal es que este cuando colisiona no hace daño ya que esta comprobacion ya se hace desde el cliente enemigo
//que dispara dicho rocket.

RocketBulletEnemy::RocketBulletEnemy(Vec3<float> position, Vec3<float> direction, Vec3<float> rotation) : EntActive(-1, NULL, "bala"),
m_position(position), m_direction(direction), m_velocity(80), m_rotation(rotation)
{
	m_lifetime = seconds(3);
	//cargarContenido();
}


RocketBulletEnemy::~RocketBulletEnemy()
{
}

void RocketBulletEnemy::inicializar()
{
}

void RocketBulletEnemy::update(Time elapsedTime)
{
	btVector3 aux(m_direction.getX(), m_direction.getY(), m_direction.getZ());
	m_rigidBody->setLinearVelocity(aux*m_velocity);

	btVector3 Point = m_rigidBody->getCenterOfMassPosition();
	m_renderState.updatePositions(Vec3<float>((float)Point[0], (float)Point[1], (float)Point[2]));

	if (timelifeclock.getElapsedTime().asSeconds() > m_lifetime.asSeconds()) {

		//Enviamos mensaje de borrado para no borrar la entity mientras iteramos el mapa de entities
		Message msg1(this, "BORRATE", NULL);
		MessageHandler::i().sendMessage(msg1);
	}
}

void RocketBulletEnemy::handleInput()
{
}

void RocketBulletEnemy::cargarContenido()
{
	m_nodo = GraphicEngine::i().createNode(m_position, Vec3<float>(0.03f, 0.03f, 0.03f), "", "../media/bullets/rocketbullet.obj");
	m_renderState.setPosition(m_position);
	m_nodo->setRotationXYZ(m_rotation);
	m_renderState.setRotation(m_rotation);

	m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(1.f, 1.f, 1.f), 1, false);
	btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::RocketEnemy;
	proxy->m_collisionFilterMask = col::rocketenemyCollidesWith;
	m_rigidBody->setCollisionFlags(4);
}

void RocketBulletEnemy::borrarContenido()
{
	GraphicEngine::i().removeNode(m_nodo);

}

void RocketBulletEnemy::handleMessage(const Message & message)
{

	if (message.mensaje == "COLLISION" || message.mensaje == "BORRATE") {

		TBillboard* bill = SceneManager::i().crearBillBoard(cons(m_rigidBody->getWorldTransform().getOrigin()));
		bill->setFrameTime(milliseconds(20.f));
		bill->setScale(Vec3<float>(3.f, 3.f, 3.f));
		PhysicsEngine::i().removeRigidBody(m_rigidBody);
		EntityManager::i().removeEntity(this);

	}
}

bool RocketBulletEnemy::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}

std::string RocketBulletEnemy::getClassName()
{
	return "RocketBulletEnemy";
}

void RocketBulletEnemy::setPosition(const Vec3<float>& pos)
{
}

float RocketBulletEnemy::explosion(Vec3<float> posExplosion, Vec3<float> posCharacter, float radio)
{

	//TODO aqui podriamos dibujar la shape

	return 0;

}
