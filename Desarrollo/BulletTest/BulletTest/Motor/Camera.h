#pragma once
#include <vec3.hpp>
#include <Character.h>
#include <Engine/TCamera.h>

class CameraShake;
class GunRecoil;


class Camera
{
public:
	Camera(TCamera* camera, const std::string &nombre);
	~Camera();

	void setTarget(Vec3<float> target);
	void setPosition(Vec3<float> position);

	Vec3<float> getTarget();
	Vec3<float> getVecRight();
	Vec3<float> getPosition();

	Vec3<float> getVectorDirection() { return m_camera->getVectorDireccion(); }
	
	//La camara sigue al nodo que le asignas
	void asignarEntity(Character* ent);
	void update();

	void setInputReceiver(bool input) { m_camera->setInputEnable(input);  }

	Vec3<float> getRotation();

	void addChild(std::shared_ptr<SceneNode> nodo) { 
		m_camera->addChild(nodo->getEntityNode()); 

	}
	void cameraShake();
	void cameraRecoil();
	void apuntar();
	void restablecerMira();

	const std::string getNameCamera() const{
		return m_pName;
	}

	TCamera* getCameraNode() const{
		return m_camera;
	}

	void setRotationX(float angulo);
	void setRotationY(float angulo);
	void setRotationZ(float angulo);
	void setDir(Vec3<float>& dir) { m_camera->setRotationDir(dir); }




private:

	std::string m_pName;
	TCamera* m_camera;
	
	Character* m_entity;
	CameraShake* m_cameraShake;
	GunRecoil* m_GunRecoil;
	float defaultFOV;
	float defaultAspect;
	float zoomFOV;
};

