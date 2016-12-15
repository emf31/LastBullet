#pragma once
#include "Entity.h"
#include <unordered_set>

class GroupEntity : public Entity {
public:
	GroupEntity(const std::string &name);
	~GroupEntity();

	// Heredado vía Entity
	virtual void inicializar() override;

	virtual void update(Time elapsedTime) override;

	virtual void handleInput() override;

	virtual void cargarContenido() override;

	virtual void borrarContenido() override;

	virtual void handleMessage(const Message & message) override;
	
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) override;

	virtual std::string getClassName() override;

	const std::unordered_set<Entity*>* getListaEntities() { return &lista_entities; }

	void addEntity(Entity* ent);

	void removeEntity(Entity* ent);
private:
	std::unordered_set<Entity*> lista_entities;
	float radio;
};