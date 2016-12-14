#include "GroupEntity.h"

GroupEntity::GroupEntity(const std::string &name) : Entity(-1, NULL, name) 
{
	isGroup = true;
}

GroupEntity::~GroupEntity()
{
}

void GroupEntity::inicializar()
{
}

void GroupEntity::update(Time elapsedTime)
{
	Vec3<float> pos_media;
	float x = 0, y = 0, z = 0;
	for (std::unordered_set<Entity*>::iterator it = lista_entities.begin(); it != lista_entities.end(); ++it) {
		x += (*it)->getRenderState()->getPosition().getX();
		y += (*it)->getRenderState()->getPosition().getY();
		z += (*it)->getRenderState()->getPosition().getZ();
	}

	pos_media.setX(x / lista_entities.size());
	pos_media.setY(y / lista_entities.size());
	pos_media.setZ(z / lista_entities.size());

	m_renderState.setPosition(pos_media);
	//Calculamos el radio que engloba a todas las entities
	radio = Vec3<float>::getDistance(pos_media, (*lista_entities.begin())->getRenderState()->getPosition());
}

void GroupEntity::handleInput()
{
}

void GroupEntity::cargarContenido()
{
}

void GroupEntity::borrarContenido()
{
	lista_entities.clear();
}

void GroupEntity::handleMessage(const Message & message)
{
}

bool GroupEntity::handleTrigger(TriggerRecordStruct* Trigger)
{
	//Hay que llamar al handle trigger de todas las entities de tu lista
	for(std::unordered_set<Entity*>::iterator it = lista_entities.begin(); it != lista_entities.end(); ++it){
		(*it)->handleTrigger(Trigger);
	}

	return true;
}

std::string GroupEntity::getClassName()
{
	return "GroupEntity";
}

//Añade una entity, si esta duplicada no la añade
void GroupEntity::addEntity(Entity * ent)
{
	lista_entities.insert(ent);
}

void GroupEntity::removeEntity(Entity * ent)
{
	lista_entities.erase(ent);
}
