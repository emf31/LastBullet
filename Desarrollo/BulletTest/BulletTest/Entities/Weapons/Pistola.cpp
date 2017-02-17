#include "Pistola.h"
#include <Estructuras.h>
#include "../EntityManager.h"
#include <NetworkManager.h>
#include <Player.h>

Pistola::Pistola(Character* ent) : Weapon(), m_ent(ent)
{
	
}


Pistola::~Pistola()
{
}

void Pistola::inicializar()
{
	damage = 35;
	capacidadAmmo = 6;
	disparos = 0;
	recarga = milliseconds(1000);
	cadencia = milliseconds(250);
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
	m_nodo = GraphicEngine::i().createAnimatedNode(Vec3<float>(player_pos.getX(), player_pos.getY(), player_pos.getZ()), Vec3<float>(0.1f, 0.1f, 0.1f), "", "../media/arma/pistola.obj");
	m_nodo->setVisible(false);

	

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



void Pistola::shoot(const Vec3<float>& target) {

	float danyo = 0;
	
	if (disparos < capacidadAmmo && estadoWeapon == CARGADA) {

		//GraphicEngine::i().getActiveCamera()->cameraRecoil();

		if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {
			//aumentamos en uno el numero de disparos, para reducir la municion
			disparos++;

			// posicion de la camara
			btVector3 start = bt(m_ent->getRenderState()->getPosition());
			start += btVector3(0.f, 8.f, 0.f);

			//añadimos un poco de desvio en el arma
			start += btVector3(Randf(-1.f, 1.f), Randf(-1.f, 1.f), Randf(-1.f, 1.f)) / 10.f;

			btVector3 tg = bt(target);
			btVector3 direccion = tg - start;
			direccion.normalize();

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
							if (ent->getClassName() == "Player" || ent->getClassName() == "Enemy" || ent->getClassName() == "Enemy_Bot") {
								Message msg(ent, "COLISION_BALA", &damage);
								MessageHandler::i().sendMessage(msg);
								danyo = damage;
							}
							//Para mover objetos del mapa
							posicionImpacto = ray.m_hitPointWorld;

							if (ent->getClassName() == "PhysicsEntity") {
								btRigidBody::upcast(ray.m_collisionObject)->activate(true);
								btRigidBody::upcast(ray.m_collisionObject)->applyImpulse(direccion*FUERZA, posicionImpacto);
							}
						}
					}

			}

			GunBullet* bala = new GunBullet(cons(start), cons(direccion), cons(posicionImpacto), m_nodo->getRotation());
			bala->cargarContenido();

			TBala p_bala;
			p_bala.position = cons(start);
			p_bala.direction = cons(direccion);
			p_bala.finalposition = cons(posicionImpacto);
			p_bala.rotation = m_nodo->getRotation();
			p_bala.guid = m_ent->getGuid();

			//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
			NetworkManager::i().dispatchMessage(p_bala, DISPARAR_BALA);
			

			relojCadencia.restart();
		}

	}

	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;
	}


}
