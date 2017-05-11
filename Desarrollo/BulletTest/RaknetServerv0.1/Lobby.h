#pragma once
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>

class Lobby
{
public:
	Lobby();
	~Lobby();


private:

	RakNet::RakNetGUID owner;

};