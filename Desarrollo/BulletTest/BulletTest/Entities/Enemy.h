#pragma once
#include <Character.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>
#include <NetworkPrediction.h>

#include <Estructuras.h>
#include <Message.h>

#include <queue>

#include <BasicSceneNode.h>
#include <Granada.h>
#include <Weapons/Weapon.h>


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



	virtual int getCurrentWeaponType() override { return currWeapon; }

	void updateEnemigo(Vec3<float> pos);

	virtual void handleMessage(const Message & message) override;

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual bool isOnGround() const override;
	virtual bool isDying() override;

	void setIsDying(bool die) { getLifeComponent()->setIsDying(die); }

	float getRadio(){ return radius; }

	void setVisibilidadBilboardSync();

	NetworkPrediction* getNetworkPrediction() { return &nPrediction; }

	int animFrameTime;

	virtual void resetAll() override { }

	void setCurrentWeapon(int curr) { currWeapon = (Type::eWeapon)curr; }
	
private:

	float radius;
	float height;
	float mass;

	
	Type::eWeapon currWeapon;


	NetworkPrediction nPrediction;


	btRigidBody* m_rigidBody;
	
};

