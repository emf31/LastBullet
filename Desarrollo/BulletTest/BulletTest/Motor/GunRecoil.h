#pragma once
#include <GraphicEngine.h>
#include <vec3.hpp>
#include <Clock.hpp>


class GunRecoil {
public:
	GunRecoil(Camera& camera);
	~GunRecoil() {};
	void RecoilOn();
	bool isRecoilActive() { return m_recoilActive; }
	void update();

private:
	Camera& m_camera;
	Clock m_recoilTime;
	bool m_recoilActive;

};
