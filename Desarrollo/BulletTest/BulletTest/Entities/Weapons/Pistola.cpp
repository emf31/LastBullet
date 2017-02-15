#include "Pistola.h"
#include <Cliente.h>
#include <Estructuras.h>
#include "../EntityManager.h"

Pistola::Pistola() : Weapon()
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
		/*Vec3<float> player_pos = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();
		Vec3<float> player_rot = EntityManager::i().getEntity(PLAYER)->getRenderState()->getRotation();
		m_renderState.updatePositions(Vec3<float>(player_pos.getX(), player_pos.getY() + 6.5f, player_pos.getZ()));
		m_renderState.updateRotations(player_rot);*/

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
	Vec3<float> player_pos = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();
	m_nodo = GraphicEngine::i().createAnimatedNode(Vec3<float>(player_pos.getX(), player_pos.getY()+6.5, player_pos.getZ()), Vec3<float>(0.1f, 0.1f, 0.1f), "", "../media/arma/pistola.obj");
	m_nodo->setVisible(false);
	//m_nodo->setTexture("../media/ice0.jpg", 0);
	//m_nodo->setTexture("../media/ice0.jpg", 1);
	//m_nodo->setTexture("../media/ice0.jpg", 2);
	GraphicEngine::i().getActiveCamera()->addChild(m_nodo);

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


float Pistola::shootBot(Vec3<float> posOwner, Vec3<float> posTarget) {

	float danyo=0;

	if (disparos < capacidadAmmo && estadoWeapon == CARGADA) {

		if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {

			disparos++;


			btVector3 start = bt(posOwner);

			btVector3 target = bt(posTarget);

			btVector3 direccion = target - start;
			direccion.normalize();

			btVector3 end = start + (direccion*SIZE_OF_WORLD);


			btKinematicClosestShapeResultCallback ray(start, end);

			PhysicsEngine::i().m_world->rayTest(start, end, ray);

			btVector3 posicionImpacto;


			if (ray.hasHit())//si ray ha golpeado algo entro
			{

				if (ray.parte != bodyPart::Body::EXTERNA) {
					Entity* ent = static_cast<Entity*>(ray.m_collisionObject->getUserPointer());



						if (ent->getClassName() == "Enemy" || ent->getClassName() == "Enemy_Bot" || ent->getClassName() == "Player") {

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



			GunBullet* bala = new GunBullet(cons(start), cons(direccion), cons(posicionImpacto), GraphicEngine::i().getActiveCamera()->getRotation());
			bala->cargarContenido();

			relojCadencia.restart();

		}

	}


	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;
	}

	return danyo;

}


void Pistola::shoot() {

	
	if (disparos < capacidadAmmo && estadoWeapon == CARGADA) {

		GraphicEngine::i().getActiveCamera()->cameraRecoil();

		if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {
			//aumentamos en uno el numero de disparos, para reducir la municion
			disparos++;

			// posicion de la camara
			btVector3 start = bt(GraphicEngine::i().getActiveCamera()->getPosition());

			//añadimos un poco de desvio en el arma
			start += btVector3(Randf(-1.f, 1.f), Randf(-1.f, 1.f), Randf(-1.f, 1.f)) / 10.f;

			btVector3 target = bt(GraphicEngine::i().getActiveCamera()->getTarget());
			btVector3 direccion = target - bt(GraphicEngine::i().getActiveCamera()->getPosition());
			direccion.normalize();

			btVector3 end = start + (direccion*SIZE_OF_WORLD);

			btKinematicClosestShapeResultCallback ray(start, end);

			PhysicsEngine::i().m_world->rayTest(start, end, ray);

			btVector3 posicionImpacto;


			if (ray.hasHit())//si ray ha golpeado algo entro
			{
					if (ray.parte != bodyPart::Body::EXTERNA) {
						Entity* ent = static_cast<Entity*>(ray.m_collisionObject->getUserPointer());
						if (ent != EntityManager::i().getEntity(PLAYER))
						{
							if (ent->getClassName() == "Enemy" || ent->getClassName() == "Enemy_Bot") {
								Message msg(ent, "COLISION_BALA", &damage);
								MessageHandler::i().sendMessage(msg);
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

			GunBullet* bala = new GunBullet(cons(start), cons(direccion), cons(posicionImpacto), GraphicEngine::i().getActiveCamera()->getRotation());
			bala->cargarContenido();

			if (Cliente::i().isConected()) {
				TBala bala;
				bala.position = cons(start);
				bala.direction = cons(direccion);
				bala.finalposition = cons(posicionImpacto);
				bala.rotation = GraphicEngine::i().getActiveCamera()->getRotation();
				bala.guid = EntityManager::i().getEntity(PLAYER)->getGuid();

				//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
				Cliente::i().dispatchMessage(bala, DISPARAR_BALA);
				//Cliente::i().dispararBala(cons(start), cons(direccion), cons(posicionImpacto), GraphicEngine::i().getActiveCamera()->getRotation());
			}

			relojCadencia.restart();
		}

	}

	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;
	}

}
/*
double Pistola::getDesirability(double dist) {

	fm.Fuzzify("DistToTarget", dist);
	fm.Fuzzify("AmmoStatus", capacidadAmmo*numCargadores + disparosRestantes);

	double desirability = fm.DeFuzzify("Desirability", FuzzyModule::max_av);

	std::cout << "Deseabilidad de la pistola: " << desirability << "\n";

	return desirability;
}

void Pistola::CalcularRules() {
	fm.AddRule(FzAND(Target_Close, Ammo_Low), Undesirable);
	fm.AddRule(FzAND(Target_Close, Ammo_Okay), Undesirable);
	fm.AddRule(FzAND(Target_Close, Ammo_Loads), Undesirable);

	fm.AddRule(FzAND(Target_Medium, Ammo_Low), Undesirable);
	fm.AddRule(FzAND(Target_Medium, Ammo_Okay), Undesirable);
	fm.AddRule(FzAND(Target_Medium, Ammo_Loads), Undesirable);

	fm.AddRule(FzAND(Target_Far, Ammo_Low), Undesirable);
	fm.AddRule(FzAND(Target_Far, Ammo_Okay), Undesirable);
	fm.AddRule(FzAND(Target_Far, Ammo_Loads), Undesirable);

}*/