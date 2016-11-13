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

	void UpWeapon() { listaWeapons->Siguiente(); }
	void DownWeapon() { listaWeapons->Anterior(); }


	void sumarVida() { m_vida++; printf("ME HE CURADO\n"); }

	Vec3<float> getVelocity() { return Vec3<float>(p_controller->getLinearVelocity().x(), p_controller->getLinearVelocity().y(), p_controller->getLinearVelocity().z()); }


	std::string getCurrentWeapon() {
		return listaWeapons->valorActual()->getClassName();
	};
private:
	float m_vida;

	Animation* animation;
	Granada* granada;
//	Weapon* weapon;

	Lista* listaWeapons;

	enum PlayerState {quieto,andando,corriendo,saltando,saltando2} m_playerState;

	//esta no deberia estar aqui acordarse de borrarla

	bool tieneAsalto = false;
	bool tieneRocketLauncher = false;
	bool tienePistola = false;

	bool isShooting=false;

	bool isJumping;
	bool isMoving;
	bool isRunning=false;

	
	float giro;

	Vec3<float> vectorPrev;
	Vec3<float> vectorNew;

	Vec3<float> speedFinal;

	//Animated Nodo
	//AnimatedSceneNode *m_animated;

	//Player controller
	KinematicCharacterController* p_controller;

	btCollisionShape* m_pCollisionShape;
	btDefaultMotionState* m_pMotionState;
	btPairCachingGhostObject* m_pGhostObject;

	float radius;
	float height;
	float mass;

	float m_acceleration_walk;
	float m_acceleration_run;
	float m_deceleration_walk;
	float m_deceleration_run;
	float m_maxSpeed_walk;
	float m_maxSpeed_run;
};

