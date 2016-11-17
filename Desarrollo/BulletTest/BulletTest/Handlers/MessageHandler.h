#pragma once
#include "../Entities/Entity.h"
#include <string>
#include "Message.h"
#include "../Otros/SafeQueue.h"

class MessageHandler
{
public:
	static MessageHandler& i() {
		static MessageHandler singleton;
		return singleton;
	}
	void update();
	void sendMessage(const Message& message);
	void borrarContenido();

private:
	SafeQueue<Message> m_messages;
	MessageHandler() {}
};