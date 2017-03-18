#pragma once
#include "EntActive.h"
#include <unordered_set>

class GroupEntity : public EntActive {
public:
	GroupEntity(const std::string &name,int id=-1);
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

	virtual void setPosition(const Vec3<float> &pos) override;

	const std::unordered_set<EntActive*>& getListaEntities() { return lista_entities; }

	void addEntity(EntActive* ent);

	void removeEntity(EntActive* ent);

	void addEntityList(std::list<EntActive*> entityList);

	float getRadius() const { return radio; }

private:
	std::unordered_set<EntActive*> lista_entities;
	float radio;
};