
#include "MessageHandler.h"

void MessageHandler::update()
{
	//std::cout << m_messages.size() << std::endl;
	//Vamos enviando todos los mensajes
	//m.lock();
	while (!m_messages.empty()) {
		Message message;
		message = m_messages.dequeue();

		//Enviamos el mensaje a la entity
		message.entity->handleMessage(message);
	}
	//m.unlock();
}

void MessageHandler::sendMessage(const Message & message)
{
	m_messages.enqueue(message);
}


 void MessageHandler::borrarContenido()
{
	/*while (!m_messages.empty()) {
		m_messages.pop();
	}*/

}
