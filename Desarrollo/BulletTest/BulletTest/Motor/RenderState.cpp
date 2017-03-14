#include "RenderState.h"
#include <math.h>
#include "../Otros\Clock.hpp"
#include "../Otros\Time.hpp"
#include "math.h"

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

void RenderState::updateRender(float interpolation, std::shared_ptr<SceneNode> m_nodo)
{
	
	m_renderPos = Vec3<float>(
		m_posPrev.getX() + ((m_posNew.getX() - m_posPrev.getX()) * interpolation),
		m_posPrev.getY() + ((m_posNew.getY() - m_posPrev.getY()) * interpolation),
		m_posPrev.getZ() + ((m_posNew.getZ() - m_posPrev.getZ()) * interpolation)
	);

	float shortest_angleX = float(((((int)(m_rotationNew.getX() - m_rotationPrev.getX()) % 360) + 540) % 360) - 180);  
	float shortest_angleY = float(((((int)(m_rotationNew.getY() - m_rotationPrev.getY()) % 360) + 540) % 360) - 180);
	float shortest_angleZ = float(((((int)(m_rotationNew.getZ() - m_rotationPrev.getZ()) % 360) + 540) % 360) - 180);

	m_renderRotation.setX(m_rotationPrev.getX() + (shortest_angleX)* interpolation);
	m_renderRotation.setY(m_rotationPrev.getY() + (shortest_angleY)* interpolation);
	m_renderRotation.setZ(m_rotationPrev.getZ() + (shortest_angleZ)* interpolation);


	if (m_nodo != NULL) {
		m_nodo->setPosition(m_renderPos);
		//cambiar rotaciones aqui
		m_nodo->setRotationXYZ(Vec3<float>(m_renderRotation.getX(), m_renderRotation.getY(), m_renderRotation.getZ()));
	}


}

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

void RenderState::updateVelocity(float elapsedTime, Vec3<float> direccion)
{
	m_posPrev = m_posNew;
	m_posNew += direccion*elapsedTime;
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
void RenderState::setDirection(Vec3<float> direction)
{
	m_Direction = direction;
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
	return m_rotationNew;
}
Vec3<float> RenderState::getPosition() {
	return m_posNew;
}
Vec3<float> RenderState::getVelocity() {
	return m_Velocity;
}
Vec3<float> RenderState::getRenderPos()
{
	return m_renderPos;
}
Vec3<float> RenderState::getRenderRotation()
{
	return m_renderRotation;
}

