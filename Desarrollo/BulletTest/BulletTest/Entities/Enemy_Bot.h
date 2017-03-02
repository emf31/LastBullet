#pragma once
#include <Character.h>
#include <Animation.h>
#include <Util.h>
#include <Vec2f.h>
#include <KinematicCharacterController.h>
#include <NavGraphNode.h>
#include <LifeComponent.h>
#include <NetBot.h>
#include <memory>

#include "FuzzyLogic\FuzzyModule.h"
#include <SensorySystem\SensoryMemory.h>
#include "WeaponSystem.h"
#include "TargetingSystem.h"
#include "MachineState.h"



class PathPlanner;
class PathFollow;


class Enemy_Bot : public Character {

public:

	Enemy_Bot(const std::string& name, RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);

	~Enemy_Bot();

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message & message) override;
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;
	virtual std::string getClassName() { return "Enemy_Bot"; }
	virtual void setPosition(const Vec3<float> &pos) override;

	void impulsar(Vec3<float> force);
	void setWeapon(int weapon) { weaponSystem->setWeapon(weapon); }

	float getRadio() const { return radius; }

	//Devolvemos el path planning
	PathPlanner* getPathPlanning() const { return m_PathPlanner; }

	PathFollow* getPathFollow() const { return m_PathFollow; }

	LifeComponent& getLifeComponent() { return life_component; }

	SensoryMemory* const GetSensoryMemory()const { return sense; }

	WeaponSystem* const getWeaponSys()const { return weaponSystem; }

	TargetingSystem* const getTargetSys() { return targetingSystem; }

	MachineState* const getMachineState()const { return m_pStateMachine; }

	Entity* const getTargetBot()const { return targetingSystem->GetTarget(); }


	void lookAt(Vec2f at);

	//Devuelve true si el bot esta en esa posicion
	bool isAtPosition(Vec2f pos);

	void updateMovement();

	void updateFacing();


	Vec2f createPathToPosition(Vec2f vec);
	float createPathToItem(const std::string& tipo);
	Vec2f createRandomPath();

	std::shared_ptr<NetBot> m_network;
	
	
	void elegirWeapon(float DistToTarget);

	void FuzzyLifeObject();

	void crearFuzzyRules();

	Vec2f getFacing();

	float getFOV();

	virtual float getVida() override;
	virtual bool isDying() override;
	virtual float getDesiAsalto() override;
	virtual float getDesiRocketLauncher() override;
	virtual float getDesiSniper()  override;

	virtual void vaciarArma(std::string arma) override;
	virtual void InsertarArmaDebug(std::string arma) override;
	virtual void setNumCiclos(int num) override;

	virtual void resetMachineState() {
		m_pStateMachine->resetMachineState();
	}


	void decisionAfterKill();

	void resetAll();

	virtual std::string getStateActual() override;


private:


	float desiAsalto = 0;
	float desiRocketLauncher = 0;
	float desiSniper = 0;
		
	float lifeTarget = 0;

	float radius;
	float height;
	float mass;
	float FOV;

	int ciclo = 0;
	int valorCiclos = 1;

	enum AnimState { quieto, andando, corriendo, saltando, saltando2 } m_animState;

	void updateAnimation();


	//el bot lo usa para seguir un camino
	PathPlanner* m_PathPlanner;

	//Calcula el vector movimiento del bot
	PathFollow*	m_PathFollow;

	WeaponSystem* weaponSystem;

	TargetingSystem* targetingSystem;

	MachineState* m_pStateMachine;

	SensoryMemory* sense;

	Animation animation;

	KinematicCharacterController* p_controller;

	LifeComponent life_component;




	//the direction the bot is facing (and therefore the direction of aim). 
	//Note that this may not be the same as the bot's heading, which always
	//points in the direction of the bot's movement
	Vec2f    m_vFacing;

	//a normalized vector pointing in the direction the entity is heading. 
	Vec2f    m_vHeading;

	//Current target
	Vec2f m_Target;

	//FuzzyLogic


	FuzzyModule fm;

	FuzzyVariable& DistToTarget = fm.CreateFLV("DistToTarget");

	FzSet Target_Close = DistToTarget.AddLeftShoulderSet("Target_Close", 0, 30, 70);
	FzSet Target_Medium = DistToTarget.AddTriangularSet("Target_Medium", 30, 70, 110);
	FzSet Target_Far = DistToTarget.AddRightShoulderSet("Target_Far", 70, 110, 8000);

	//LifeObject

	FuzzyVariable& Life = fm.CreateFLV("Life");
	FuzzyVariable& LifeTarget = fm.CreateFLV("LifeTarget");
//	FuzzyVariable& DistToLifeObject = fm.CreateFLV("DistToLifeObject");

	FzSet Life_Low = Life.AddLeftShoulderSet("Life_Low", 0, 10, 30);
	FzSet Life_Okay = Life.AddTriangularSet("Life_Okay", 10, 30, 60);
	FzSet Life_Loads = Life.AddRightShoulderSet("Life_Loads", 60, 70, 100);
	
	FzSet Life_LowTarget = LifeTarget.AddLeftShoulderSet("Life_LowTarget", 0, 10, 30);
	FzSet Life_OkayTarget = LifeTarget.AddTriangularSet("Life_OkayTarget", 10, 30, 60);
	FzSet Life_LoadsTarget = LifeTarget.AddRightShoulderSet("Life_LoadsTarget", 60, 70, 100);

	/*
	FzSet Life_Close = DistToLifeObject.AddLeftShoulderSet("Life_Close", 0, 40, 60);
	FzSet Life_Medium = DistToLifeObject.AddTriangularSet("Life_Medium", 40, 65, 90);
	FzSet Life_Far = DistToLifeObject.AddRightShoulderSet("Life_Far", 65, 90, 150);
	*/


	FuzzyVariable& DesirabilityLifeDrop = fm.CreateFLV("DesirabilityLifeDrop");

	FzSet UndesirableLifeDrop = DesirabilityLifeDrop.AddLeftShoulderSet("UndesirableLifeDrop", 0, 25, 50);
	FzSet DesirableLifeDrop = DesirabilityLifeDrop.AddTriangularSet("DesirableLifeDrop", 25, 50, 75);
	FzSet VeryDesirableLifeDrop = DesirabilityLifeDrop.AddRightShoulderSet("VeryDesirableLifeDrop", 50, 75, 100);

	//DesirabilityAsalto

	FuzzyVariable& DesirabilityAsalto = fm.CreateFLV("DesirabilityAsalto");
	FuzzyVariable& AmmoStatusAsalto = fm.CreateFLV("AmmoStatusAsalto");


	FzSet UndesirableAsalto = DesirabilityAsalto.AddLeftShoulderSet("UndesirableAsalto", 0, 25, 50);
	FzSet DesirableAsalto = DesirabilityAsalto.AddTriangularSet("DesirableAsalto", 25, 50, 75);
	FzSet VeryDesirableAsalto = DesirabilityAsalto.AddRightShoulderSet("VeryDesirableAsalto", 50, 75, 100);

	FzSet Ammo_LowAsalto = AmmoStatusAsalto.AddLeftShoulderSet("Ammo_LowAsalto", 0, 0, 10);
	FzSet Ammo_OkayAsalto = AmmoStatusAsalto.AddTriangularSet("Ammo_OkayAsalto", 0, 30, 60);
	FzSet Ammo_LoadsAsalto = AmmoStatusAsalto.AddRightShoulderSet("Ammo_LoadsAsalto", 30, 60, 150);


	//DesirabilityRocketLauncher

	FuzzyVariable& DesirabilityRocketLauncher = fm.CreateFLV("DesirabilityRocketLauncher");
	FuzzyVariable& AmmoStatusRocketLauncher = fm.CreateFLV("AmmoStatusRocketLauncher");

	FzSet UndesirableRocketLauncher = DesirabilityRocketLauncher.AddLeftShoulderSet("UndesirableRocketLauncher", 0, 25, 50);
	FzSet DesirableRocketLauncher = DesirabilityRocketLauncher.AddTriangularSet("DesirableRocketLauncher", 25, 50, 75);
	FzSet VeryDesirableRocketLauncher = DesirabilityRocketLauncher.AddRightShoulderSet("VeryDesirableRocketLauncher", 50, 75, 100);

	FzSet Ammo_LowRocketLauncher = AmmoStatusRocketLauncher.AddLeftShoulderSet("Ammo_LowRocketLauncher", 0, 0, 5);
	FzSet Ammo_OkayRocketLauncher = AmmoStatusRocketLauncher.AddTriangularSet("Ammo_OkayRocketLauncher", 0, 5, 10);
	FzSet Ammo_LoadsRocketLauncher = AmmoStatusRocketLauncher.AddRightShoulderSet("Ammo_LoadsRocketLauncher", 5, 10, 15);

	//DesirabilitySniper

	FuzzyVariable& DesirabilitySniper = fm.CreateFLV("DesirabilitySniper");
	FuzzyVariable& AmmoStatusSniper = fm.CreateFLV("AmmoStatusSniper");

	FzSet UndesirableSniper = DesirabilitySniper.AddLeftShoulderSet("UndesirableSniper", 0, 25, 50);
	FzSet DesirableSniper = DesirabilitySniper.AddTriangularSet("DesirableSniper", 25, 50, 75);
	FzSet VeryDesirableSniper = DesirabilitySniper.AddRightShoulderSet("VeryDesirableSniper", 50, 75, 100);

	FzSet Ammo_LowSniper = AmmoStatusSniper.AddLeftShoulderSet("Ammo_LowSniper", 0, 0, 5);
	FzSet Ammo_OkaySniper = AmmoStatusSniper.AddTriangularSet("Ammo_OkaySniper", 0, 5, 10);
	FzSet Ammo_LoadsSniper = AmmoStatusSniper.AddRightShoulderSet("Ammo_LoadsSniper", 5, 10, 15);

	friend class PathPlanner;
};