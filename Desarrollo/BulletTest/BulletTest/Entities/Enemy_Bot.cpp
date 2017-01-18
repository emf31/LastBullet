#include "Enemy_Bot.h"
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <PathPlanner.h>
#include <PathFollow.h>

Enemy_Bot::Enemy_Bot(const std::string & name, RakNet::RakNetGUID guid) : Entity(-1, NULL, name, guid)
{
}

Enemy_Bot::~Enemy_Bot()
{
}

void Enemy_Bot::inicializar()
{
	m_PathPlanner = new PathPlanner(this);
	m_PathFollow = new PathFollow(this);
}

void Enemy_Bot::update(Time elapsedTime)
{

	updateAnimation();

	updateMovement();

	/*if (isAtPosition(m_Target) && !m_camino.empty())
	{
		//Marcamos como objetivo actual el siguiente nodo del camino
		m_Target = m_camino.front();
		
		//Como es nuestro objetivo lo eliminamos ya de la lista
		m_camino.pop_front();

		//Lo marcamos como objetivo
		m_PathFollow->SetTarget(m_Target);

		//Es el ultimo nodo
		if (m_camino.size() == 0) {
			m_PathFollow->ArriveOn();
		}
		else {
			m_PathFollow->SeekOn();
		}
		
	}*/

	//m_rigidBody->setLinearVelocity(btVector3(1, 0, 1) * 2.f);


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

void Enemy_Bot::handleInput()
{
}

void Enemy_Bot::cargarContenido()
{

	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createAnimatedNode(Vec3<float>(0, 100, 0), Vec3<float>(0.05f, 0.05f, 0.05f), "", "../media/ArmyPilot.b3d");
	m_nodo.get()->setTexture("../media/body01.png", 1);
	m_nodo.get()->setTexture("../media/head01.png", 0);
	m_nodo.get()->setTexture("../media/m4tex.png", 2);

	animation.addAnimation("Default", 0, 0);
	animation.addAnimation("Run_Forwards", 1, 69);
	animation.addAnimation("Run_backwards", 70, 138);
	animation.addAnimation("Walk", 139, 183);
	animation.addAnimation("Jump", 184, 219);
	animation.addAnimation("Jump2", 184, 219);
	animation.addAnimation("Idle", 220, 472);
	animation.addAnimation("AimRunning", 473, 524);

	m_animState = quieto;

	radius = 1.2f;
	height = 7.3f;
	mass = 70.f;


	m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(5.f, 5.f, 5.f), mass, false, Vec3<float>(0,0,0), DISABLE_DEACTIVATION);

	/*btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Enemy;
	proxy->m_collisionFilterMask = col::enemyCollidesWith;*/
}

void Enemy_Bot::borrarContenido()
{
	PhysicsEngine::i().removeRigidBody(m_rigidBody);

	GraphicEngine::i().removeNode(m_nodo);
}

void Enemy_Bot::handleMessage(const Message & message)
{
}

bool Enemy_Bot::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}

void Enemy_Bot::setPosition(Vec3<float> pos)
{
	m_renderState.setPosition(pos);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
	m_nodo.get()->setPosition(pos);
}


void Enemy_Bot::updateMovement()
{
	if (siguiendo) {
		Vec2f direccion = m_PathFollow->Calculate();
		btVector3 vel = btVector3(direccion.x, 0, direccion.y);
		vel = vel * 20.f;

		m_rigidBody->setLinearVelocity(vel);
	}
	
}

void Enemy_Bot::createPathToPosition(Vec2f vec) {

	siguiendo = true;

	//Limpiamos el camino actual
	m_camino.clear();

	m_PathPlanner->CreatePathToPosition(vec, m_camino);

	m_PathFollow->SetPath(m_camino);

}

void Enemy_Bot::updateAnimation()
{
	switch (m_animState)
	{
	case quieto:
		if (animation.getActualAnimation() != "Idle") {
			m_nodo.get()->setAnimation(animation.getAnimationStart("Idle"), animation.getAnimationEnd("Idle"));
		}
		break;

	case andando:
		if (animation.getActualAnimation() != "Walk") {
			m_nodo.get()->setAnimation(animation.getAnimationStart("Walk"), animation.getAnimationEnd("Walk"));
		}
		break;

	case saltando:
		if (animation.getActualAnimation() != "Jump") {
			m_nodo.get()->setAnimation(animation.getAnimationStart("Jump"), animation.getAnimationEnd("Jump"));
		}
		break;
	case saltando2:
		if (animation.getActualAnimation() != "Jump2") {
			m_nodo.get()->setAnimation(animation.getAnimationStart("Jump2"), animation.getAnimationEnd("Jump2"));
		}
		break;

	}
}