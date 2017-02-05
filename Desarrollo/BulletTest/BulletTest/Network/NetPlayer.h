#pragma once
#include <NetObject.h>
#include <Player.h>

class NetPlayer : public NetObject{
public:
	NetPlayer(Player* player);
	~NetPlayer();

	virtual void handlePackets(Time elapsedTime) override;

private:
	Player* m_player;

};