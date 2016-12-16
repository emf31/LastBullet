#pragma once
#include "Otros/vec3.hpp"
#include "Otros/Time.hpp"


class RenderState
{
public:
	RenderState();
	~RenderState();

	////////////////////////////////////////
	//Setters
	////////////////////////////////////////
	void setRotation(Vec3<float> rotation);
	void setPosition(Vec3<float> position);
	void setVelocity(Vec3<float> velocity);
	void setRenderPos(Vec3<float> renderPos);
	void setRenderRot(Vec3<float> renderRot);

	////////////////////////////////////////
	//Getters
	////////////////////////////////////////
	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getVelocity();
	Vec3<float> getRenderPos();
	Vec3<float> getRenderRotation();

	////////////////////////////////////////
	//Update methods
	////////////////////////////////////////

	//Updatea posiciones y angulos
	void update(Time elapsedTime);
	//Calcula la posición y rotación de renderizado interpoladas
	//void updateRender(float interpolation, SceneNode *m_nodo);
	
	//Updatea las posiciones prev y new
	void updatePositions(Vec3<float> position);
	//Updatea las rotaciones prev y new
	void updateRotations(Vec3<float> rotation);

private:
	Vec3<float> m_Velocity;	//Vector velocidad

	Vec3<float> m_renderPos;
	Vec3<float>	m_renderRotation;

	Vec3<float> m_posPrev;
	Vec3<float> m_posNew;

	Vec3<float> m_rotationPrev;
	Vec3<float> m_rotationNew;

};

