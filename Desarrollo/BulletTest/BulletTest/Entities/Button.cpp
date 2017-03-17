#include "Button.h"
#include <TriggerSystem.h>
#include <PhysicsEngine.h>

Button::Button(std::shared_ptr<BasicSceneNode> nodo, const std::string & name, EnumTriggerType type, int id):EntPassive(id, nodo, name) {
	m_triggerType = type;
}

Button::~Button() {
}

void Button::inicializar() {
	TriggerSystem::i().RegisterTrigger(m_triggerType, 10, m_id, getPosition(), 5, Time::Zero, false);
	m_ghostTrigger = PhysicsEngine::i().createSphereShape(this, 5);
}

void Button::update(Time elapsedTime) {
}

void Button::handleInput() {
}

void Button::cargarContenido() {

}

void Button::borrarContenido() {
}

void Button::handleMessage(const Message & message) {
}

bool Button::handleTrigger(TriggerRecordStruct * Trigger) {

	return false;
}

std::string Button::getClassName() {
	return std::string();
}

void Button::setPosition(const Vec3<float>& pos)
{
	m_position = pos;
	m_nodo->setPosition(pos);
}
