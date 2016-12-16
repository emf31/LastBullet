
#include "RenderState.h"
#include <math.h>
#include "Otros/Clock.hpp"
#include "Otros/Time.hpp"

RenderState::RenderState()
{
}


RenderState::~RenderState()
{
}

void RenderState::update(Time elapsedTime)
{
	m_posPrev = m_posNew;
	m_posNew += m_Velocity * elapsedTime.asSeconds();
}

/*void RenderState::updateRender(float interpolation, SceneNode *m_nodo)
{
	
	m_renderPos = Vec3<float>(
		m_posPrev.getX() + ((m_posNew.getX() - m_posPrev.getX()) * interpolation),
		m_posPrev.getY() + ((m_posNew.getY() - m_posPrev.getY()) * interpolation),
		m_posPrev.getZ() + ((m_posNew.getZ() - m_posPrev.getZ()) * interpolation)
	);

	float shortest_angleX = ((((int)(m_rotationNew.getX() - m_rotationPrev.getX()) % 360) + 540) % 360) - 180;   //Calculamos el angulo más corto en el caso de que
	float shortest_angleY = ((((int)(m_rotationNew.getY() - m_rotationPrev.getY()) % 360) + 540) % 360) - 180;
	float shortest_angleZ = ((((int)(m_rotationNew.getZ() - m_rotationPrev.getZ()) % 360) + 540) % 360) - 180;

	m_renderRotation.setX(m_rotationPrev.getX() + (shortest_angleX)* interpolation);
	m_renderRotation.setY(m_rotationPrev.getY() + (shortest_angleY)* interpolation);
	m_renderRotation.setZ(m_rotationPrev.getZ() + (shortest_angleZ)* interpolation);


	m_nodo->setPosition(m_renderPos);
	m_nodo->setRotation(m_renderRotation);

}*/

void RenderState::updatePositions(Vec3<float> position)
{
	m_posPrev = m_posNew;
	m_posNew = position;
}

void RenderState::updateRotations(Vec3<float> rotation)
{
	m_rotationPrev = m_rotationNew;
	m_rotationNew = rotation;
}


void RenderState::setRotation(Vec3<float> rotation)
{
	m_rotationNew = rotation;
	m_rotationPrev = rotation;
}

void RenderState::setPosition(Vec3<float> position) {
	m_posNew = position;
	m_posPrev = position;
}

void RenderState::setVelocity(Vec3<float> velocity) {
	m_Velocity = velocity;
}
void RenderState::setRenderPos(Vec3<float> renderPos)
{
	m_renderPos = renderPos;
}
void RenderState::setRenderRot(Vec3<float> renderRot)
{
	m_renderRotation = renderRot;
}
Vec3<float> RenderState::getRotation()
{
	return Vec3<float>();
}
Vec3<float> RenderState::getPosition() {
	return m_posNew;
}
Vec3<float> RenderState::getVelocity() {
	return m_Velocity;
}
Vec3<float> RenderState::getRenderPos()
{
	return m_renderPos;;
}
Vec3<float> RenderState::getRenderRotation()
{
	return m_renderRotation;
}

