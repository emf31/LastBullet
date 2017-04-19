#pragma once
#include <GLEW/glew.h>
#include <SPARK.h>
#include <SPARK_GL.h>
#include <SOIL/SOIL.h>
#include <Entity.h>


class ExplosionParticleSystem;

class ParticleSystem {

public:
	
	static ParticleSystem& i() {
		static ParticleSystem singleton;
		return singleton;
	}
	void inicializar() {
		// Sets the update step
		SPK::System::setClampStep(true, 0.1f);			// clamp the step to 100 ms
		SPK::System::useAdaptiveStep(0.001f, 0.01f);		// use an adaptive step from 1ms to 10ms (1000fps to 100fps)
	}
	void createExplosion(Vec3<float> &position);
	
	void update(Time time);

	void render();

	void apagar();

private:
	ParticleSystem() {

	}

	~ParticleSystem() {

	}

	ExplosionParticleSystem *explosion;

};

