#include "TEntity.h"
#include "TNode.h"
#include "TTransform.h"



TEntity::TEntity() :
	miNodo(nullptr),
	transTraslacion(nullptr),
	transEscalado(nullptr),
	transRotacion(nullptr) 
{
}


TEntity::~TEntity() {
}



void TEntity::endDraw() {
}

TNode * TEntity::getMiNodo() {
	return miNodo;
}

int TEntity::getID() {
	return entityID;
}

void TEntity::setID(int id) {
	entityID = id;
}

void TEntity::setMiNodo(TNode * nodo) {
	miNodo = nodo;
}

void TEntity::addChild(TEntity * ent) {
	TNode* nuevoHijo = ent->getMiNodo();
	TNode* padre = ent->getMiNodo()->getParentNode();
	
	while (padre->getParentNode() != nullptr && padre->getMyNodeEntityID() == entityID) {
		//haciendo esta asignacion si luego cambio padre tambien se cambia nuevoHijo? al ser un puntero que apunta a otro puntero
		nuevoHijo = nuevoHijo->getParentNode();
		padre = padre->getParentNode();
	}
	padre->removeChild(nuevoHijo);
	//NOTA PARA NUESTROS FUTUROS YO: porque en setParent se pasa el padre de miNodo y no directamente miNodo
	//pues es bien sencillo, simplemente pork estamos en un nodo malla que son a los que se tiene acceso desde el juego
	//y el padre no puede ser el nodo malla sino la transformacion de la que depende este nodo malla , es decir, el padre del nodo malla. De nada futuro yo ;)
	nuevoHijo->setParentNode(miNodo->getParentNode());
	miNodo->getParentNode()->addChild(nuevoHijo);

}




void TEntity::removeChild(TEntity * ent)
{
	miNodo->removeChild(ent->getMiNodo());
}

void TEntity::setVisible(bool b) { miNodo->setVisible(b); transTraslacion->getMiNodo()->setVisible(b); }

bool TEntity::isVisible() const { return miNodo->isVisible(); }

void TEntity::setTransformacionRotacion(TTransform * rot) {
	transRotacion = rot;
}

void TEntity::setTransformacionEscalado(TTransform * esc) {
	transEscalado = esc;
}

void TEntity::setTransformacionTraslacion(TTransform * tras) {
	transTraslacion = tras;
}