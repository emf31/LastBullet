#include "stdafx.h"
#include "RenderState.h"
#include <math.h>


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

void RenderState::updateRender(float interpolation, ISceneNode *m_nodo)
{
	float *result;
	m_renderPos = Vec3<float>(
		m_posPrev.getX() + ((m_posNew.getX() - m_posPrev.getX()) * interpolation),
		m_posPrev.getY() + ((m_posNew.getY() - m_posPrev.getY()) * interpolation),
		m_posPrev.getZ() + ((m_posNew.getZ() - m_posPrev.getZ()) * interpolation)
	);

	result = fixAngle(m_rotationNew.getX(), m_rotationPrev.getX());
	m_rotationNew.setX(result[0]);
	m_rotationPrev.setX(result[1]);

	result = fixAngle(m_rotationNew.getY(), m_rotationPrev.getY());
	m_rotationNew.setY(result[0]);
	m_rotationPrev.setY(result[1]);

	result = fixAngle(m_rotationNew.getZ(), m_rotationPrev.getZ());
	m_rotationNew.setZ(result[0]);
	m_rotationPrev.setZ(result[1]);

	result = nullptr;

	m_renderRotation = Vec3<float>(
		m_rotationPrev.getX() + ((m_rotationNew.getX() - m_rotationPrev.getX()) * interpolation),
		m_rotationPrev.getY() + ((m_rotationNew.getY() - m_rotationPrev.getY()) * interpolation),
		m_rotationPrev.getZ() + ((m_rotationNew.getZ() - m_rotationPrev.getZ()) * interpolation)
	);
	
	Vec3<float> final = 
		Vec3<float>(
			Wrap(m_renderRotation.getX(), 0, 360), 
			Wrap(m_renderRotation.getY(), 0, 360), 
			Wrap(m_renderRotation.getZ(), 0, 360)
		);
	/*float shortest_angleX = ((((int)(m_rotationNew.getX() - m_rotationPrev.getX()) % 360) + 540) % 360) - 180;   //Calculamos el angulo más corto en el caso de que
	float shortest_angleY = ((((int)(m_rotationNew.getY() - m_rotationPrev.getY()) % 360) + 540) % 360) - 180;
	float shortest_angleZ = ((((int)(m_rotationNew.getZ() - m_rotationPrev.getZ()) % 360) + 540) % 360) - 180;

	m_renderRotation.setX(m_rotationPrev.getX() + (shortest_angleX)* interpolation);
	m_renderRotation.setY(m_rotationPrev.getY() + (shortest_angleY)* interpolation);
	m_renderRotation.setZ(m_rotationPrev.getZ() + (shortest_angleZ)* interpolation);*/

	/*float dot = Vec3<float>::dotProduct(m_rotationPrev, m_rotationNew);

	dot = clamp(dot, -1.0f, 1.0f);

	float theta = acos(dot)*interpolation;

	Vec3<float> RelativeVec = m_rotationNew - m_rotationPrev*dot;

	RelativeVec.normalise();

	Vec3<float> final = ((m_rotationPrev*cos(theta)) + (RelativeVec*sin(theta)));*/

	m_nodo->setPosition(vector3df(m_renderPos.getX(), m_renderPos.getY(), m_renderPos.getZ()));
	//m_nodo->setRotation(vector3df(final.getX(), final.getY(), final.getZ()));
	m_nodo->setRotation(vector3df(m_renderRotation.getX(), m_renderRotation.getY(), m_renderRotation.getZ()));

}

float RenderState::Wrap(float value, float lower, float upper)
{
	float rangeZero = upper - lower;

	if (value >= lower && value <= upper)
		return value;

	return ((int)value % (int)rangeZero) + lower;
}

float* RenderState::fixAngle(float end, float start) {
	static float result[2];
	float difference = abs(end - start);

	if (difference > 180)
	{
		// We need to add on to one of the values.
		if (end > start)
		{
			// We'll add it on to start...
			start += 360;
		}
		else
		{
			// Add it on to end.
			end += 360;
		}
	}
	result[0] = end;
	result[1] = start;
	
	return result;
}
float RenderState::clamp(float x, float a, float b)
{
	return x < a ? a : (x > b ? b : x);
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

