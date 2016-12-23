
#include "MessageHandler.h"
#include "../Motor/PhysicsEngine.h"
#include "../Entities/EntityManager.h"
void MessageHandler::update()
{
	//std::cout << m_messages.size() << std::endl;
	//Vamos enviando todos los mensajes
	//m.lock();
	while (!m_messages.empty()) {
		/*btCollisionObjectArray arr = PhysicsEngine::i().m_world->getCollisionObjectArray();
		std::unordered_map<int, Entity*> map = EntityManager::i().m_entities;*/
		Message message;
		message = m_messages.dequeue();

		Entity* ent = static_cast<Entity*>(message.data);

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
	while (!m_messages.empty()) {
		m_messages.dequeue();
	}

}
