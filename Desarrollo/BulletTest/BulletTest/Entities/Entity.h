#pragma once

#include "../Otros/vec3.hpp"
#include "../Otros/Time.hpp"
#include "../Otros/Clock.hpp"
#include "../Motor/RenderState.h"

#include "../Motor/SceneNode.h"
#include "../Handlers/Message.h"
#include <RakPeerInterface.h>

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <memory>

#include "../TriggerSystem/TriggerRecordStruct.h"


#define DISPONIBLE 0
#define USADO 1

#define LANZACOHETES 10
#define ASALTO 11
#define PISTOLA 12



class Entity
{
public:
	

	Entity(int id, std::shared_ptr<SceneNode> nodo, const std::string& name = "", RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	virtual ~Entity();

	void updateRender(float interpolation);
	Vec3<float> getRenderPosition();

	RenderState* getRenderState() { return &m_renderState; }

	RakNet::RakNetGUID getGuid() {
		return m_guid;
	}

	void setGUID(RakNet::RakNetGUID guid) {
		m_guid = guid;
	}
	void setName(std::string& name) {
		m_name = name;
	 }
	std::string getName() {
		return m_name;
	}


	int getID() {
		return m_id;
	}
	void setID(int id) {
		m_id = id;
	}
	

	
		
	
	

	byte getTriggerFlags() {
		return dwTriggerFlags;
	}

	
	std::shared_ptr<SceneNode> getNode();

	virtual void inicializar() = 0;
	virtual void update(Time elapsedTime) = 0;
	virtual void handleInput() = 0;
	virtual void cargarContenido() = 0;
	virtual void borrarContenido() = 0;
	virtual void handleMessage(const Message& message) = 0;
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) = 0;

	virtual std::string getClassName() = 0;


protected:
	int m_id;
	RakNet::RakNetGUID m_guid;
	std::string m_name;
	std::shared_ptr<SceneNode> m_nodo;
	RenderState m_renderState;
	

	byte dwTriggerFlags = kTrig_None;

	//Sirve para identificar que una entity sea un grupo de entities, siempre se crea a false
	bool isGroup;
private:

	
};

