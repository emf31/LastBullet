#pragma once
#include "../Entities/Entity.h"
#include <string>
#include <queue>
#include "Message.h"

class MessageHandler
{
public:
	static MessageHandler& i() {
		static MessageHandler singleton;
		return singleton;
	}
	void update();
	void sendMessage(const Message& message);
	~MessageHandler();

private:
	std::queue<Message> m_messages;
	MessageHandler() {}

};

