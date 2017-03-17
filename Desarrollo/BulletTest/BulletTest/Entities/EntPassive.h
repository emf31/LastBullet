#pragma once

#include <vec3.hpp>
#include <Time.hpp>

#include <Entity.h>

#include <memory>
#include <TriggerRecordStruct.h>



class EntPassive : public Entity
{
public:


	EntPassive(int id, std::shared_ptr<SceneNode> nodo, const std::string& name = "", RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	virtual ~EntPassive();

	virtual void inicializar() = 0;
	virtual void update(Time elapsedTime) = 0;
	virtual void handleInput() = 0;
	virtual void cargarContenido() = 0;
	virtual void borrarContenido() = 0;
	virtual void handleMessage(const Message& message) = 0;
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) = 0;
	virtual std::string getClassName() = 0;
	virtual void setPosition(const Vec3<float>& vec) = 0;
	virtual Vec3<float> getPosition() override { return m_position; }


protected:

	Vec3<float> m_position;
	Vec3<float> m_rotation;
	Vec3<float> m_scale;

private:


};