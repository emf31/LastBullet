#pragma once
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <EntActive.h>
#include <MessageHandler.h>
#include "../GunBullet.h"
#include "../RocketBullet.h"
#include "math.h"
#include <vec3.hpp>
#include <Util.h>
#include <Message.h>
#include <SoundManager.h>


#define CARGADA 0
#define DESCARGADA 1

namespace Type {
	enum eWeapon : int {
		Asalto = 0,
		Rocket = 1,
		Pistola = 2,
		Sniper = 3
	};
}


class Weapon : public EntActive
{
public:
	Weapon(Character* ent);
	virtual ~Weapon();

	virtual void inicializar() = 0;

	virtual void update(Time elapsedTime) = 0;

	virtual void handleInput() = 0;

	virtual void cargarContenido() = 0;

	virtual void borrarContenido() = 0;

	virtual void handleMessage(const Message& message) = 0;

	virtual bool handleTrigger(TriggerRecordStruct* Trigger)  = 0;

	virtual std::string getClassName() { return "Weapon"; }

	virtual void setPosition(const Vec3<float> &pos) override;

	virtual Character* shoot(const Vec3<float>& target) = 0;

	virtual bool canShoot();

	virtual bool cadenciaOk();

	virtual void reloadSound() {};

	void vaciar() {
		disparos = capacidadAmmo;
		numCargadores = 0;
		estadoWeapon = DESCARGADA;
	}

	Vec3<float> getBalaRotation();

	virtual int getEstadoWeapon() { return estadoWeapon; }

	virtual int getAmmo() { return capacidadAmmo - disparos; }
	virtual int getCapacidadCargador() { return capacidadAmmo; }
	virtual int getNumCargadores() { return numCargadores; }
	virtual int getBalasRestantes() { return disparosRestantes; }

	virtual int getMunicionTotal() { return capacidadAmmo*numCargadores + disparosRestantes; }


	virtual void resetAmmoTotal() = 0;

	virtual void setEquipada(bool nuevoEquipada) { equipada = nuevoEquipada; }
	virtual void resetRecarga() { relojrecarga.restart(); }

	virtual void recargar();


	virtual void updatePositionAndRotation() = 0;


	virtual int getCurrentWeaponType() = 0;

protected:

	Time cadencia;
	Clock relojCadencia;

	int capacidadAmmo;
	int numCargadores;
	int disparos;

	float damage;

	Time recarga;
	Clock relojrecarga;

	int estadoWeapon;

	bool equipada=false;

	int disparosRestantes=0;

	Character* m_ent;


};

