#pragma once
#include <Entity.h>
#include <Animation.h>
#include <Util.h>
#include <Vec2f.h>
#include <KinematicCharacterController.h>
#include <NavGraphNode.h>
#include <LifeComponent.h>

#include "FuzzyLogic\FuzzyModule.h"
#include <SensorySystem\SensoryMemory.h>

#include "WeaponSystem.h"

class PathPlanner;
class PathFollow;

class Enemy_Bot : public Entity {

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


	float getRadio() const { return radius; }

	//Devolvemos el path planning
	PathPlanner* getPathPlanning() const { return m_PathPlanner; }

	LifeComponent& getLifeComponent() { return life_component; }

	//Devuelve true si el bot esta en esa posicion
	bool isAtPosition(Vec2f pos);

	void updateMovement();

	void createPathToPosition(Vec2f vec);
	void createPathToItem(const std::string& tipo);

	void elegirWeapon();

	void crearFuzzyRules();

	Vec2f getFacing();

	float getFOV();
private:
	

	float radius;
	float height;
	float mass;
	float FOV;

	Animation animation;

	enum AnimState { quieto, andando, corriendo, saltando, saltando2 } m_animState;

	void updateAnimation();

	//el bot lo usa para seguir un camino
	PathPlanner* m_PathPlanner;

	//Calcula el vector movimiento del bot
	PathFollow*	m_PathFollow;

	WeaponSystem* weaponSystem;




	//the direction the bot is facing (and therefore the direction of aim). 
	//Note that this may not be the same as the bot's heading, which always
	//points in the direction of the bot's movement
	Vec2f    m_vFacing;

	//a normalized vector pointing in the direction the entity is heading. 
	Vec2f    m_vHeading;

	//Current target
	Vec2f m_Target;

	KinematicCharacterController* p_controller;

	LifeComponent life_component;

	SensoryMemory* sense;

	friend class PathPlanner;




	//FuzzyLogic


	FuzzyModule fm;

	FuzzyVariable& DistToTarget = fm.CreateFLV("DistToTarget");

	FzSet Target_Close = DistToTarget.AddLeftShoulderSet("Target_Close", 0, 25, 150);
	FzSet Target_Medium = DistToTarget.AddTriangularSet("Target_Medium", 25, 150, 300);
	FzSet Target_Far = DistToTarget.AddRightShoulderSet("Target_Far", 150, 300, 500);



	//DesirabilityAsalto

	FuzzyVariable& DesirabilityAsalto = fm.CreateFLV("DesirabilityAsalto");
	FuzzyVariable& AmmoStatusAsalto = fm.CreateFLV("AmmoStatusAsalto");


	FzSet UndesirableAsalto = DesirabilityAsalto.AddLeftShoulderSet("UndesirableAsalto", 0, 25, 50);
	FzSet DesirableAsalto = DesirabilityAsalto.AddTriangularSet("DesirableAsalto", 25, 50, 75);
	FzSet VeryDesirableAsalto = DesirabilityAsalto.AddRightShoulderSet("VeryDesirableAsalto", 50, 75, 100);

	FzSet Ammo_LowAsalto = AmmoStatusAsalto.AddLeftShoulderSet("Ammo_LowAsalto", 0, 0, 10);
	FzSet Ammo_OkayAsalto = AmmoStatusAsalto.AddTriangularSet("Ammo_OkayAsalto", 0, 30, 60);
	FzSet Ammo_LoadsAsalto = AmmoStatusAsalto.AddRightShoulderSet("Ammo_LoadsAsalto", 30, 60, 200);

	//DesirabilitySniper

	FuzzyVariable& DesirabilitySniper = fm.CreateFLV("DesirabilitySniper");
	FuzzyVariable& AmmoStatusSniper = fm.CreateFLV("AmmoStatusSniper");

	FzSet UndesirableSniper = DesirabilitySniper.AddLeftShoulderSet("UndesirableSniper", 0, 25, 50);
	FzSet DesirableSniper = DesirabilitySniper.AddTriangularSet("DesirableSniper", 25, 50, 75);
	FzSet VeryDesirableSniper = DesirabilitySniper.AddRightShoulderSet("VeryDesirableSniper", 50, 75, 100);

	FzSet Ammo_LowSniper = AmmoStatusSniper.AddLeftShoulderSet("Ammo_LowSniper", 0, 0, 5);
	FzSet Ammo_OkaySniper = AmmoStatusSniper.AddTriangularSet("Ammo_OkaySniper", 0, 5, 10);
	FzSet Ammo_LoadsSniper = AmmoStatusSniper.AddRightShoulderSet("Ammo_LoadsSniper", 5, 10, 15);


};