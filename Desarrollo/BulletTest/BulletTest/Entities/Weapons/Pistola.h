#pragma once
#include "Weapon.h"

#define numCargadoresPistola 6


class Pistola : public Weapon
{
public:
	Pistola(Character* ent);
	~Pistola();

	void* operator new(size_t size) { return  _aligned_malloc(size, 16); }
	void operator delete(void *p) { _aligned_free(p); }

	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message& message) override;

	virtual std::string getClassName() { return "Pistola"; }

	virtual int getCurrentWeaponType() override { return Type::eWeapon::Pistola; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual Character* shoot(const Vec3<float>& target);

	virtual void recargar() override;

	virtual void reloadSound() {
		SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("reloadPistola.mp3", "sounds"), Sound::type::sound);
	}

	virtual void updatePositionAndRotation() override {

		Vec3<float> vecDir = GraphicEngine::i().getActiveCamera()->getVectorDirection();
		Vec3<float> newPos = vecDir * 0.3f;
		m_nodo->setOrientation(vecDir);
		m_nodo->setPosition(GraphicEngine::i().getActiveCamera()->getPosition());
		m_nodo->updatePosition(newPos);

	}
	virtual void resetAmmoTotal() { numCargadores = numCargadoresPistola; }

private:
	btVector3 SIZE_OF_WORLD;
	btVector3 FUERZA;

	int cont = 0;
};

