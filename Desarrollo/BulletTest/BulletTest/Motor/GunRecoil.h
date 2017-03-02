#pragma once
#include <GraphicEngine.h>
#include <vec3.hpp>
#include <Clock.hpp>
#include <stack>


class GunRecoil {
public:
	GunRecoil(Camera& camera);
	~GunRecoil() {};
	void RecoilOn();
	bool isRecoilActive() { return m_recoilActive; }
	void update(bool isShooting);

private:
	Camera& m_camera;
	Clock m_recoilTime;
	bool m_recoilActive;
	std::stack<Vec3<float>> randomStack;
	Vec3<float> randomAcumulativo;

	Vec3<float> velocidad ;
	Vec3<float> xfin;
	Vec3<float> xini;
	float tiempo;

};
