#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include "KinematicCharacterController.h"
//#include <BulletDynamics\Character\btKinematicCharacterController.h>
#include "Granada.h"
#include "Weapons/Weapon.h"
#include "../Motor/AnimatedSceneNode.h"
#include "../Motor/Animation.h"
#include <vector>
#include "../Lista.h"

class Player : public Entity
{
public:
	Player(const std::string& name, RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	~Player();

	void setPosition(Vec3<float> pos);

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message& message) override;
	virtual std::string getClassName() { return "Player"; }

	void run();
	void setWeapon(int weapon);

	void jump();

	void shoot();
	void shootGranada();

	void move_up();
	void move_down();
	void move_right();
	void move_left();

	void updateAnimation();
	void updateState();

	void UpWeapon();
	void DownWeapon();


	void sumarVida() { m_vida++; printf("ME HE CURADO\n"); }

	Vec3<float> getVelocity() { return Vec3<float>(p_controller->getLinearVelocity().x(), p_controller->getLinearVelocity().y(), p_controller->getLinearVelocity().z()); }


	std::string getCurrentWeapon() {
		return listaWeapons->valorActual()->getClassName();
	};

	int getAmmoActual() { return listaWeapons->valorActual()->getAmmo(); }
	int getCargadorActual() { return listaWeapons->valorActual()->getCargadorWeapon(); }
private:
	float m_vida;

	Animation* animation;
	Granada* granada;

	Lista* listaWeapons;
	Asalto* asalto;
	Pistola* pistola;
	RocketLauncher* rocket;

	enum PlayerState { quieto,andando,corriendo,saltando,saltando2 } m_playerState;

	//esta no deberia estar aqui acordarse de borrarla

	bool tieneAsalto = false;
	bool tieneRocketLauncher = false;
	bool tienePistola = false;

	bool isShooting=false;

	bool isJumping;
	bool isMoving;
	bool isRunning=false;
	bool isReloading = false;

	Vec3<float> speedFinal;

	//Player controller
	KinematicCharacterController* p_controller;

	btCollisionShape* m_pCollisionShape;
	btDefaultMotionState* m_pMotionState;
	btPairCachingGhostObject* m_pGhostObject;

	float radius;
	float height;
	float mass;

};

