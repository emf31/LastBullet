#include "Weapon.h"


Weapon::Weapon() : Entity(-1, NULL)
{
	estadoWeapon = CARGADA;
}


Weapon::~Weapon()
{
}


void Weapon::recargar() {

	printf("RECARGANDO");
	relojrecarga.restart();
	estadoWeapon = DESCARGADA;

	disparosRestantes += capacidadAmmo - disparos;
	std::cout << "DISPAROS RESTANTES: " << disparosRestantes;
	if (disparosRestantes >= capacidadAmmo) {
		numCargadores++;
		disparosRestantes -= capacidadAmmo;
	}

}