#pragma once

#include <Time.hpp>
#include <Entity.h>

class Player : public Entity
{
public:
	Player(const std::string& name, RakNet::RakNetGUID guid);
	~Player();

	

private:
	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void borrarContenido() override;
	virtual std::string getClassName() { return "Player"; };

};

