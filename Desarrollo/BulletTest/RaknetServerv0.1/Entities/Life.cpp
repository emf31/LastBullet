#include "Life.h"



Life::Life(int id) : Entity("vida", RakNet::UNASSIGNED_RAKNET_GUID, id)
{
	//setID(id);
}


Life::~Life()
{
}

void Life::updateTiempo()
{
	if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
		//enviar mensaje de que la vida se ha reseteado
		disponible = true;
	}
	disponible = false;

}


void Life::inicializar()
{
}

void Life::borrarContenido()
{
}
