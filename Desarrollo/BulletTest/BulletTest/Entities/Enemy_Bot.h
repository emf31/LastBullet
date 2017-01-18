#pragma once
#include <Entity.h>
#include <Animation.h>
#include <Util.h>
#include <Vec2f.h>
#include <KinematicCharacterController.h>

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
	virtual std::string getClassName() { return "Enemy"; }

	void setPosition(Vec3<float> pos);

	float getRadio() const {
		return radius;
	}

	//Devolvemos el path planning
	PathPlanner* getPathPlanning() const { return m_PathPlanner; }

	//Devuelve true si el bot esta en esa posicion
	bool isAtPosition(Vec2f pos)
	{
		const static double tolerance = 3.0;
		Vec2f curr_pos = vec3ToVec2(m_renderState.getPosition());

		return Vec2f(curr_pos - pos).Magnitude() < tolerance * tolerance;
	}

	void updateMovement();

	void createPathToPosition(Vec2f vec);

private:

	bool siguiendo = false;

	float radius;
	float height;
	float mass;

	Animation animation;

	enum AnimState { quieto, andando, corriendo, saltando, saltando2 } m_animState;

	void updateAnimation();

	//el bot lo usa para seguir un camino
	PathPlanner* m_PathPlanner;

	//Calcula el vector movimiento del bot
	PathFollow*	m_PathFollow;


	
	//the direction the bot is facing (and therefore the direction of aim). 
	//Note that this may not be the same as the bot's heading, which always
	//points in the direction of the bot's movement
	Vec2f    m_vFacing;

	//a normalized vector pointing in the direction the entity is heading. 
	Vec2f    m_vHeading;


	//Camino actual a seguir
	std::list<Vec2f> m_camino;

	//Current target
	Vec2f m_Target;


	KinematicCharacterController* p_controller;

	friend class PathPlanner;
};