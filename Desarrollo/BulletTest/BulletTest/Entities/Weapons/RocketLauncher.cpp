#include <Weapons/RocketLauncher.h>
#include <Estructuras.h>
#include <NetworkManager.h>
#include <Player.h>


RocketLauncher::RocketLauncher(Character* ent) : Weapon(ent)
{
	
}



RocketLauncher::~RocketLauncher()
{
}


void RocketLauncher::inicializar()
{
	capacidadAmmo = 5;
	disparos = 0;
	recarga = milliseconds(1000);
	cadencia = milliseconds(400);
	numCargadores = numCargadoresRocket;
	SIZE_OF_WORLD = btVector3(1500, 1500, 1500);
}


void RocketLauncher::update(Time elapsedTime)
{
	if (equipada) {

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
	Vec3<float> player_pos = m_ent->getRenderState()->getPosition();
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(player_pos.getX(), player_pos.getY(), player_pos.getZ()), Vec3<float>(1.f, 1.f, 1.f), "", "../media/Weapons/rocket.obj");
	m_nodo->setVisible(false);

	

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



Entity* RocketLauncher::shoot(const Vec3<float>& target) {
	
		if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {

			

			//aumentamos en uno el numero de disparos, para reducir la municion
			disparos++;

			// posicion de la camara
			btVector3 start = bt(m_ent->getRenderState()->getPosition());
			start += btVector3(0.f, 3.f, 0.f);

			//añadimos un poco de desvio en el arma
			//start += btVector3(Randf(-1.f, 1.f), Randf(-1.f, 1.f), Randf(-1.f, 1.f)) / 10.f;


			btVector3 tg = bt(target);
			
			btVector3 direccion = tg - start;
			direccion.normalize();

			start += direccion * 3.f;

			RocketBullet* bala = new RocketBullet(m_ent, cons(start), cons(direccion), m_ent->getNode()->getRotation());
			bala->cargarContenido();

		
			TBala tBala;
			tBala.position = cons(start);
			tBala.direction = cons(direccion);
			tBala.rotation = m_ent->getNode()->getRotation();
			tBala.guid = m_ent->getGuid();

			//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
			NetworkManager::i().dispatchMessage(tBala, DISPARAR_ROCKET);

			relojCadencia.restart();
		}

	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
			relojrecarga.restart();
		
		estadoWeapon = DESCARGADA;
	}


	return nullptr;
	
	
}
