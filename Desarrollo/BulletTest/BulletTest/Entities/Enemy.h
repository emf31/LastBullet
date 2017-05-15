#pragma once
#include <Character.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include <NetworkPrediction.h>

#include <Estructuras.h>
#include <Message.h>
#include <Animation.h>

#include <queue>

#include <BasicSceneNode.h>
#include <Granada.h>

#include <SoundManager.h>

class Enemy : public Character
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
	virtual void setPosition(const Vec3<float> &pos) override;
	virtual std::string getClassName() { return "Enemy"; }

	void updateEnemigo(Vec3<float> pos);

	//void updateAnimation();
	void updateState();

	virtual void handleMessage(const Message & message) override;

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;


	void lanzarGranada(TGranada g);

	virtual bool isDying() override;

	void setIsDying(bool die) { getLifeComponent()->setIsDying(die); }

	float getRadio(){
		return radius;
	}

	void setVisibilidadBilboardSync();

	NetworkPrediction* getNetworkPrediction() { return &nPrediction; }
	

private:


	float radius;
	float height;
	float mass;
	Animation* animation;
	Granada* granada;

	enum AnimState { quieto, andando, corriendo, saltando, saltando2 } m_animState;
	bool isMoving;

	//bool m_isDying;

	Clock relojMuerte;
	
	NetworkPrediction nPrediction;


	btRigidBody* m_rigidBody;
	

	ISound* footsteps;
	
};

