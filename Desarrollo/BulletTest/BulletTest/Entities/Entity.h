#pragma once

#include "../Otros/vec3.hpp"
#include "../Otros/Time.hpp"
#include "../Otros/Clock.hpp"
#include "../RenderState.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "../Motor/SceneNode.h"
#include "../Handlers/Message.h"

using namespace irr;
using namespace scene;

class Entity
{
public:
	Entity(int id, SceneNode* nodo, const std::string& name = "");
	virtual ~Entity();

	void updateRender(float interpolation);
	Vec3<float> getRenderPosition();

	RenderState* getRenderState() { return &m_renderState; }

	int getID() {
		return m_id;
	}
	void setID(int id) {
		m_id = id;
	}
	
	SceneNode* getNode();

	virtual void inicializar() = 0;
	virtual void update(Time elapsedTime) = 0;
	virtual void handleInput() = 0;
	virtual void cargarContenido() = 0;
	virtual void borrarContenido() = 0;
	virtual void handleMessage(const Message& message) = 0;

protected:
	int m_id;
	std::string m_name;
	SceneNode* m_nodo;
	RenderState m_renderState;

private:

	
};

