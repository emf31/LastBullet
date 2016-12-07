
#include "Entity.h"
#include "../Motor/RenderState.h"
#include "EntityManager.h"
#include "../Motor de Red/Cliente.h"


Entity::Entity(int id, std::shared_ptr<SceneNode> nodo, const std::string& name, RakNet::RakNetGUID guid) :
	m_id(id),
	m_nodo(nodo),
	m_name(name),
	m_renderState(),
	m_guid(guid)
{

	if (m_nodo) {
		m_renderState.setPosition(m_nodo.get()->getPosition());
		//std::cout << "soy el pringao de " << m_nodo.get()->getPosition().getX() << '\n';
	}
	else {
		//std::cout << "soy el pringao de " << name << '\n';
		m_renderState.setPosition(Vec3<float>(0,0,0));
	}

	//cada entity que se crea llama a entity manager para registrarse
	EntityManager::i().registerEntity(this);
}


Entity::~Entity()
{
}

void Entity::updateRender(float interpolation)
{
	m_renderState.updateRender(interpolation, m_nodo);
}

Vec3<float> Entity::getRenderPosition()
{
	return m_renderState.getRenderPos();
}

std::shared_ptr<SceneNode> Entity::getNode()
{
	return m_nodo;
}


void Entity::restaVida(float cantidad, RakNet::RakNetGUID guid)
{
	m_vida -= cantidad;
	if (m_vida <= 0) {
		isDying = true;
		relojMuerte.restart();
		if (Cliente::i().isConected()) {
			Cliente::i().playerMuerto();
			Cliente::i().actualizaTabla(guid, m_guid);
		}


		//TODO aqui no habria que llamar al resetALL ???
	}
}



