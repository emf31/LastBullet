#include "GroupEntity.h"

GroupEntity::GroupEntity(const std::string &name, int id) : EntActive(id, NULL, name) 
{
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
	for (std::unordered_set<EntActive*>::iterator it = lista_entities.begin(); it != lista_entities.end(); ++it) {
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
	for(std::unordered_set<EntActive*>::iterator it = lista_entities.begin(); it != lista_entities.end(); ++it){
		(*it)->handleTrigger(Trigger);
	}

	return true;
}

std::string GroupEntity::getClassName()
{
	return "GroupEntity";
}

void GroupEntity::setPosition(const Vec3<float>& pos)
{
}

//Añade una entity, si esta duplicada no la añade
void GroupEntity::addEntity(EntActive * ent)
{
	lista_entities.insert(ent);
}

void GroupEntity::removeEntity(EntActive * ent)
{
	lista_entities.erase(ent);
}

void GroupEntity::addEntityList(std::list<EntActive*> entityList) {
	for (auto i = entityList.begin(); i != entityList.end(); ++i) {
		addEntity(*i);
	}
}
