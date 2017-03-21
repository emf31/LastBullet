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
	//if (cont == 100) {
		Camera* cam = GraphicEngine::i().getActiveCamera();
		Vec3<float> posCamera = cam->getPosition();
		/*Vec3<float> vecDir = cam->getTarget();

		Vec3<float> direccion = vecDir - posCamera;
		//Vec3<float> newPos = vecDir * 2.f;
		//p->setPosition(newPos);
		//m_nodo->setOrientation(vecDir);
		direccion.normalise();

		posCamera += direccion * 1.4f;*/

		/*Vec3<float> pos = m_ent->getRenderState()->getPosition();
		pos.addY(3.f);
		m_renderState.updatePositions(pos);*/


		//m_renderState.updateRotations(cam->getRotation() );
		//m_nodo->setPosition(pos);
		//m_nodo->getPosition().display();
		//m_nodo->updatePosition(newPos);
		//m_nodo->setVisible(true);

	//	cont = 0;
	//}
	//else {
	//	cont++;
	//}
	

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
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(player_pos.getX(), player_pos.getY(), player_pos.getZ()), Vec3<float>(0.1f, 0.1f, 0.1f), "", "assets/pistolaTexturizada.obj");
	
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



void Pistola::shoot(const Vec3<float>& target) {

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
							TImpactoBala impacto;
							impacto.damage = damage;
							impacto.guid = ent->getGuid();

							Message msg(ent, "COLISION_BALA", &impacto);
							MessageHandler::i().sendMessageNow(msg);
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

		GunBullet* bala = new GunBullet(cons(start), cons(direccion), cons(posicionImpacto), m_ent->getNode()->getRotation());
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

	

	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;
	}


}
