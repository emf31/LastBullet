#include "NetObject.h"
#include <NetworkManager.h>

NetObject::NetObject()
{
}

NetObject::~NetObject()
{
}

void NetObject::inicializar()
{
	/*conectado = false;
	char eleccion;
	int elec;
	std::string str;
	resetBarTime.restart();

	do {
		searchServersOnLAN();

		//Lista de servidores en la red
		std::cout << m_servers.size() << " servidor(es) encontrado(s): " << std::endl;
		for (std::size_t i = 0; i < m_servers.size(); ++i) {
			std::cout << "\t[" << i << "] - " << m_servers.at(i) << std::endl;
		}
		std::cout << "\t[a] - Actualizar" << std::endl;
		std::cout << "\t[m] - Introducir IP manualmente" << std::endl;
		std::cout << "Elige una opcion: ";
		std::cin >> eleccion;
		if (eleccion != 'a' && eleccion != 'm') {
			elec = eleccion - '0';
			std::string ipConPuerto = m_servers.at((elec));
			std::string ip = ipConPuerto.substr(0, ipConPuerto.find("|"));
			str = ip;
		}
		else if (eleccion == 'm') {
			printf("Introduce la IP \n");
			std::cin >> str;
			if (str != "a") {
				break;
			}
			else {
				eleccion = 'a';
			}
		}
	} while (eleccion == 'a');


	//Nos conectamos a la lobby del servidor
	//lobby.join(str, SERVER_PORT);

	conectar(str, SERVER_PORT);*/
}
