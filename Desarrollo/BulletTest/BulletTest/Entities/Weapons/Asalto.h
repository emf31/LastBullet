#pragma once
#include "Weapon.h"

#define numCargadoresAsalto 5


class Asalto : public Weapon
{
public:
	Asalto(Character* ent);
	~Asalto();

	void* operator new(size_t size) { return  _aligned_malloc(size, 16); }
	void operator delete(void *p) { _aligned_free(p); }

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Asalto"; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual Character* shoot(const Vec3<float>& target);

	virtual void updatePositionAndRotation() override {

		Vec3<float> vecDir = GraphicEngine::i().getActiveCamera()->getVectorDirection();
		Vec3<float> newPos = vecDir * 0.3f;
		m_nodo->setOrientation(vecDir);
		m_nodo->setPosition(GraphicEngine::i().getActiveCamera()->getPosition());
		m_nodo->updatePosition(newPos);
		

	}


	virtual void resetAmmoTotal() { 
		numCargadores = numCargadoresAsalto; 
	}

private:
	btVector3 SIZE_OF_WORLD;
	btVector3 FUERZA;

};

