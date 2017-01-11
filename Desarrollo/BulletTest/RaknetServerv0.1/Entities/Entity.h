#pragma once

#include  <Clock.hpp>
#include <Vec3f.h>

#include <RakPeerInterface.h>

class Entity
{
public:
	Entity(const std::string& name, RakNet::RakNetGUID guid, int id = -1);
	virtual ~Entity();


	Vec3f getPosition() const { return m_position; }
	void setPosition(Vec3f& pos) { m_position = pos; }

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
	virtual void borrarContenido() = 0;
	

protected:
	RakNet::RakNetGUID m_guid;
	int m_id;
	std::string m_name;
	Vec3f m_position;

private:

	
};

