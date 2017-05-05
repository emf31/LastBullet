#pragma once

#include  <Clock.hpp>
#include <vec3.hpp>

#include <RakPeerInterface.h>

class Entity
{
public:
	Entity(const std::string& name, RakNet::RakNetGUID guid, int id = -1);
	virtual ~Entity();


	Vec3<float> getPosition() const { return m_position; }
	void setPosition(Vec3<float>& pos) { m_position = pos; }

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
	virtual std::string getClassName() = 0;

	bool isAvailable() const { return m_available; }
	void setAvailable(bool a) { m_available = a; }

protected:
	RakNet::RakNetGUID m_guid;
	int m_id;
	std::string m_name;
	Vec3<float> m_position;

	//Si el player ha cargado el mundo o no, y esta preparado para jugar
	bool m_available;

private:

	
};

