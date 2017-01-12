#include "DropObject.h"

DropObject::DropObject(int id) : Entity("weapondrop", RakNet::UNASSIGNED_RAKNET_GUID, id)
{
	//setID(id);
}


DropObject::~DropObject()
{
}

void DropObject::updateTiempo()
{
	if (clockRecargaLife.getElapsedTime().asSeconds() >= timeRecargaLife) {
		//enviar mensaje de que la vida se ha reseteado
		disponible = true;
	}
	disponible = false;

}


void DropObject::inicializar()
{
}

void DropObject::borrarContenido()
{
}

