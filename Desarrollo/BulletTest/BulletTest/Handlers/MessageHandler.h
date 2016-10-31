#pragma once
#include "../Entities/Entity.h"
#include <string>
#include <queue>
#include "Message.h"

class MessageHandler
{
public:
	static void update();
	static void sendMessage(const Message& message);
	~MessageHandler();

private:
	static std::queue<Message> m_messages;
	MessageHandler() {}

};

