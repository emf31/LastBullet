#pragma once
#include "irrlicht.h"
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

#define CARGADO 0
#define DISPARADO 1


class Rocket :
	public Entity
{
public:
	Rocket();
	~Rocket();

	void setRigidBody(btRigidBody* rigidBody) { m_rigidBody = rigidBody; }

	void setPosition(Vec3<float> pos);
	int getEstado() { return estado;}
	void setEstado(int newEstado) { estado = newEstado; }
	void resetRigidBody();
	// Heredado vía Entity
	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;


	btRigidBody* m_rigidBody;

private:
	int estado=CARGADO;
};

