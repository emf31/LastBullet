#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include "KinematicCharacterController.h"
#include "Granada.h"
#include "Weapons/Weapon.h"
#include "../Motor/AnimatedSceneNode.h"
#include "../Motor/Animation.h"
#include <vector>
#include "../Otros/Lista.h"

class Player : public Entity
{
public:
	Player(const std::string& name, std::vector<Vec3<float>> spawnPoints, RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	~Player();

	void setPosition(Vec3<float> &pos);
	void searchSpawnPoint();

	// Heredado v�a Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message& message) override;
	virtual std::string getClassName() { return "Player"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;


	void run();
	void setWeapon(int weapon);

	void jump();

	void shoot();
	void shootGranada();

	void move_up();
	void move_down();
	void move_right();
	void move_left();

	void UpWeapon();
	void DownWeapon();

	void impulsar(Vec3<float> force);



	Vec3<float> getVelocity() { return Vec3<float>(p_controller->getLinearVelocity().x(), p_controller->getLinearVelocity().y(), p_controller->getLinearVelocity().z()); }


	std::string getCurrentWeapon() {
		return listaWeapons->valorActual()->getClassName();
	};

	int getAmmoActual() { return listaWeapons->valorActual()->getAmmo(); }
	int getCargadorActual() { return listaWeapons->valorActual()->getCargadorWeapon(); }
	int getAmmoTotal() { return listaWeapons->valorActual()->getAmmoTotal(); }


	btPairCachingGhostObject* getGhostObject() {
		return p_controller->getGhostObject();
	}

	void resetAll();
	KinematicCharacterController* p_controller;

private:

	Animation* animation;

	//EQUIPO
	Granada* granada;

	//LISTA DE ARMAS
	Lista* listaWeapons;
	Asalto* asalto;
	Pistola* pistola;
	RocketLauncher* rocket;



	//ESTADOS DEL PLAYER
	enum PlayerState { quieto,andando,corriendo,saltando,saltando2 } m_playerState;


	bool tieneAsalto = false;
	bool tieneRocketLauncher = false;
	bool tienePistola = false;

	bool isShooting=false;

	bool isJumping;
	bool isMoving;
	bool isRunning=false;
	bool isReloading = false;

	
	//Player controller
	btCollisionShape* m_pCollisionShape;
	btPairCachingGhostObject* m_pGhostObject;

	float radius;
	float height;
	float mass;

	Vec3<float> speedFinal;

	std::vector<Vec3<float>> m_spawns;
};

