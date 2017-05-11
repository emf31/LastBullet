#pragma once

#include <vec3.hpp>
#include <Time.hpp>
#include <Clock.hpp>
#include <RenderState.h>

#include <Entity.h>

#include <SceneNode.h>

#include <memory>
#include <TriggerRecordStruct.h>



class EntActive : public Entity
{
public:
	

	EntActive(int id, std::shared_ptr<SceneNode> nodo, const std::string& name = "", RakNet::RakNetGUID guid = RakNet::UNASSIGNED_RAKNET_GUID);
	virtual ~EntActive();

	void updateRender(float interpolation);
	Vec3<float> getRenderPosition();

	RenderState* getRenderState() { return &m_renderState; }

	virtual void inicializar() = 0;
	virtual void update(Time elapsedTime) = 0;
	virtual void handleInput() = 0;
	virtual void cargarContenido() = 0;
	virtual void borrarContenido() = 0;
	virtual void handleMessage(const Message& message) = 0;
	virtual bool handleTrigger(TriggerRecordStruct* Trigger) = 0;
	virtual std::string getClassName() = 0;
	virtual void setPosition(const Vec3<float>& vec) = 0;
	virtual Vec3<float> getPosition() override { return m_renderState.getPosition(); }


protected:

	RenderState m_renderState;
	
private:

	
};

