#include "RenderState.h"
#include <math.h>
#include "..\Otros\Clock.hpp"
#include "..\Otros\Time.hpp"
#include "math.h"

RenderState::RenderState()
{
	m_MaxVelocity = 30;
	m_Acceleration = 150;
	m_SpeedFactor = 1;
	m_rotated = 0;
}


RenderState::~RenderState()
{
}

void RenderState::update(Time elapsedTime)
{
	m_posPrev = m_posNew;
	m_posNew += m_Velocity * elapsedTime.asSeconds();
}

void RenderState::updateRender(float interpolation, SceneNode *m_nodo)
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

	//printf("giro en realdidad %f\n", m_renderRotation);


	m_nodo->setPosition(m_renderPos);
	m_nodo->setRotation(m_renderRotation);

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
	m_rotated += rotation.getY();
}

void RenderState::updateVelocity(float elapsedTime)
{
	Vec3<float> VelocityAccelerated = Vec3<float>(
		(m_Velocity.getX() + m_Direction.getX()*m_Acceleration*elapsedTime),
		(m_Velocity.getY() + 0 * elapsedTime),
		(m_Velocity.getZ() + m_Direction.getZ()*m_Acceleration*elapsedTime));

	//float VelocityAcceleratedTotal = sqrt(pow(VelocityAccelerated.getX(), 2.0) + pow(VelocityAccelerated.getY(), 2.0) + pow(VelocityAccelerated.getZ(), 2.0));

	if (m_Acceleration>0) {
		if (abs(VelocityAccelerated.getX()) < m_MaxVelocity) {
			m_Velocity.setX(VelocityAccelerated.getX());
		}
		if (abs(VelocityAccelerated.getZ()) < m_MaxVelocity) {
			m_Velocity.setZ(VelocityAccelerated.getZ());
		}
	}
	else {
		m_Velocity = Vec3<float>(0, 0, 0);
		m_Direction = Vec3<float>(0, 0, 0);
	}
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
void RenderState::setAccelerating(bool accelerating)
{
	if (accelerating && m_Acceleration < 0) {
		m_Acceleration = m_Acceleration*-1; //se pone a acelerar y se pone la aceleracion en negativo para frenar
	}
	if (!accelerating && m_Acceleration > 0) {
		m_Acceleration = m_Acceleration*-1; //deja de frenar y se pone la aceleracion en positiva para acelerar
	}
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