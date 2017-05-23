#include "Weapon.h"


Weapon::Weapon(Character* ent) : EntActive(-1, NULL), estadoWeapon(CARGADA), m_ent (ent)
{

}


Weapon::~Weapon()
{
}


void Weapon::recargar() {


	if (estadoWeapon == CARGADA) {
		relojrecarga.restart();
		estadoWeapon = DESCARGADA;

		reloadSound();

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

bool Weapon::canShoot()
{

	if (disparos < capacidadAmmo && estadoWeapon == CARGADA && cadenciaOk())
		return true;

	return false;
}

bool Weapon::cadenciaOk()
{
	if (relojCadencia.getElapsedTime().asMilliseconds() > cadencia.asMilliseconds())
		return true;
	return false;
}

Vec3<float> Weapon::getBalaRotation()
{
	if (m_ent->getClassName() == "Player"){
		return GraphicEngine::i().getActiveCamera()->getRotation();
	}
	if (m_ent->getClassName() == "Enemy_Bot") {
		return m_ent->getRenderState()->getRenderRotation();
	}
	return Vec3<float>();
}
