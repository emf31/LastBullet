#pragma once
#include <GraphicEngine.h>
#include <vec3.hpp>
#include <Clock.hpp>


class CameraShake {
public:
	CameraShake(Camera& camera);
	~CameraShake(){};
	void shakeOn();
	bool isShakeActive() { return m_shakeActive; }
	void update();

private:
	Camera& m_camera;
	Clock m_shakeTime;
	bool m_shakeActive;
	float m_amplitud;
	float m_frecuencia;
	float posicion;

};

