#pragma once
#include "irrlicht.h"
#include "../../Motor/GraphicEngine.h"
#include "../../Motor/PhysicsEngine.h"
#include "../Entity.h"
#include "../../Handlers/MessageHandler.h"
#include "../GunBullet.h"
#include "../RocketBullet.h"
#include "math.h"
#include "../../Otros/Vec3f.h"
#include "../../Otros/Util.h"
#include "../../Handlers/MessageHandler.h"
#include "../../Handlers/Message.h"

#define CARGADA 0
#define DESCARGADA 1

class Weapon :
	public Entity
{
public:
	Weapon();
	~Weapon();

	virtual void inicializar() override ;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Weapon"; }

	virtual void shoot() = 0;

	virtual int getEstadoWeapon() { return estadoWeapon; }

	virtual int getAmmo() { return capacidadAmmo - disparos; }
	virtual int getCargadorWeapon() { return capacidadAmmo; }
	virtual int getAmmoTotal() { return numCargadores; }

	virtual void resetAmmoTotal()=0;

protected:
	Time cadencia;
	Clock relojCadencia;

	int capacidadAmmo;
	int numCargadores;
	int disparos;

	Time recarga;
	Clock relojrecarga;

	int estadoWeapon;
};

