#pragma once
#include "Weapon.h"

#define numCargadoresAsalto 4


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

	virtual int getCurrentWeaponType() override { return Type::eWeapon::Asalto; }

	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual Character* shoot(const Vec3<float>& target);

	virtual void recargar() override;

	virtual void reloadSound() {
		SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("reloadAssault.mp3", "sounds"), Sound::type::sound);

	}

	virtual void updatePositionAndRotation() override;

	


	virtual void resetAmmoTotal() { 
		numCargadores = numCargadoresAsalto; 
	}

private:
	btVector3 SIZE_OF_WORLD;
	btVector3 FUERZA;

};

