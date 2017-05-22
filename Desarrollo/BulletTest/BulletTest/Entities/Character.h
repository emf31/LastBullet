#pragma once

#include <vec3.hpp>
#include <Time.hpp>
#include <Clock.hpp>
#include <RenderState.h>

#include <EntActive.h>
#include <LifeComponent.h>

#include "irrKlang/ik_ISound.h"
#include <SoundManager.h>

class AnimationMachine;

class Character : public EntActive
{
public:
	

	Character(int id, std::shared_ptr<SceneNode> nodo, const std::string& name = "", RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	virtual ~Character();

	virtual void inicializar() = 0;
	virtual void update(Time elapsedTime) = 0;
	virtual void handleInput() = 0;
	virtual void cargarContenido() = 0;
	virtual void borrarContenido() = 0;
	virtual void handleMessage(const Message& message) = 0;
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) = 0;
	virtual std::string getClassName() = 0;
	virtual void setPosition(const Vec3<float>& vec) = 0;

	virtual float getVida() { return life_component->getVida(); }
	virtual bool isDying() { return life_component->isDying(); }
	virtual std::string getStateActual() { return ""; }
	virtual void resetMachineState() {};
	virtual void setNumCiclos(int num) {}

	virtual float getDesiAsalto() { return 0; }
	virtual float getDesiRocketLauncher() { return 0; }
	virtual float getDesiSniper() { return 0; }

	virtual void vaciarArma(std::string arma) {};
	virtual void InsertarArmaDebug(std::string arma) {};

	virtual int getCurrentWeaponType() = 0;

	void setAvailable(bool a) { available = a; }
	bool isAvailable() { return available; }

	LifeComponent* getLifeComponent() { return life_component; }
	AnimationMachine* getAnimationMachine();
	void setLoD(bool a) { calcularLOD = a; };
	bool getLOD() { return calcularLOD; }

	void setOnGround(bool ground) { onGround = ground; }

	virtual bool isOnGround() const = 0;

	void setIsMoving(bool mov) { moving = mov; }

	bool isMoving() const { return moving; }

	virtual void resetAll() = 0;

	ISound* footsteps;

protected:

	LifeComponent* life_component;
	AnimationMachine* animationMachine;


	bool onGround;
	bool moving;

	//Say if this player is ready to play
	bool available;

	bool calcularLOD = true;


	

};

