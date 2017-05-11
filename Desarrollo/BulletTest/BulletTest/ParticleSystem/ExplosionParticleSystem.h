#pragma once

#include <GLEW/glew.h>
#include <SPARK.h>
#include <SPARK_GL.h>
#include <SOIL/SOIL.h>

#include <Entity.h>
#include <Time.h>


class ExplosionParticleSystem {

public:
	ExplosionParticleSystem(Vec3<float> &position);
	~ExplosionParticleSystem();

	bool loadTexture(GLuint& index, const char* path, GLuint type, GLuint clamp, bool mipmap);

	void update(Time deltaTime);

	void render();

	// Creates the base system and returns its ID
	SPK::Ref<SPK::System> createParticleSystemBase(GLuint textureExplosion, GLuint textureFlash, GLuint textureSpark1, GLuint textureSpark2, GLuint textureWave);
	

	// Creates a particle system from the base system (CREA COPIA)
	SPK::Ref<SPK::System> createParticleSystem(Vec3<float> &position);


private:
	
	typedef std::list<SPK::Ref<SPK::System> > SystemList;
	SystemList particleSystems;
	SPK::Ref<SPK::System> baseSystem;

	GLuint textureExplosion;
	GLuint textureFlash;
	GLuint textureSpark1;
	GLuint textureSpark2;
	GLuint textureWave;

	// Draws the bounding box for a particle group
	void drawBoundingBox(const SPK::System& system);


	

};

