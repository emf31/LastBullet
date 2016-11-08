
#include "MessageHandler.h"

void MessageHandler::update()
{
	//std::cout << m_messages.size() << std::endl;
	//Vamos enviando todos los mensajes
	m.lock();
	while (!m_messages.empty()) {
		Message message = m_messages.front();
		//lo borramos de la cola
		m_messages.pop();
		//Enviamos el mensaje a la entity
		message.entity->handleMessage(message);
	}
	m.unlock();
}

void MessageHandler::sendMessage(const Message & message)
{
	m.lock();

	m_messages.push(message);

	m.unlock();
}


 void MessageHandler::borrarContenido()
{
	while (!m_messages.empty()) {
		m_messages.pop();
	}

}
