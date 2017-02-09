#pragma once

#include <DebugMarks.h>
#include <map>
#include <Enemy.h>
#include <Estructuras.h>

class NetworkDebugger{
public:
	NetworkDebugger();
	~NetworkDebugger();

	bool addDebugMark(int entID);
	bool removeDebugMark(int entID);
	DebugMarks* getDebugMark(int entID);

	void sendSyncPackage(const RakNet::RakNetGUID& guid, unsigned char message);

	void receivedSyncPacket(const TSyncMessage& sync);

	void restartPacketsCount();

	int getPacketCount(unsigned char message);


private:
	//Contador de paquetes
	std::unordered_map<unsigned char, int> m_counter;

	//Enemy ID, DebugMark
	std::unordered_map<int, DebugMarks*> m_marks;
};