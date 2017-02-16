#pragma once
#include "Entity.h"

class Life : public Entity
{
public:
	Life(int id);
	~Life();

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
	virtual void borrarContenido() override;
	virtual std::string getClassName() { return "Life"; };
};

