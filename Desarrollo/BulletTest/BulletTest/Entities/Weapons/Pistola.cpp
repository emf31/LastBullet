#include "Pistola.h"
#include "../../Motor de Red/Cliente.h"
#include "../../Motor de Red/Estructuras.h"

Pistola::Pistola() : Weapon()
{
	capacidadAmmo = 6;
	disparos = 0;
	recarga = milliseconds(1000);
	cadencia = milliseconds(350);
}


Pistola::~Pistola()
{
}

void Pistola::inicializar()
{
}

void Pistola::update(Time elapsedTime)
{
	if (estadoWeapon == DESCARGADA) {
		if (relojrecarga.getElapsedTime() < recarga) {
			printf("recargando\n");
		}
		else {
			estadoWeapon = CARGADA;
			disparos = 0;
		}
	}

}

void Pistola::handleInput()
{
}

void Pistola::cargarContenido()
{


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
			printf("DISPARANDO PISTOLA\n");
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

			Vec3<float> posicionImpacto(1500, 1500, 1500);


			if (ray.hasHit())//si ray ha golpeado algo entro
			{


				const btRigidBody* hit = btRigidBody::upcast(ray.m_collisionObject); // Miro que ha golpeado el rayo y compruebo si no es el player, si no lo es salto

																					 //calcularDistancia(start, end);

																					 ////////////////////////////////////////////////////////////
																					 //TODO:CAMBIAR ESTO POR EL RIGID BODY DEL PLAYER CONTROLLER
																					 //if (hit != m_rigidBody)
																					 //{

				Entity* myEnt = static_cast<Entity*>(hit->getUserPointer());
				if (myEnt->getClassName() == "Enemy") {
					Message msg(myEnt, "COLISION_BALA", NULL);
					MessageHandler::i().sendMessage(msg);
				}

				posicionImpacto = Vec3<float>(ray.m_hitPointWorld.at(0).x(), ray.m_hitPointWorld.at(0).y(), ray.m_hitPointWorld.at(0).z());

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


			if (m_guid != RakNet::UNASSIGNED_RAKNET_GUID) {
				//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
				Cliente::i().dispararBala(posDisparo, direccion, posicionImpacto, GraphicEngine::i().getActiveCamera()->getRotation());
			}
			//}

			relojCadencia.restart();
		}

	}

	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;
	}

}