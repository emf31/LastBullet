#pragma once
#include <NetObject.h>

//Forward declaration - prevents circular reference
class Player;

class NetPlayer : public NetObject {
public:
	NetPlayer(Player* player);
	~NetPlayer();

	virtual void handlePackets(Time elapsedTime) override;

	//virtual void apagar();

	//Send packet to server using netplayer peer 
	template<typename T>
	void dispatchMessage(T& estructura, GameMessages messageType) {
		estructura.mID = messageType;

		peer->Send((const char*)&estructura, sizeof(estructura), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, getServerGUID(), false);
	}

private:
	Player* m_player;

};