#pragma once
#include <Entity.h>
#include <Animation.h>

#include <Vec2f.h>

class PathPlanner;

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
	virtual std::string getClassName() { return "Enemy"; }

	void setPosition(Vec3<float> pos);

	float getRadio() const {
		return radius;
	}

private:
	float radius;
	float height;
	float mass;

	btRigidBody* m_rigidBody;

	Animation animation;

	enum AnimState { quieto, andando, corriendo, saltando, saltando2 } m_animState;

	void updateAnimation();

	//el bot lo usa para seguir un camino
	PathPlanner*                 m_PathPlanner;


	
	//the direction the bot is facing (and therefore the direction of aim). 
	//Note that this may not be the same as the bot's heading, which always
	//points in the direction of the bot's movement
	Vec2f                           m_vFacing;

	//a normalized vector pointing in the direction the entity is heading. 
	Vec2f    m_vHeading;



};