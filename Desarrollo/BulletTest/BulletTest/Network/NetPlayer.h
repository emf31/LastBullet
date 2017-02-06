#pragma once
#include <NetObject.h>

//Forward declaration - prevents circular reference
class Player;

class NetPlayer : public NetObject{
public:
	NetPlayer(Player* player);
	~NetPlayer();

	virtual void handlePackets(Time elapsedTime) override;

private:
	Player* m_player;

};