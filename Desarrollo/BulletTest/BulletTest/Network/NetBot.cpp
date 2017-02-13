#include <NetBot.h>
#include <Estructuras.h>
#include <EntityManager.h>
#include <Enemy_Bot.h>


NetBot::NetBot(Enemy_Bot* bot) : NetObject(), m_bot(bot)
{


}

NetBot::~NetBot()
{

}

void NetBot::handlePackets(Time elapsedTime)
{

}

void NetBot::apagar()
{
	if (isConnected()) {
		//First call shutdown from base class
		NetObject::apagar();

		//Do what you need here
	}
	
}
