#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>


#include "../Motor de Red/Estructuras.h"
#include "../Handlers/Message.h"
#include "../Motor/Animation.h"

#include <queue>
#include <mutex>

#include "../Motor/BasicSceneNode.h"
#include "../Entities/Granada.h"

#include "../Otros/SafeQueue.h"

#include "../IA/MachineState.h"

class Enemy : public Entity
{
public:
	Enemy(const std::string& name, RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);

	~Enemy();

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;

	void setPosition(Vec3<float> pos);
	void updateEnemigo(Vec3<float> pos);

	void updateAnimation();
	void updateState();

	virtual void handleMessage(const Message & message) override;

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;



	void encolaMovimiento(TMovimiento mov);
	void desencolaMovimiento();

//	MachineState* GetFSM()const { return m_pStateMachine; }
	void lanzarGranada(TGranada g);

	bool isDying() { return m_isDying; }
	void setIsDying(bool die) { m_isDying = die; }

private:

	//MachineState* m_pStateMachine;

	float radius;
	float height;
	float mass;
	Animation* animation;
	Granada* granada;

	enum AnimState { quieto, andando, corriendo, saltando, saltando2 } m_animState;
	bool isMoving;

	bool m_isDying;

	Clock relojMuerte;
	


	btRigidBody* m_rigidBody;
	std::queue<TMovimiento> m_positions;
	
	

	virtual std::string getClassName() { return "Enemy"; }
	
};

