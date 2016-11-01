#include "MessageHandler.h"

void MessageHandler::update()
{
	std::cout << m_messages.size() << std::endl;
	//Vamos enviando todos los mensajes
	while (!m_messages.empty()) {
		Message message = m_messages.front();
		//lo borramos de la cola
		m_messages.pop();
		//Enviamos el mensaje a la entity
		message.entity->handleMessage(message);
	}
}

void MessageHandler::sendMessage(const Message & message)
{
	// Añadir a la cola
	m_messages.push(message);
}

MessageHandler::~MessageHandler()
{
	while (!m_messages.empty()) {
		m_messages.pop();
	}
}
