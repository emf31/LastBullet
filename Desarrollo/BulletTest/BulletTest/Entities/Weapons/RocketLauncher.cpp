#include <Weapons/RocketLauncher.h>
#include <Cliente.h>
#include <Estructuras.h>

RocketLauncher::RocketLauncher() : Weapon()
{
	capacidadAmmo = 5;
	disparos = 0;
	recarga = milliseconds(1000);
	cadencia = milliseconds(400);
	numCargadores = numCargadoresRocket;
	SIZE_OF_WORLD = btVector3(1500, 1500, 1500);
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
		/*Vec3<float> player_pos = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();
		Vec3<float> player_rot = EntityManager::i().getEntity(PLAYER)->getRenderState()->getRotation();
		m_renderState.updatePositions(Vec3<float>(player_pos.getX(), player_pos.getY() + 7.3f, player_pos.getZ()));
		m_renderState.updateRotations(player_rot);*/

		if (estadoWeapon == DESCARGADA) {
			if (numCargadores > 0) {
				if (relojrecarga.getElapsedTime() >= recarga) {
					estadoWeapon = CARGADA;
					disparos = 0;
					numCargadores--;
				}

			}
			else if (disparosRestantes>0) {
				if (relojrecarga.getElapsedTime() >= recarga) {
					estadoWeapon = CARGADA;
					disparos = capacidadAmmo - disparosRestantes;
					disparosRestantes = 0;
				}

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
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(player_pos.getX(), player_pos.getY(), player_pos.getZ()), Vec3<float>(1.f, 1.f, 1.f), "", "../media/arma/rocket.obj");
	m_nodo->setVisible(false);

	GraphicEngine::i().getActiveCamera()->addChild(m_nodo);

}

void RocketLauncher::borrarContenido()
{
}

void RocketLauncher::handleMessage(const Message & message)
{

}

bool RocketLauncher::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}

void RocketLauncher::shoot() {

	
	if (disparos < capacidadAmmo && estadoWeapon == CARGADA) {

		GraphicEngine::i().getActiveCamera()->cameraRecoil();

		if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {
			//aumentamos en uno el numero de disparos, para reducir la municion
			disparos++;

			// posicion de la camara
			btVector3 start = bt(GraphicEngine::i().getActiveCamera()->getPosition());
			//start.setY(start.getY() + 3.f);

			//añadimos un poco de desvio en el arma
			start += btVector3(Randf(-1.f, 1.f), Randf(-1.f, 1.f), Randf(-1.f, 1.f)) / 10.f;

			btVector3 target = bt(GraphicEngine::i().getActiveCamera()->getTarget());
			btVector3 direccion = target - bt(GraphicEngine::i().getActiveCamera()->getPosition());
			direccion.normalize();

			RocketBullet* bala = new RocketBullet(cons(start), cons(direccion), GraphicEngine::i().getActiveCamera()->getRotation());
			bala->cargarContenido();

			/*if (Cliente::i().isConected()) {

				TBala tBala;
				tBala.position = cons(start);
				tBala.direction = cons(direccion);
				tBala.rotation = GraphicEngine::i().getActiveCamera()->getRotation();
				tBala.guid = EntityManager::i().getEntity(PLAYER)->getGuid();

				//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
				Cliente::i().dispatchMessage(tBala, DISPARAR_ROCKET);
			}*/

			relojCadencia.restart();
		}

	}

	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
			relojrecarga.restart();
		
		estadoWeapon = DESCARGADA;
	}
}