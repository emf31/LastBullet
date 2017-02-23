#pragma once
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <Entity.h>
#include <MessageHandler.h>
#include "../GunBullet.h"
#include "../RocketBullet.h"
#include "math.h"
#include "../../Otros/Vec3f.h"
#include <Util.h>
#include <Message.h>


#define CARGADA 0
#define DESCARGADA 1

class Weapon : public Entity
{
public:
	Weapon();
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

	virtual void shoot(const Vec3<float>& target) = 0;

	void vaciar() {
		disparos = capacidadAmmo;
		numCargadores = 0;
	}


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


};

