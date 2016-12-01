#include "Pistola.h"
#include "../../Motor de Red/Cliente.h"
#include "../../Motor de Red/Estructuras.h"
#include "../EntityManager.h"

Pistola::Pistola() : Weapon()
{
	capacidadAmmo = 6;
	disparos = 0;
	recarga = milliseconds(1000);
	cadencia = milliseconds(350);
	numCargadores = numCargadoresPistola;
}


Pistola::~Pistola()
{
}

void Pistola::inicializar()
{
}

void Pistola::update(Time elapsedTime)
{
	if (equipada) {
		Vec3<float> player_pos = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();
		Vec3<float> player_rot = EntityManager::i().getEntity(PLAYER)->getRenderState()->getRotation();
		m_renderState.updatePositions(Vec3<float>(player_pos.getX(), player_pos.getY() + 6.5f, player_pos.getZ()));
		m_renderState.updateRotations(player_rot);

		if (estadoWeapon == DESCARGADA) {
			if (numCargadores > 0) {
				if (relojrecarga.getElapsedTime() < recarga) {
					printf("recargando\n");
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

void Pistola::handleInput()
{
}

void Pistola::cargarContenido()
{
	Vec3<float> player_pos = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();
	m_nodo = std::shared_ptr<SceneNode>(GraphicEngine::i().createAnimatedNode(Vec3<float>(player_pos.getX(), player_pos.getY()+6.5f, player_pos.getZ()), Vec3<float>(0.2f, 0.2f, 0.2f), "", "../media/arma/pistola.obj"));
	m_nodo->setVisible(false);
	m_nodo->setTexture("../media/ice0.jpg", 0);

}

void Pistola::borrarContenido()
{
}

void Pistola::handleMessage(const Message & message)
{

}

void Pistola::shoot() {

	if (disparos < capacidadAmmo) {


		if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {
			disparos++;
			//printf("DISPARANDO PISTOLA\n");
			btVector3 SIZE_OF_WORLD(1500, 1500, 1500);
			btVector3 FUERZA(10,10,10);

			btVector3 start(
				GraphicEngine::i().getActiveCamera()->getPosition().getX(),
				GraphicEngine::i().getActiveCamera()->getPosition().getY(),
				GraphicEngine::i().getActiveCamera()->getPosition().getZ()); // posicion de la camara

			Vec3<float> target = GraphicEngine::i().getActiveCamera()->getTarget();
			Vec3<float> direccion = target - GraphicEngine::i().getActiveCamera()->getPosition();
			direccion.normalise();

			btVector3 direccion2(direccion.getX(), direccion.getY(), direccion.getZ());

			btVector3 end = start + (direccion2*SIZE_OF_WORLD);

			btCollisionWorld::ClosestRayResultCallback ray(start, end);

			PhysicsEngine::i().m_world->rayTest(start, end, ray);

			Vec3<float> posicionImpacto;


			if (ray.hasHit())//si ray ha golpeado algo entro
			{
			

				//Entity* ent = static_cast<Entity*>(ray.m_collisionObjects[nearestObject]->getUserPointer());

				// = btRigidBody::upcast(ray.m_collisionObject); // Miro que ha golpeado el rayo y compruebo si no es el player, si no lo es salto

																					 //calcularDistancia(start, end);

																					 ////////////////////////////////////////////////////////////
																					 //TODO:CAMBIAR ESTO POR EL RIGID BODY DEL PLAYER CONTROLLER
				Entity* ent = static_cast<Entity*>(ray.m_collisionObject->getUserPointer());
				if (ent != EntityManager::i().getEntity(PLAYER))
				{
					//Entity* myEnt = static_cast<Entity*>(hit->getUserPointer());
					if (ent->getClassName() == "Enemy") {
						Message msg(ent, "COLISION_BALA", NULL);
						MessageHandler::i().sendMessage(msg);
					}


					posicionImpacto = Vec3<float>(ray.m_hitPointWorld.x(), ray.m_hitPointWorld.y(), ray.m_hitPointWorld.z());

					if (ent->getClassName() == "PhysicsEntity") {
						btRigidBody::upcast(ray.m_collisionObject)->applyImpulse(direccion2*FUERZA, btVector3(posicionImpacto.getX(), posicionImpacto.getY(), posicionImpacto.getZ()));
						std::cout << ent->getName() << std::endl;
					}
				}

				
			}

			//creamos la bala cuando disparamos, le pasamos la posicion de inicio, el vector direccion por el cual se movera y la posicion final
			//TODO: mas adelante la posicion inicial no sera la posicion de la camara sino que sera la posicion del arma.

			//disparamos la bala en nuestro cliente
			Vec3<float> posDisparo = GraphicEngine::i().getActiveCamera()->getPosition();
			posDisparo += Vec3<float>(Randf(-1.f, 1.f), Randf(-1.f, 1.f), Randf(-1.f, 1.f)) / 10.f;

			//	  if (arma != LANZACOHETES)
			GunBullet* bala = new GunBullet(posDisparo, direccion, posicionImpacto, GraphicEngine::i().getActiveCamera()->getRotation());
			//	else {
			//		RocketBullet* bala = new RocketBullet(posDisparo, direccion, posicionImpacto, GraphicEngine::i().getActiveCamera()->getRotation());
			//	  }


			if (Cliente::i().isConected()) {
				//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
				Cliente::i().dispararBala(posDisparo, direccion, posicionImpacto, GraphicEngine::i().getActiveCamera()->getRotation());
			}
			//}

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