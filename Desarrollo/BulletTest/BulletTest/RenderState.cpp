#include "stdafx.h"
#include "RenderState.h"


RenderState::RenderState()
{
}


RenderState::~RenderState()
{
}

void RenderState::setPosition(Vec3<float> position) {
	posPrev = position;
	posNew = position;
}

void RenderState::setVelocity(Vec3<float> velocity) {
	Velocity = velocity;
}
Vec3<float> RenderState::getPosition() {
	return posNew;
}
Vec3<float> RenderState::getVelocity() {
	return Velocity;
}

void RenderState::update(Time elapsedTime)
{
	posPrev = posNew;
	posNew += Velocity * elapsedTime.asSeconds();
}

void RenderState::updateRender(float interpolation, ISceneNode *m_nodo)
{
	renderPos=Vec3<float>(
	posPrev.getX() + ((posNew.getX() - posPrev.getX()) * interpolation),
	posPrev.getY() + ((posNew.getY() - posPrev.getY()) * interpolation),
	posPrev.getZ() + ((posNew.getZ() - posPrev.getZ()) * interpolation)		
	);

	m_nodo->setPosition(vector3df(renderPos.getX(), renderPos.getY(), renderPos.getZ()));

}
