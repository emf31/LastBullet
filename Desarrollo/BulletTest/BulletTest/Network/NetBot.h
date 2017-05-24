#pragma once
#include <NetObject.h>
#include <NetworkDebugger.h>
#include <memory>

//Forward declaration - prevents circular reference
class Enemy_Bot;

class NetBot : public NetObject {
public:
	NetBot();
	void SetBot(Enemy_Bot *bot);
	~NetBot();

	virtual void inicializar() override;

	virtual void handlePackets(Time elapsedTime) override;

	virtual void apagar();

	//Send packet to server using netplayer peer 
	template<typename T>
	void dispatchMessage(T& estructura, GameMessages messageType) {
		estructura.mID = messageType;

		peer->Send((const char*)&estructura, sizeof(estructura), HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, getServerGUID(), false);
	}

	void SetBotName(const std::string& name) {
		BotName = name;
	}

private:
	Enemy_Bot* m_bot;
	std::string BotName;
};