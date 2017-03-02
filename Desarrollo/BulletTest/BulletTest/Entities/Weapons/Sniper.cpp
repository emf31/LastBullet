#include "Sniper.h"
#include <Estructuras.h>
#include <Util.h>
#include <NetworkManager.h>


Sniper::Sniper(Character* ent) : Weapon(ent)
{


}


Sniper::~Sniper()
{

}

void Sniper::inicializar()
{
		damage = 100;
		capacidadAmmo = 5;
		disparos = 0;
		cadencia = milliseconds(2000);
		recarga = milliseconds(1000);
		numCargadores = numCargadoresSniper;
		SIZE_OF_WORLD = btVector3(1500, 1500, 1500);
		FUERZA = btVector3(300.f, 300.f, 300.f);
	
}

void Sniper::update(Time elapsedTime)
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

void Sniper::handleInput()
{
}

void Sniper::cargarContenido()
{

	Vec3<float> player_pos = m_ent->getRenderState()->getPosition();
	m_nodo = GraphicEngine::i().createAnimatedNode(Vec3<float>(player_pos.getX(), player_pos.getY(), player_pos.getZ()), Vec3<float>(0.1f, 0.1f, 0.1f), "", "../media/arma/Sniper3.obj");
	m_nodo->setVisible(false);


}

void Sniper::borrarContenido()
{
}

void Sniper::handleMessage(const Message & message)
{

}

bool Sniper::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}


void Sniper::shoot(const Vec3<float>& target)
{

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
							TImpactoBala impacto;
							impacto.damage = damage;
							impacto.guid = m_ent->getGuid();

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

			GunBullet* bala = new GunBullet(cons(start), cons(direccion), cons(posicionImpacto), getBalaRotation());
			bala->cargarContenido();

			TBala t_bala;
			t_bala.position = cons(start);
			t_bala.direction = cons(direccion);
			t_bala.finalposition = cons(posicionImpacto);
			t_bala.rotation = m_nodo->getRotation();
			t_bala.guid = m_ent->getGuid();

			//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
			NetworkManager::i().dispatchMessage(t_bala, DISPARAR_BALA);


			relojCadencia.restart();


	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;
	}

}