#include "DebugMarks.h"
#include <GraphicEngine.h>
#include <EntityManager.h>
#include <Color4f.h>

//Creates a billboard in the position of the entity
DebugMarks::DebugMarks(Character* ent, float yOffset) : 
	m_ent(ent), 
	mIsActive(false), 
	entYOffset(yOffset), 
	losedConnection(seconds(5)), 
	EntActive(-1, NULL)
{
	
}

DebugMarks::~DebugMarks()
{
}

void DebugMarks::inicializar()
{
	//mlastSyncPacket.restart();
}

void DebugMarks::update(Time elapsedTime)
{	
	Vec3<float> ent_pos = m_ent->getRenderState()->getPosition();
	Vec3<float> prev_rot = m_renderState.getRotation();
	prev_rot.addY(5);

	m_renderState.updatePositions(Vec3<float>(ent_pos.getX(), ent_pos.getY() + entYOffset, ent_pos.getZ()));
	m_renderState.updateRotations(prev_rot);

	//If is equal to Time::Zero show billboard indefinetily
	if (m_lifetime == Time::Zero) {
		return;
	}

	//If we are not visible for 5 seconds, billboard shows red
	if (mlastSyncPacket.getElapsedTime() >= losedConnection) {
		activateMark(Time::Zero,Vec3<float>(0.1,0.9,0.2));
	}

	if (mbillboardTime.getElapsedTime() >= m_lifetime) {
		m_nodo->setVisible(false);
	}
}

void DebugMarks::handleInput()
{
}

void DebugMarks::cargarContenido()
{
	//Creates a billboard as parent of entity passed to contrsuctor
	//parent node, size, relposition, color
	m_nodo = GraphicEngine::i().createNode(m_ent->getRenderPosition(), Vec3<float>(1, 1, 1));
	m_nodo->setVisible(false);
}

void DebugMarks::borrarContenido()
{
}

void DebugMarks::handleMessage(const Message & message)
{
}

bool DebugMarks::handleTrigger(TriggerRecordStruct * Trigger)
{
	return false;
}

void DebugMarks::setPosition(const Vec3<float>& vec)
{
}

//Activates billboard during time passed
void DebugMarks::activateMark(Time time, const Vec3<float> color)
{

	//Change the color to billboard 
	m_nodo->setColor(Vec3<float>(0.32, 0.92, 0.32));

	//Turn visible
	m_nodo->setVisible(true);

	m_lifetime = time;

	mbillboardTime.restart();
}

void DebugMarks::syncRecevied()
{
	mlastSyncPacket.restart();
}
