#include "Weapon.h"


Weapon::Weapon() : Entity(-1, NULL)
{
	estadoWeapon = CARGADA;
}


Weapon::~Weapon()
{
}


void Weapon::recargar() {

	relojrecarga.restart();
	estadoWeapon = DESCARGADA;

	disparosRestantes += capacidadAmmo - disparos;
	if (disparosRestantes >= capacidadAmmo) {
		numCargadores++;
		disparosRestantes -= capacidadAmmo;
	}

}