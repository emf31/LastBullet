#pragma once

#include "Entities/Weapons/Weapon.h";
#include "Entities/Weapons/Asalto.h"
#include "Entities/Weapons/Pistola.h"
#include "Entities/Weapons/RocketLauncher.h"

#define LANZACOHETES 10
#define ASALTO 11
#define PISTOLA 12

class Nodo
{
public:
	Nodo(int tipo, Nodo *next = NULL, Nodo *pre = NULL)
	{
		if (tipo == LANZACOHETES) {
			valor = new RocketLauncher();
		}
		else if (tipo == ASALTO) {
			valor = new Asalto();
		}
		else if (tipo == PISTOLA) {
			valor = new Pistola();
		}
		else {
			valor = new Weapon();
		}
	};
	~Nodo();

private:
	Weapon* valor;
	Nodo *siguiente; 
	Nodo* anterior;

	friend class Lista;

};
 
