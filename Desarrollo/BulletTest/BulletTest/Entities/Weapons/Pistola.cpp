#include "Pistola.h"
#include <Estructuras.h>
#include "../EntityManager.h"
#include <NetworkManager.h>
#include <Player.h>
#include <Camera.h>

Pistola::Pistola(Character* ent) : Weapon(ent)
{
	
}


Pistola::~Pistola()
{
}

void Pistola::inicializar()
{
	damage = 20;
	capacidadAmmo = 12;
	disparos = 0;
	recarga = milliseconds(500);
	cadencia = milliseconds(180);
	numCargadores = numCargadoresPistola;
	SIZE_OF_WORLD = btVector3(1500, 1500, 1500);
	FUERZA = btVector3(10, 10, 10);
}



void Pistola::update(Time elapsedTime)
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
			else if(disparosRestantes>0){
				if (relojrecarga.getElapsedTime() >= recarga) {
					estadoWeapon = CARGADA;
					disparos = capacidadAmmo - disparosRestantes;
					disparosRestantes = 0;
				}
			}

		}
	}

}


void Pistola::handleInput()
{
}


void Pistola::cargarContenido()
{
	Vec3<float> player_pos = m_ent->getRenderState()->getPosition();
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(player_pos.getX(), player_pos.getY(), player_pos.getZ()), Vec3<float>(0.08f, 0.08f, 0.08f), "", "../media/Weapons/pistolaTexturizada.obj");
	
	m_nodo->setVisible(true);

	

}


void Pistola::borrarContenido()
{
}


void Pistola::handleMessage(const Message & message)
{

}

bool Pistola::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}



Character* Pistola::shoot(const Vec3<float>& target) {
	//si impacta con algun personaje devuelve true
	Character* hitted = nullptr;

	SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("shoot.mp3", "sounds"), m_ent->getRenderState()->getPosition(), Sound::type::sound);
	

	//if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {
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

		btVector3 end = start + (direccion*SIZE_OF_WORLD);

		btKinematicClosestShapeResultCallback ray(start, end);

		PhysicsEngine::i().m_world->rayTest(start, end, ray);

		btVector3 posicionImpacto;


		if (ray.hasHit())//si ray ha golpeado algo entro
		{
				if (ray.parte != bodyPart::Body::EXTERNA) {
					Entity* ent = static_cast<Entity*>(ray.m_collisionObject->getUserPointer());
					if (ent != m_ent)
					{
						if (ent->getClassName() == "Enemy" || ent->getClassName() == "Player" || ent->getClassName() == "Enemy_Bot") {
							
							hitted = static_cast<Character*>(ent);


							TImpactoBala* impacto = new TImpactoBala();
							impacto->damage = damage;
							impacto->guidImpactado = ent->getGuid();
							impacto->guidDisparado = m_ent->getGuid();

							Message msg(ent, "COLISION_BALA", impacto);
							MessageHandler::i().sendMessage(msg);

						}
						//Para mover objetos del mapa
						posicionImpacto = ray.m_hitPointWorld;
					}
				}

		}

		GunBullet* bala = new GunBullet(cons(bt(m_nodo->getPosition())), cons(direccion), cons(posicionImpacto), getBalaRotation(), GraphicEngine::i().getActiveCamera()->getVectorDirection());
		bala->cargarContenido();

		TBala p_bala;
		p_bala.position = cons(start);
		p_bala.direction = cons(direccion);
		p_bala.finalposition = cons(posicionImpacto);
		p_bala.rotation = m_nodo->getRotation();
		p_bala.orientation = GraphicEngine::i().getActiveCamera()->getVectorDirection();
		p_bala.guid = m_ent->getGuid();

		//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
		NetworkManager::i().dispatchMessage(p_bala, DISPARAR_BALA);
			

		relojCadencia.restart();
	//}

	

	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;
		SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("reloadPistola.mp3", "sounds"), Sound::type::sound);

	}


	return hitted;

}

void Pistola::recargar()
{
	Weapon::recargar();

}
