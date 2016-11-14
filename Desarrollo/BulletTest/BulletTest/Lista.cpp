#include "stdafx.h"
#include "Lista.h"


Lista::Lista()
{
}


Lista::~Lista()
{
}

void Lista::insertar(Weapon* v) {


	pnodo nodo;
	nodo = new Nodo(v);

	
	if (actual == NULL) {
		actual = nodo;
		actual->anterior = actual;
		actual->siguiente = actual;

	}
	else {
		nodo->siguiente = actual->siguiente;
		nodo->anterior = actual;
	}
	actual->siguiente->anterior = nodo;
	actual->siguiente = nodo;

}

void Lista::Mostrar() {
	pnodo nodo = actual;

	do {
		std::cout << nodo->valor->getClassName() << "-> ";
		nodo = nodo->siguiente;
	} while (nodo != actual);

	printf("\n");
}

void Lista::Siguiente() {
	if (actual) {
		actual = actual->siguiente;
	}
}

void Lista::Anterior() {
	if (actual) {
		actual = actual->anterior;
	}
}

