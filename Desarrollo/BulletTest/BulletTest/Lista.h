#pragma once

#include "Nodo.h"
#include "Entities/Weapons/Weapon.h";

typedef Nodo *pnodo;

class Lista
{
public:
	Lista();
	~Lista();

	void insertar(int tipo);
	bool ListaVacia() { return actual == NULL; }
	void Mostrar();
	void Siguiente();
	void Anterior();
	bool Actual() { return actual != NULL; }
	Weapon valorActual() { return *actual->valor; }
	void dispararArmaActual();

private:
	pnodo actual;
};

