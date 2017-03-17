
#include "EntActive.h"
#include <RenderState.h>
#include "EntityManager.h"


EntActive::EntActive(int id, std::shared_ptr<SceneNode> nodo, const std::string& name, RakNet::RakNetGUID guid) :
	Entity(id, nodo, name, guid), m_renderState()
{

	if (m_nodo) {
		m_renderState.setPosition(m_nodo->getPosition());
	}
	else {
		m_renderState.setPosition(Vec3<float>(0,0,0));
	}

	//cada entity que se crea llama a entity manager para registrarse
	EntityManager::i().registerEntityActive(this);

}


EntActive::~EntActive()
{
}

void EntActive::updateRender(float interpolation)
{
	m_renderState.updateRender(interpolation, m_nodo);
}

Vec3<float> EntActive::getRenderPosition()
{
	return m_renderState.getRenderPos();
}







