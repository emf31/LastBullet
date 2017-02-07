
#include "MessageHandler.h"
#include <PhysicsEngine.h>
#include <EntityManager.h>
void MessageHandler::update()
{
	//Vamos enviando todos los mensajes
	while (!m_messages.empty()) {

		Message message;
		message = m_messages.dequeue();

		Entity* ent = static_cast<Entity*>(message.data);

		//Enviamos el mensaje a la entity
		message.entity->handleMessage(message);

		
		
	}
}

void MessageHandler::sendMessage(const Message & message)
{
	m_messages.enqueue(message);
}


 void MessageHandler::borrarContenido()
{
	while (!m_messages.empty()) {
		m_messages.dequeue();
	}

}
