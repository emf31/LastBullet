
#include "MessageHandler.h"
#include <PhysicsEngine.h>
#include <EntityManager.h>
void MessageHandler::update()
{
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
	m_messages.push(message);
}

void MessageHandler::sendMessageNow(const Message & message)
{
	message.entity->handleMessage(message);
}


 void MessageHandler::borrarContenido()
{
	while (!m_messages.empty()) {
		m_messages.pop();
	}

}
