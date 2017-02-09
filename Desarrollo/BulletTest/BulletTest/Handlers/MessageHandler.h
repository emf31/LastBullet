#pragma once
#include "Message.h"
#include <Entity.h>
#include <string>
#include <queue>

class MessageHandler
{
public:
	static MessageHandler& i() {
		static MessageHandler singleton;
		return singleton;
	}

	void update();
	void sendMessage(const Message& message);
	void sendMessageNow(const Message& message);
	void borrarContenido();

private:
	std::queue<Message> m_messages;
	MessageHandler() {}
};