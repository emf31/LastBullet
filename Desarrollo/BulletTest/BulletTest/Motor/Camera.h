#pragma once
#include "irrlicht.h"
#include <vec3.hpp>
#include "../Entities/Entity.h"

using namespace irr;
using namespace scene;

class Camera
{
public:
	Camera(ICameraSceneNode* camera);
	~Camera();

	void setTarget(Vec3<float> target);
	void setPosition(Vec3<float> position);

	Vec3<float> getTarget();
	Vec3<float> getPosition();

	//La camara sigue al nodo que le asignas
	void asignarEntity(Entity* ent);
	void update();

	Vec3<float> getRotation();

private:
	ICameraSceneNode* m_camera;
	Entity* m_entity;
};

