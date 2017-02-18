#include "NetworkManager.h"


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
		CREATE_NEW_CONSOLE,              // No creation flags
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
	CloseHandle(pi.hProcess);
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
	
	

}

//Creates net player object and stores it in shared ptr
std::shared_ptr<NetPlayer> NetworkManager::createNetPlayer(Player* player)
{
	NetPlayer* netp = new NetPlayer(player);

	// takes ownership of pointer
	// if acquires new pointer, deletes managed object 
	m_netPlayer.reset(netp);
	
	return m_netPlayer;
	
}

std::shared_ptr<NetBot> NetworkManager::createNetBot(Enemy_Bot * bot)
{
	NetBot* netp = new NetBot(bot);

	std::shared_ptr<NetBot> ptr(netp);

	m_netBots.push_back(ptr);

	return ptr;
}

void NetworkManager::updateNetwork(Time elapsedTime)
{
	std::list<std::shared_ptr<NetBot>>::iterator it;
	for (it = m_netBots.begin(); it != m_netBots.end(); ++it) {
		(*it)->handlePackets(elapsedTime);
	}

	//We call handle packets of netplayer too
	m_netPlayer->handlePackets(elapsedTime);
}
