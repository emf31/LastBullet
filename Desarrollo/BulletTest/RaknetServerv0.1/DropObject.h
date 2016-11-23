#pragma once
#include"Entities/Entity.h"

class DropObject : public Entity
{
public:
	DropObject(int id);
	~DropObject();

	void resetTiempoRecargar() {
		clockRecargaLife.restart();
	}
	Clock clockRecargaLife;
	float timeRecargaLife = 3;
	void updateTiempo();
	bool disponible = true;
private:



	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void update(Time elapsedTime) override;
	virtual void handleInput() override;
	virtual void cargarContenido() override;
	virtual void borrarContenido() override;
};