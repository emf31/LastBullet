#pragma once

#include "BulletTest\Otros\vec3.hpp"
#include  "BulletTest\Otros\Time.hpp"
#include  "BulletTest\Otros\Clock.hpp"
#include  "BulletTest\RenderState.h"
#include <RakPeerInterface.h>

class Entity
{
public:
	Entity(int id, const std::string& name = "");
	virtual ~Entity();

	RenderState* getRenderState() { return &m_renderState; }

	RakNet::RakNetGUID getGuid() {
		return m_guid;
	}

	void setGUID(RakNet::RakNetGUID guid){
		m_guid = guid;
	}


	int getID() {
		return m_id;
	}
	void setID(int id) {
		m_id = id;
	}

	std::string getName() {
		return m_name;
	}

	void setName(std::string name) {
		m_name = name;
	}

	virtual void inicializar() = 0;
	virtual void update(Time elapsedTime) = 0;
	virtual void handleInput() = 0;
	virtual void cargarContenido() = 0;
	virtual void borrarContenido() = 0;

protected:
	RakNet::RakNetGUID m_guid;
	int m_id;
	std::string m_name;
	RenderState m_renderState;

private:

	
};

