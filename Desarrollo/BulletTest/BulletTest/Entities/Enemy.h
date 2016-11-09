#pragma once
#include "Entity.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicscommon.h>


#include "../Motor de Red/Estructuras.h"
#include "../Handlers/Message.h"

#include <queue>
#include <mutex>

#include "../Motor/BasicSceneNode.h"

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



	virtual void handleMessage(const Message & message) override;

	void encolaPos(TPlayer pos);
	void desEncolaPos();
	//esto es un semaforo para cuando accedamos de diferentes hilos no intenten escribir y leer a la vez
	std::mutex m;


private:


	btRigidBody* m_rigidBody;
	std::queue<Vec3<float>> m_positions;

	virtual std::string getClassName() { return "Enemy"; }
	
};

