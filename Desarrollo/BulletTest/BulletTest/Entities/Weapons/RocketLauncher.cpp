#include "RocketLauncher.h"
#include "../../Motor de Red/Cliente.h"
#include "../../Motor de Red/Estructuras.h"

RocketLauncher::RocketLauncher() : Weapon()
{
	capacidadAmmo = 5;
	disparos = 0;
	recarga = milliseconds(1000);
	cadencia = milliseconds(400);
	numCargadores = numCargadoresRocket;

}


RocketLauncher::~RocketLauncher()
{
}

void RocketLauncher::inicializar()
{
}

void RocketLauncher::update(Time elapsedTime)
{
	if (equipada) {
		Vec3<float> player_pos = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();
		Vec3<float> player_rot = EntityManager::i().getEntity(PLAYER)->getRenderState()->getRotation();
		m_renderState.updatePositions(Vec3<float>(player_pos.getX(), player_pos.getY() + 7.3f, player_pos.getZ()));
		m_renderState.updateRotations(player_rot);

		if (estadoWeapon == DESCARGADA) {
			if (numCargadores > 0) {
				if (relojrecarga.getElapsedTime() < recarga) {
					//printf("recargando\n");
				}
				else {
					estadoWeapon = CARGADA;
					disparos = 0;
					numCargadores--;
				}
			}
			else {
				relojrecarga.restart();
			}

		}
	}

}

void RocketLauncher::handleInput()
{
}

void RocketLauncher::cargarContenido()
{
	Vec3<float> player_pos = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(player_pos.getX(), player_pos.getY(), player_pos.getZ()), Vec3<float>(2.2f, 2.2f, 2.2f), "", "../media/arma/rocket.obj");
	m_nodo->setVisible(false);
	m_nodo->setTexture("../media/ice0.jpg", 0);

}

void RocketLauncher::borrarContenido()
{
}

void RocketLauncher::handleMessage(const Message & message)
{

}

void RocketLauncher::shoot() {

	if (disparos < capacidadAmmo) {


	if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {
		disparos++;
		//printf("DISPARANDO ROCKETLAUNCHER\n");
		btVector3 SIZE_OF_WORLD(1500, 1500, 1500);

		btVector3 start(
			GraphicEngine::i().getActiveCamera()->getPosition().getX(),
			GraphicEngine::i().getActiveCamera()->getPosition().getY(),
			GraphicEngine::i().getActiveCamera()->getPosition().getZ()); // posicion de la camara

		Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
		Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
		direccion.normalise();

		btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

		btVector3 end = start + (direccion2*SIZE_OF_WORLD);

		btCollisionWorld::AllHitsRayResultCallback ray(start, end);

		PhysicsEngine::i().m_world->rayTest(start, end, ray);

		//disparamos la bala en nuestro cliente
		Vec3<float> posDisparo = GraphicEngine::i().getActiveCamera()->getPosition();
		posDisparo.addY(3.f);	//esto es para no dispararlo desde el suelo y que no detecte colision con el suelo
		posDisparo += Vec3<float>(Randf(-1.f, 1.f), Randf(-1.f, 1.f), Randf(-1.f, 1.f)) / 10.f;


		RocketBullet* bala = new RocketBullet(posDisparo, direccion, GraphicEngine::i().getActiveCamera()->getRotation());

		if (Cliente::i().isConected()) {
			//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
			Cliente::i().dispararRrocket(posDisparo, direccion, GraphicEngine::i().getActiveCamera()->getRotation());
		}

		relojCadencia.restart();
	}

	}

	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
		if (numCargadores > 0) {
			relojrecarga.restart();
		}
		estadoWeapon = DESCARGADA;
	}
}