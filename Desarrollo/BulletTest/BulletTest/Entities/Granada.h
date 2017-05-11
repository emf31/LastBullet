#pragma once
#include "EntActive.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <Estructuras.h>
#include <Character.h>
#include <BulletCollision\CollisionDispatch\btGhostObject.h>

#define GRANADACARGADA 0
#define GRANADADISPARADA 1



class Granada : public EntActive
{
public:
	Granada(Character* owner);
	~Granada();

	void setRigidBody(btRigidBody* rigidBody) { m_rigidBody = rigidBody; }

	int getEstado() const{ return estado;}
	void setEstado(int newEstado) { estado = newEstado; }

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
	virtual void handleMessage(const Message& message) override;
	virtual std::string getClassName() { return "Granada"; }
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;
	virtual void setPosition(const Vec3<float> &pos) override;

	void shoot(const btVector3& posicionPlayer);
	void serverShoot(TGranada& g);

	float explosion(Character* player, const Vec3<float>& posExplosion, float radio);

	btRigidBody* m_rigidBody;

	Clock clockRecargaGranada;



private:
	int estado;
	RakNet::RakNetGUID guidLanzador;

	Vec3<float> fuerza;
	float radioExplosion;
	float mass;
	float height;
	float radius;
	float timeRecargaGranada;
	float restitution;

	Character* m_character;

	btGhostObject* m_explosion;
};

