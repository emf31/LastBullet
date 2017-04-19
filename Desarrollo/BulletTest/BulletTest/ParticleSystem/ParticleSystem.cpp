#include "particleSystem.h"
#include "ExplosionParticleSystem.h"

void ParticleSystem::createExplosion(Vec3<float> &position) {
	if (explosion == nullptr) {
		explosion = new ExplosionParticleSystem(position);
	} else {
		explosion->createParticleSystem(position);
	}
}

void ParticleSystem::update(Time time) {
	if (explosion != nullptr) {
		explosion->update(time);
	}
}

void ParticleSystem::render() {
	if (explosion != nullptr) {
		explosion->render();
	}
}

void ParticleSystem::apagar() {
	delete explosion;
}
