#pragma once

#include <vec3.hpp>
#include <Time.hpp>
#include <Clock.hpp>
#include "../Motor/RenderState.h"

#include <SceneNode.h>
#include <Message.h>
#include <RakPeerInterface.h>

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <memory>

#include <TriggerRecordStruct.h>


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


	const RakNet::RakNetGUID& getGuid() { return m_guid; }
	void setGUID(const RakNet::RakNetGUID& guid) { m_guid = guid; }

	void setName(const std::string& name) { m_name = name; }
	const std::string& getName() const { return m_name; }

	int getID() const { return m_id; }
	void setID(int id) { m_id = id; }
	
	

	byte getTriggerFlags() const { return dwTriggerFlags; }

	
	std::shared_ptr<SceneNode> getNode();

	virtual void inicializar() = 0;
	virtual void update(Time elapsedTime) = 0;
	virtual void handleInput() = 0;
	virtual void cargarContenido() = 0;
	virtual void borrarContenido() = 0;
	virtual void handleMessage(const Message& message) = 0;
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) = 0;
	virtual std::string getClassName() = 0;
	virtual void setPosition(const Vec3<float>& vec) = 0;
	virtual Vec3<float> getPosition() = 0;

	

protected:
	//Unique id de la entity
	int m_id;
	//Unique id de red de la entity
	RakNet::RakNetGUID m_guid;
	//Nombre de la entity
	std::string m_name;
	//Nodo respresentativo de la entity
	std::shared_ptr<SceneNode> m_nodo;
	
	//Flag para trigger system
	byte dwTriggerFlags;

private:

	
};

