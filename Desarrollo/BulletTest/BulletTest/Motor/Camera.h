#pragma once
#include "irrlicht.h"
#include <vec3.hpp>
#include "../Entities/Entity.h"

class CameraShake;
class GunRecoil;
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

	void setInputReceiver(bool input) { m_camera->setInputReceiverEnabled(input);  }

	Vec3<float> getRotation();

	void addChild(std::shared_ptr<SceneNode> nodo) { 
		m_camera->addChild(nodo->getNodo()); 

	}
	void cameraShake();
	void cameraRecoil();
	void apuntar();
	void restablecerMira();


private:
	ICameraSceneNode* m_camera;
	
	Entity* m_entity;
	CameraShake* m_cameraShake;
	GunRecoil* m_GunRecoil;
	f32 defaultFOV;
	f32 defaultAspect;
	f32 zoomFOV;
};

