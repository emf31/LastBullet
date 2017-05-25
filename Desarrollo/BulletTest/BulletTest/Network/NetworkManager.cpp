#include "NetworkManager.h"
#include <StateStack.h>

NetworkManager::~NetworkManager()
{
}

void NetworkManager::createServer()
{
	startup(L"RaknetServerv0.1.exe");
}

void NetworkManager::startup(LPCTSTR lpApplicationName)
{

	hJob = CreateJobObject(NULL, NULL);

	/*
	* Causes all processes associated with the job to terminate when the
	* last handle to the job is closed.
	*/
	jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
	SetInformationJobObject(hJob, JobObjectExtendedLimitInformation, &jeli, sizeof(jeli));


	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// start the program up
	CreateProcess(lpApplicationName,   // the path
		NULL,			// Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		FALSE/*CREATE_NEW_CONSOLE*/,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);

	/*
	* Add the process to our job object.
	*/
	AssignProcessToJobObject(hJob, pi.hProcess);


	// Close process and thread handles. 
	//CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

bool NetworkManager::removeNetBotObject(std::shared_ptr<NetBot> netobj)
{
	m_netBots.remove(netobj);

	//should check here if it's removed

	return true;
}

void NetworkManager::apagar()
{
	m_netBots.clear();

	m_netPlayer->apagar();
	
	//cerrar el server
	TerminateProcess(pi.hProcess, 0);
	//CloseHandle(pi.hProcess);



}

//Creates net player object and stores it in shared ptr
std::shared_ptr<NetPlayer> NetworkManager::createNetPlayer()
{
	NetPlayer* netp = new NetPlayer();

	// takes ownership of pointer
	// if acquires new pointer, deletes managed object 
	m_netPlayer.reset(netp);


	return m_netPlayer;
	
}

std::shared_ptr<NetBot> NetworkManager::createNetBot()
{
	NetBot* netp = new NetBot();

	std::shared_ptr<NetBot> ptr(netp);

	m_netBots.push_back(ptr);

	return ptr;
}

void NetworkManager::updateNetwork(Time elapsedTime)
{
	//No updatear la red si estamos cargando el mapa
	/*if (StateStack::i().GetCurrentStateID() == States::ID::Carga) {
		return;
	}*/

	std::list<std::shared_ptr<NetBot>>::iterator it;
	for (it = m_netBots.begin(); it != m_netBots.end(); ++it) {
		(*it)->handlePackets(elapsedTime);
	}

	//We call handle packets of netplayer too
	m_netPlayer->handlePackets(elapsedTime);

	
}

void NetworkManager::configureNetwork()
{
	std::shared_ptr<NetPlayer> netPlayer = NetworkManager::i().createNetPlayer();
	netPlayer->inicializar();

	movementPrediction = true;
}

#include <StringCompressor.h>

std::string NetworkManager::serverLogInfo()
{
	RakID rakid;
	rakid.guid = m_netPlayer->getMyGUID();
	dispatchMessage(rakid, SOLICITAR_INFO);

	RakNet::Packet *packet;

	while (true) {
		//Now wait to receive answer
		for (packet = m_netPlayer->peer->Receive(); packet; m_netPlayer->peer->DeallocatePacket(packet), packet = m_netPlayer->peer->Receive()) {
			if (packet == 0) {
				RakSleep(1000);
				continue;
			}
			if (packet->data[0] == SOLICITAR_INFO) {
				
				RakNet::RakString rakString;
				RakNet::BitStream r(packet->data, packet->length, false);
				r.IgnoreBytes(1);
				r.ReadCompressed(rakString);

				/*char buffer[1000];
				RakNet::StringCompressor::Instance()->DecodeString(rakString, 0, &r, 0);*/

				//TLogInfo* info = static_cast<TLogInfo*>(packet->data);



				return std::string(rakString.C_String());
			}

		}
	}

	

}
