#include "Weapon.h"


Weapon::Weapon() : Entity(-1, NULL), estadoWeapon(CARGADA)
{

}


Weapon::~Weapon()
{
}


void Weapon::recargar() {

	if (estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;

		disparosRestantes += capacidadAmmo - disparos;
		if (disparosRestantes >= capacidadAmmo) {
			numCargadores++;
			disparosRestantes -= capacidadAmmo;
		}
	}
}

void Weapon::setPosition(const Vec3<float>& pos)
{
}
