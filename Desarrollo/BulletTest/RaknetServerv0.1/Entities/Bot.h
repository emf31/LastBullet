#pragma once

#include <Time.hpp>
#include <Entity.h>

class Bot : public Entity
{
public:
	Bot(const std::string& name, RakNet::RakNetGUID guid);
	~Bot();

private:

	// Heredado vía Entity
	virtual void inicializar() override;
	virtual void borrarContenido() override;
	virtual std::string getClassName() { return "Bot"; };
};

