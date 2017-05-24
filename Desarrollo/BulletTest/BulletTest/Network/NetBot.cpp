#include <NetBot.h>
#include <Estructuras.h>
#include <EntityManager.h>
#include <Enemy_Bot.h>
#include <NetworkManager.h>


NetBot::NetBot() : NetObject(), m_bot()
{


}

void NetBot::SetBot(Enemy_Bot *bot) {
	m_bot = bot;
	m_bot->setGUID(peer->GetMyGUID());
	EntityManager::i().registerRaknetEntity(bot);
}

NetBot::~NetBot()
{

}

void NetBot::inicializar()
{
	conectar("127.0.0.1", server_port);

	while (isConnected() == false) {
		NetworkManager::i().updateNetwork(Time::Zero);
	}

	
}

void NetBot::handlePackets(Time elapsedTime)
{
	for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {

		// Recibimos un paquete, tenemos que obtener el tipo de mensaje
		mPacketIdentifier = getPacketIdentifier(packet);

		switch (mPacketIdentifier) {
		case ID_REMOTE_DISCONNECTION_NOTIFICATION:
			printf("Otro cliente se ha desconectado.\n");
			break;
		case 22:
			printf("EL SERVIDOR SE HA CAIDO.\n");
			break;
		case ID_REMOTE_CONNECTION_LOST:
			printf("Otro cliente ha perdido la conexion.\n");

			break;
		case ID_CONNECTION_ATTEMPT_FAILED:
			printf("Fallo en la conexion.\n");

			//Aqui enviariamos un evento de conexion fallida a la interfaz.

			break;

		case ID_CONNECTION_REQUEST_ACCEPTED: {

			printf("Nuestra conexion se ha aceptado.\n");
			servidor = packet->guid;
			servidorAdr = packet->systemAddress;


			//Esta variable indica que el servidor ha aceptado la conexion
			connected = true;

			TPlayer nuevoplayer;
			nuevoplayer.guid = peer->GetMyGUID();
			nuevoplayer.name = BotName;
			nuevoplayer.color = 1;
			nuevoplayer.available = 1;

			dispatchMessage(nuevoplayer, NUEVO_BOT);

			/*RakID rakID;
			rakID.guid = peer->GetMyGUID();
			NetworkManager::i().dispatchMessage(rakID, CARGA_COMPLETA);*/

			



			break;
		}
		case IMPACTO_BALA:
		{

			TImpactoBala bala = *reinterpret_cast<TImpactoBala*>(packet->data);

			//nos guardamos el guid de quien dispara por si mata al jugador poder actualizar la tabla

			//si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			m_bot->getLifeComponent().restaVida(bala.damage, bala.guidDisparado);
			

			break;
		}
		
		case IMPACTO_ROCKET:
		{
			TImpactoRocket impacto = *reinterpret_cast<TImpactoRocket*>(packet->data);

			//si recibimos este mensaje es pork nos han dado a nosotros, por lo que nos restamos vida;
			//le pasamos el damage causado por el rocket y el guid del jugador que lo disparo, para que si lo mata pueda apuntarse un punto
			m_bot->getLifeComponent().restaVida(impacto.damage, impacto.guidDisparado);

			break;
		}

		

		case APLICAR_IMPULSO:
		{

			TImpulso imp = *reinterpret_cast<TImpulso*>(packet->data);

			//si recibimos este mensaje es pork nos han dado a nosotros
			m_bot->impulsar(imp.fuerza);

			break;
		}
		
		}
	}
}

void NetBot::apagar()
{
	if (isConnected()) {
		//First call shutdown from base class
		NetObject::apagar();

		//Do what you need here
	}
	
}
