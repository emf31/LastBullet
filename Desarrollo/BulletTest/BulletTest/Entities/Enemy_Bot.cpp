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


	p_controller->updateAction(PhysicsEngine::i().m_world, elapsedTime.asSeconds());


	m_renderState.updatePositions(Vec3<float>(
		p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().y() - (height / 2) - p_controller->getStepHeight() / 2,
		p_controller->getGhostObject()->getWorldTransform().getOrigin().z()));


	float angle = std::atan2(m_vHeading.x, m_vHeading.y);


	m_renderState.updateRotations(Vec3<float>(0, RadToDeg(angle), 0));

	
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

	m_animState = andando;

	radius = 1.2f;
	height = 7.3f;
	mass = 70.f;


	//m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(5.f, 5.f, 5.f), mass, false, Vec3<float>(0,0,0), DISABLE_DEACTIVATION);

	/*btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Enemy;
	proxy->m_collisionFilterMask = col::enemyCollidesWith;*/

	p_controller = PhysicsEngine::i().createCapsuleKinematicCharacter(this, radius, height, mass);

	p_controller->m_acceleration_walk = 4.3f;
	p_controller->m_deceleration_walk = 6.5f;
	p_controller->m_maxSpeed_walk = 2.f;
}

void Enemy_Bot::borrarContenido()
{
	delete m_PathFollow;
	delete m_PathPlanner;

	PhysicsEngine::i().removeKinematic(p_controller);

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
	p_controller->warp(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_nodo->setPosition(pos);
}


void Enemy_Bot::updateMovement()
{
	Vec2f direccion = m_PathFollow->Calculate();

	if (!direccion.Zero()) {
		m_vHeading = direccion;
	}
	

	btVector3 vel = btVector3(direccion.x, 0, direccion.y);

	p_controller->setWalkDirection(vel);
	
}

void Enemy_Bot::createPathToPosition(Vec2f vec) {


	//Camino actual a seguir
	std::list<Vec2f> m_camino;

	m_PathPlanner->CreatePathToPosition(vec, m_camino);

	m_PathFollow->SetPath(m_camino);

	m_PathFollow->FollowOn();

}

void Enemy_Bot::createPathToItem(ExtraInfo tipo)
{

	//Camino actual a seguir
	std::list<Vec2f> m_camino;

	m_PathPlanner->CreatePathToItem(tipo, m_camino);

	m_PathFollow->SetPath(m_camino);

	m_PathFollow->FollowOn();
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