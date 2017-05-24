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
		cadencia = milliseconds(1500);
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
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(player_pos.getX(), player_pos.getY(), player_pos.getZ()), Vec3<float>(0.1f, 0.1f, 0.1f), "", "../media/Weapons/sniperFinalv2.obj");
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


Character* Sniper::shoot(const Vec3<float>& target)
{
	//si impacta con algun personaje devuelve true
	Character* hitted = nullptr;

	SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("shootSniper.mp3", "sounds"), m_ent->getRenderState()->getPosition(), Sound::type::sound);

	SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("reloadRifle.mp3", "sounds"), Sound::type::sound);

	//aumentamos en uno el numero de disparos, para reducir la municion
	disparos++;

	// posicion de la camara
	btVector3 start = bt(m_ent->getRenderState()->getPosition());
	start += btVector3(0.f, 3.f, 0.f);

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

	TBala t_bala;
	t_bala.position = m_nodo->getPosition();
	t_bala.direction = cons(direccion);
	t_bala.finalposition = cons(posicionImpacto);
	t_bala.rotation = getBalaRotation();
	t_bala.orientation = GraphicEngine::i().getActiveCamera()->getVectorDirection();
	t_bala.guid = m_ent->getGuid();


	//enviamos el disparo de la bala al servidor para que el resto de clientes puedan dibujarla
	NetworkManager::i().dispatchMessage(t_bala, DISPARAR_BALA);


	relojCadencia.restart();


	if (disparos == capacidadAmmo && estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;
		SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("reloadRifle.mp3", "sounds"), Sound::type::sound);

	}

	return hitted;

}

void Sniper::recargar()
{
	Weapon::recargar();

}
