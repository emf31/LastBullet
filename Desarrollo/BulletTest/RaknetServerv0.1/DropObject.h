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
	virtual void borrarContenido() override;
	virtual std::string getClassName() { return "DropObject"; };
};