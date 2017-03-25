#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include "KinematicCharacterController.h"
#include "Granada.h"
#include <Weapons\Weapon.h>
#include <AnimatedSceneNode.h>
#include <Animation.h>
#include <vector>

#include <Lista.h>
#include <LifeComponent.h>

#include "Weapons/Asalto.h"
#include "Weapons/Pistola.h"
#include "Weapons/RocketLauncher.h"
#include "Weapons/Sniper.h"



#include <Character.h>


class NetPlayer;


class Player : public Character
{
public:
	Player(const std::string& names, RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	~Player();


	// Heredado v�a Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message& message) override;
	virtual std::string getClassName() { return "Player"; }
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;
	virtual void setPosition(const Vec3<float> &pos) override;


	void setWeapon(int weapon);

	void jump();

	void shoot();
	void shootGranada();

	void move_up();
	void move_down();
	void move_right();
	void move_left();

	void bindWeapon();
	void UpWeapon();
	void DownWeapon();
	void reload();
	void apuntar();
	void restablecerMira();

	void impulsar(Vec3<float> force);


	Vec3<float> getVelocity() { return Vec3<float>(p_controller->getLinearVelocity().x(), p_controller->getLinearVelocity().y(), p_controller->getLinearVelocity().z()); }


	LifeComponent& getLifeComponent() { return life_component; }

	std::string getCurrentWeaponName() { return listaWeapons->valorActual()->getClassName(); };

	Weapon* getCurrentWeapon() { return listaWeapons->valorActual(); };

	int getAmmoActual() { return listaWeapons->valorActual()->getAmmo(); }

	int getCargadorActual() { return listaWeapons->valorActual()->getCapacidadCargador(); }
	int getAmmoTotal();



	btPairCachingGhostObject* getGhostObject() const{ return p_controller->getGhostObject(); }


	bool getApuntando() {
		return apuntando;
	}

	void resetAll();

	void updateRelojes();

	//shared ptr, we can pass by value
	std::shared_ptr<NetPlayer> m_network;

	KinematicCharacterController* p_controller;

	bool hit;
	bool sangre;
	Clock relojSangre, relojHit;

	virtual float getVida() override;
	virtual bool isDying() override;

	bool isShooting;


	void updateCurrentWeaponPosition() {
		listaWeapons->valorActual()->updatePositionAndRotation();
	}
	
private:
	

	Animation* animation;

	//EQUIPO
	Granada* granada;

	//LISTA DE ARMAS
	Lista* listaWeapons;

	Asalto* asalto;
	Pistola* pistola;
	RocketLauncher* rocket;
	Sniper* sniper;

	LifeComponent life_component;

	//ESTADOS DEL PLAYER
	enum PlayerState { quieto,andando,corriendo,saltando,saltando2 } m_playerState;


	bool tieneAsalto;
	bool tieneRocketLauncher;
	bool tienePistola;
	bool tieneSniper;

	bool apuntando=false;



	bool isJumping;
	bool isMoving;
	bool isRunning;
	bool isReloading;

	float radius;
	float height;
	float mass;

	//Current facing player vector
	Vec3<float> speedFinal;

	

	
};
