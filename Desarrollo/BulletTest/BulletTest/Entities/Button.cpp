#include "Button.h"
#include "../TriggerSystem.h"


Button::Button(std::shared_ptr<BasicSceneNode> nodo, const std::string & name):Entity(-1, nodo, name) {

}

Button::~Button() {
}

void Button::setPosition(Vec3<float>& pos) {
	m_renderState.setPosition(pos);
}

void Button::inicializar() {
	TriggerSystem::i().RegisterTrigger(EnumTriggerType::kTrig_Explosion, 10, m_id, m_renderState.getPosition(), 5, Time::Zero, false);

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
