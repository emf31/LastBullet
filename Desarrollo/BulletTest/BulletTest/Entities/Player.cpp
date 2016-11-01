
#include "Player.h"
#include "../Motor de Red/Cliente.h"
#include "../Motor/PhysicsEngine.h"
#include "../Motor/GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include "../Handlers/MessageHandler.h"


Player::Player(const std::string& name, RakNet::RakNetGUID guid) : Entity(1, NULL, name, guid), m_speedFactor(30)	//El player siempre tendra ID 1
{
}


Player::~Player()
{
}




void Player::inicializar()
{
}

void Player::update(Time elapsedTime)
{
	Vec3<float> speedFinal;


	Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();

	Vec3<float> posicion = getRenderState()->getPosition();
	Vec3<float> speed = target - posicion;
	speedFinal = Vec3<float>(0, 0, 0);

	if (isMovingForward) {
		speedFinal.setX(speedFinal.getX() + speed.getX());
		speedFinal.setZ(speedFinal.getZ() + speed.getZ());
		moviendo = true;
	}
	if (isMovingBackward) {
		speedFinal.setX(speedFinal.getX() - speed.getX());
		speedFinal.setZ(speedFinal.getZ() - speed.getZ());
		moviendo = true;
	}
	if (isMovingLeft) {
		speedFinal.setX(speedFinal.getX() - speed.getZ());
		speedFinal.setZ(speedFinal.getZ() + speed.getX());
		moviendo = true;
	}
	if (isMovingRight) {
		speedFinal.setX(speedFinal.getX() + speed.getZ());
		speedFinal.setZ(speedFinal.getZ() - speed.getX());
		moviendo = true;
	}
	speedFinal.normalise();

	m_rigidBody->setLinearVelocity(btVector3(speedFinal.getX()*m_speedFactor, speedFinal.getY(), speedFinal.getZ()*m_speedFactor));


	if (isJumping && tiempoSalto.getElapsedTime().asSeconds() > 3) {
		m_rigidBody->setLinearVelocity(btVector3(0, 7, 0));
		tiempoSalto.restart();
	}

	// Set position
	btVector3 Point = m_rigidBody->getCenterOfMassPosition();
	m_renderState.updatePositions(Vec3<float>((f32)Point[0], (f32)Point[1], (f32)Point[2]));


		Cliente::i().enviarPos(this);
	

	// Set rotation
	vector3df Euler;
	const btQuaternion& TQuat = m_rigidBody->getOrientation();
	quaternion q(TQuat.getX(), TQuat.getY(), TQuat.getZ(), TQuat.getW());
	q.toEuler(Euler);
	Euler *= RADTODEG;

	m_renderState.updateRotations(Vec3<float>(Euler.X, Euler.Y, Euler.Z));

	/*Message msg1(this, "MOVE", NULL);

	MessageHandler::sendMessage(msg1);*/
}

void Player::handleInput()
{
	isMovingForward = MastEventReceiver::i().keyDown(KEY_KEY_W);
	isMovingBackward = MastEventReceiver::i().keyDown(KEY_KEY_S);
	isMovingLeft = MastEventReceiver::i().keyDown(KEY_KEY_A);
	isMovingRight = MastEventReceiver::i().keyDown(KEY_KEY_D);
}

void Player::cargarContenido()
{
	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 500, 0), Vec3<float>(100.f, 100.f, 100.f), "../media/earth.jpg");

	m_renderState.setPosition(Vec3<float>(0, 500, 0));

	//Creas el body(fisico) 
	m_rigidBody = PhysicsEngine::createBoxRigidBody(this, Vec3<float>(100.f, 100.f, 100.f), 1.0f, DISABLE_DEACTIVATION);

	//Creamos la camara FPS
	GraphicEngine::i().createCamera(Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	GraphicEngine::i().setCameraEntity(this);
}

void Player::borrarContenido()
{
	//No se si aqui habria que hacer delete al nodo porque igual se encarga irrlitch
	delete m_nodo;
}

void Player::handleMessage(const Message & message)
{
}

void Player::setPosition(Vec3<float> pos) {
	m_renderState.setPosition(pos);
	btTransform transform = m_rigidBody->getCenterOfMassTransform();
	transform.setOrigin(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_rigidBody->setCenterOfMassTransform(transform);
	m_nodo->setPosition(pos);

}

