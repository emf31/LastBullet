#include "Lobby.h"

//TODO habria que cambiar el cliente para que los enemigos no se creen hasta haber empezado la partida,
//pero si alguien se conecta a mitad de partida habria que ver como hacerlo
/*
using namespace std;

LobbyClient::LobbyClient(RakNet::RakPeerInterface *peer) :
m_peer(peer), maxPlayers(4)
{
}

LobbyClient::~LobbyClient()
{
}

void LobbyClient::join(const std::string& address, int port)
{
	char eleccion;

	Cliente::i().conectar(address, port);

	while (Cliente::i().isConected() == false);


	do {
		cout << "( " << clients.size() << " / " << maxPlayers << " ) jugadores" << endl;
		cout << "Esperando a más jugadores..." << endl;

		std::cout << "\t[s] - Empezar partida" << std::endl;
		std::cout << "\t[e] - Salir al menu" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> eleccion;

		
	}while(eleccion != 's' || eleccion != 'e');

	if (eleccion == 'e') {
		disconnect();
		Cliente::i().inicializar();
	}
	else if (eleccion == 's') {

	}

}

void LobbyClient::disconnect()
{
	Cliente::i().apagar();
}

int LobbyClient::getMaxPlayers() const {
	return maxPlayers;
}

//Si supera el máximo de clientes permitidos devuelve false
bool LobbyClient::addPlayer(const TPlayer & p) {
	if (clients.size() < maxPlayers) {
		clients.push_back(p);
		return true;
	}
	else {
		return false;
	}
	
}*/

