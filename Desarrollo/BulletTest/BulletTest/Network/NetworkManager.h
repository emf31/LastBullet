#pragma once
#include <NetObject.h>
#include <Time.h>
#include <list>
#include <memory>

static const int SERVER_PORT = 65535;

class NetworkManager {
public:

	static NetworkManager& i() {
		static NetworkManager singleton;
		return singleton;
	}

	void inicializar(const std::string& address);
	

	void createNetObject(NetObject* netobj);
	void updateNetwork(Time elapsedTime);

private:
	std::list<NetObject*> m_netobjs;

	std::string serverIP;

	NetworkManager() { }
};