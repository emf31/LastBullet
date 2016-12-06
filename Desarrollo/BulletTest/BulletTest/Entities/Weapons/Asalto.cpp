#include "Asalto.h"
#include "../../Motor de Red/Cliente.h"
#include "../../Motor de Red/Estructuras.h"

Asalto::Asalto() : Weapon()
{
	

}


Asalto::~Asalto()
{

}

void Asalto::inicializar()
{
	damage = 15;
	capacidadAmmo = 30;
	disparos = 0;
	cadencia = milliseconds(50);
	recarga = milliseconds(1000);
	numCargadores = numCargadoresAsalto;
}

void Asalto::update(Time elapsedTime)
{
	if (equipada) {
		Vec3<float> player_pos = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();
		Vec3<float> player_rot = GraphicEngine::i().getActiveCamera()->getRotation();
		m_renderState.updatePositions(Vec3<float>(player_pos.getX(), player_pos.getY() + 5.5f, player_pos.getZ()));
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

void Asalto::handleInput()
{
}

void Asalto::cargarContenido()
{
	Vec3<float> player_pos = EntityManager::i().getEntity(PLAYER)->getRenderState()->getPosition();
	m_nodo = GraphicEngine::i().createAnimatedNode(Vec3<float>(player_pos.getX(), player_pos.getY(), player_pos.getZ()), Vec3<float>(0.003f, 0.003f, 0.003f), "", "../media/arma/asalto.obj");
	m_nodo->setVisible(false);
	m_nodo->setTexture("../media/ice0.jpg", 0);
	//m_nodo.get()->setTexture("../media/arma/v_hands_gloves_sf2 d.tga", 1);

}

void Asalto::borrarContenido()
{
}

void Asalto::handleMessage(const Message & message)
{

}

void Asalto::shoot()
{

	if (disparos < capacidadAmmo) {


		if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds()) {
			disparos++;

			//printf("DISPARANDO ASALTO\n");
			btVector3 SIZE_OF_WORLD(1500, 1500, 1500);
			btVector3 FUERZA(60.f, 60.f, 60.f);

			btVector3 start(
				GraphicEngine::i().getActiveCamera()->getPosition().getX(),
				GraphicEngine::i().getActiveCamera()->getPosition().getY(),
				GraphicEngine::i().getActiveCamera()->getPosition().getZ()); // posicion de la camara

			//añadimos un poco de desvio en el arma
			start += btVector3(Randf(-1.f, 1.f), Randf(-1.f, 1.f), Randf(-1.f, 1.f)) / 10.f;

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
						btRigidBody::upcast(ray.m_collisionObject)->activate(true);
						btRigidBody::upcast(ray.m_collisionObject)->applyImpulse(direccion2*FUERZA, btVector3(posicionImpacto.getX(), posicionImpacto.getY(), posicionImpacto.getZ()));
					}
				}
			}

			//creamos la bala cuando disparamos, le pasamos la posicion de inicio, el vector direccion por el cual se movera y la posicion final
			//TODO: mas adelante la posicion inicial no sera la posicion de la camara sino que sera la posicion del arma.

			//disparamos la bala en nuestro cliente
			Vec3<float> posDisparo = GraphicEngine::i().getActiveCamera()->getPosition();
			posDisparo += Vec3<float>(Randf(-1.f, 1.f), Randf(-1.f, 1.f), Randf(-1.f, 1.f)) / 10.f;


			GunBullet* bala = new GunBullet(posDisparo, direccion, posicionImpacto, GraphicEngine::i().getActiveCamera()->getRotation());


			if (Cliente::i().isConected()) {
				//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
				Cliente::i().dispararBala(posDisparo, direccion, posicionImpacto, GraphicEngine::i().getActiveCamera()->getRotation());
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