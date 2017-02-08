#pragma once

#include "Nodo.h"
#include "../Entities/Weapons/Weapon.h"

typedef Nodo *pnodo;

class Lista
{
public:
	Lista();
	~Lista();

	void insertar(Weapon* v);
	bool ListaVacia() { return actual == NULL; }
	void Mostrar();
	bool Equipar(std::string arma);
	void Siguiente();
	void Anterior();
	bool Actual() { return actual != NULL; }
	bool Buscar(std::string str);
	Weapon* valorActual() { return actual->valor; }
	void Vaciar();

	//void armaMasDeseada(double dist);

private:
	pnodo actual;
};

