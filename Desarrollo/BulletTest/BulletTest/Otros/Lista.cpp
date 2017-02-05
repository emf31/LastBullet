
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

bool Lista::Buscar(std::string arma) {
	pnodo nodo = actual;

	do {
		if (arma == nodo->valor->getClassName()) {
			return true;
		}
		nodo = nodo->siguiente;
	} while (nodo != actual);

	return false;

}

void Lista::Siguiente() {
	if (actual) {
		actual->valor->setEquipada(false);
		actual = actual->siguiente;
		actual->valor->setEquipada(true);
		actual->valor->resetRecarga();

	}
}

void Lista::Anterior() {
	if (actual) {
		actual->valor->setEquipada(false);
		actual = actual->anterior;
		actual->valor->setEquipada(true);
		actual->valor->resetRecarga();
	}
}

void Lista::Vaciar() {

	while (actual != NULL) {
		if (actual->siguiente == actual) {//Solo hay un arma en la lista
			delete actual;
			actual = NULL;
		}
		else {//Hay mas de un arma en la lista
			pnodo nodo;
			nodo = actual->siguiente;
			actual->siguiente->anterior = actual->anterior;//Modificamos los nodos siguientes y anteriores para que la lista no se desestabilice
			actual->anterior->siguiente = actual->siguiente;
			delete actual;
			actual = nodo;
		}
	}

}

