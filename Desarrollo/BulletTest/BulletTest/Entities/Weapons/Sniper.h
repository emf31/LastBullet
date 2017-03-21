#pragma once
#include "Weapon.h"


#define numCargadoresSniper 3


class Sniper : public Weapon
{
public:
	Sniper(Character* ent);
	~Sniper();

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Sniper"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual void shoot(const Vec3<float>& target);

	virtual void updatePositionAndRotation() override {

		Vec3<float> vecDir = GraphicEngine::i().getActiveCamera()->getVectorDirection();
		Vec3<float> newPos = vecDir * 0.3f;
		m_nodo->setOrientation(vecDir);
		m_nodo->setPosition(m_ent->getRenderPosition());
		m_nodo->updatePosition(newPos);

	}

	virtual void resetAmmoTotal() { numCargadores = numCargadoresSniper; }

private:
	btVector3 SIZE_OF_WORLD;
	btVector3 FUERZA;

};

