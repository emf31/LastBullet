#pragma once

#include "../Entities/Weapons/Weapon.h"
#include "../Entities/Weapons/Asalto.h"
#include "../Entities/Weapons/Pistola.h"
#include "../Entities/Weapons/RocketLauncher.h"

#define LANZACOHETES 10
#define ASALTO 11
#define PISTOLA 12
#define SNIPER 13

class Nodo
{
public:
	Nodo(Weapon* v, Nodo *next = NULL, Nodo *pre = NULL) : valor(v), siguiente(next), anterior(pre) {}
	
	~Nodo() {};

	void borrar() {
		delete this;
	}

private:
	Weapon* valor;
	Nodo *siguiente; 
	Nodo* anterior;

	friend class Lista;

};
 
