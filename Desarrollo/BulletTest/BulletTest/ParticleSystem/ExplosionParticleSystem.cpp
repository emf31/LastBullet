#include "ExplosionParticleSystem.h"
#include <Util.h>
#include <SPARK_GL.h>

ExplosionParticleSystem::ExplosionParticleSystem(Vec3<float> &position) {

	if (!loadTexture(textureExplosion, "../media/particles/explosion.bmp", GL_ALPHA, GL_CLAMP, false))
		throw std::runtime_error("ERROR loading Explosion texture");


	if (!loadTexture(textureFlash, "../media/particles/flash.bmp", GL_RGB, GL_CLAMP, false))
		throw std::runtime_error("ERROR loading Explosion texture");


	if (!loadTexture(textureSpark1, "../media/particles/spark1.bmp", GL_RGB, GL_CLAMP, false))
		throw std::runtime_error("ERROR loading Explosion texture");

	if (!loadTexture(textureSpark2, "../media/particles/point.bmp", GL_ALPHA, GL_CLAMP, false))
		throw std::runtime_error("ERROR loading Explosion texture");

	if (!loadTexture(textureWave, "../media/particles/wave.bmp", GL_RGBA, GL_CLAMP, false))
		throw std::runtime_error("ERROR loading Explosion texture");

	baseSystem = createParticleSystemBase(textureExplosion, textureFlash, textureSpark1, textureSpark2, textureWave);
	createParticleSystem(position);
}


ExplosionParticleSystem::~ExplosionParticleSystem() {
	particleSystems.clear();
}

bool ExplosionParticleSystem::loadTexture(GLuint & index,const char * path, GLuint type, GLuint clamp, bool mipmap) {
	std::cout << "Loading particle texture: " << path << std::endl;
	glGenTextures(1, &index);
	int width, height;
	unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);

	glBindTexture(GL_TEXTURE_2D, index);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, clamp);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, clamp);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	//glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(image);

	return true;
}

void ExplosionParticleSystem::update(Time deltaTime) {
	SystemList::iterator it = particleSystems.begin();
	while (it != particleSystems.end()) {
		// Updates the particle systems
		if (!(*it)->updateParticles(deltaTime.asSeconds())) {
			// And erases its entry in the container
			it = particleSystems.erase(it);
		} else
			++it;
	}
}


// Creates the base system and returns its ID

inline SPK::Ref<SPK::System> ExplosionParticleSystem::createParticleSystemBase(GLuint textureExplosion, GLuint textureFlash, GLuint textureSpark1, GLuint textureSpark2, GLuint textureWave) {
	///////////////
	// Renderers //
	///////////////

	// smoke renderer
	SPK::Ref<SPK::GL::GLQuadRenderer> smokeRenderer = SPK::GL::GLQuadRenderer::create();
	smokeRenderer->setTexturingMode(SPK::TEXTURE_MODE_2D);
	smokeRenderer->setTexture(textureExplosion);
	smokeRenderer->setAtlasDimensions(2, 2); // uses 4 different patterns in the texture
	smokeRenderer->setBlendMode(SPK::BLEND_MODE_ALPHA);
	smokeRenderer->enableRenderingOption(SPK::RENDERING_OPTION_DEPTH_WRITE, false);
	smokeRenderer->setShared(true);

	// flame renderer
	SPK::Ref<SPK::GL::GLQuadRenderer> flameRenderer = SPK::GL::GLQuadRenderer::create();
	flameRenderer->setTexturingMode(SPK::TEXTURE_MODE_2D);
	flameRenderer->setTexture(textureExplosion);
	flameRenderer->setAtlasDimensions(2, 2);
	flameRenderer->setBlendMode(SPK::BLEND_MODE_ADD);
	flameRenderer->enableRenderingOption(SPK::RENDERING_OPTION_DEPTH_WRITE, false);
	flameRenderer->setShared(true);

	// flash renderer
	SPK::Ref<SPK::GL::GLQuadRenderer> flashRenderer = SPK::GL::GLQuadRenderer::create();
	flashRenderer->setTexturingMode(SPK::TEXTURE_MODE_2D);
	flashRenderer->setTexture(textureFlash);
	flashRenderer->setBlendMode(SPK::BLEND_MODE_ADD);
	flashRenderer->enableRenderingOption(SPK::RENDERING_OPTION_DEPTH_WRITE, false);
	flashRenderer->setShared(true);

	// spark 1 renderer
	SPK::Ref<SPK::GL::GLQuadRenderer> spark1Renderer = SPK::GL::GLQuadRenderer::create();
	spark1Renderer->setTexturingMode(SPK::TEXTURE_MODE_2D);
	spark1Renderer->setTexture(textureSpark1);
	spark1Renderer->setBlendMode(SPK::BLEND_MODE_ADD);
	spark1Renderer->enableRenderingOption(SPK::RENDERING_OPTION_DEPTH_WRITE, false);
	spark1Renderer->setOrientation(SPK::DIRECTION_ALIGNED); // sparks are oriented function of their velocity
	spark1Renderer->setScale(0.05f, 1.0f); // thin rectangles
	spark1Renderer->setShared(true);

	// spark 2 renderer
	SPK::Ref<SPK::GL::GLRenderer> spark2Renderer = SPK_NULL_REF;
	if (SPK::GL::GLPointRenderer::isPointSpriteSupported() && SPK::GL::GLPointRenderer::isWorldSizeSupported())// uses point sprite if possible
	{
		SPK::GL::GLPointRenderer::setPixelPerUnit(45.0f * M_PI / 180.f, 720.f);
		SPK::Ref<SPK::GL::GLPointRenderer> pointRenderer = SPK::GL::GLPointRenderer::create();
		pointRenderer->setType(SPK::POINT_TYPE_SPRITE);
		pointRenderer->setTexture(textureSpark2);
		pointRenderer->enableWorldSize(true);
		spark2Renderer = pointRenderer;
	} else {
		SPK::Ref<SPK::GL::GLQuadRenderer> quadRenderer = SPK::GL::GLQuadRenderer::create();
		quadRenderer->setTexturingMode(SPK::TEXTURE_MODE_2D);
		quadRenderer->setTexture(textureSpark2);
		spark2Renderer = quadRenderer;
	}
	spark2Renderer->setBlendMode(SPK::BLEND_MODE_ADD);
	spark2Renderer->enableRenderingOption(SPK::RENDERING_OPTION_DEPTH_WRITE, false);
	spark2Renderer->setShared(true);

	// wave renderer
	SPK::Ref<SPK::GL::GLQuadRenderer> waveRenderer = SPK::GL::GLQuadRenderer::create();
	waveRenderer->setTexturingMode(SPK::TEXTURE_MODE_2D);
	waveRenderer->setTexture(textureWave);
	waveRenderer->setBlendMode(SPK::BLEND_MODE_ALPHA);
	waveRenderer->enableRenderingOption(SPK::RENDERING_OPTION_DEPTH_WRITE, false);
	waveRenderer->enableRenderingOption(SPK::RENDERING_OPTION_ALPHA_TEST, true); // uses the alpha test
	waveRenderer->setAlphaTestThreshold(0.0f);
	waveRenderer->setOrientation(SPK::FIXED_ORIENTATION); // the orientation is fixed
	waveRenderer->lookVector.set(0.0f, 1.0f, 0.0f);
	waveRenderer->upVector.set(1.0f, 0.0f, 0.0f); // we dont really care about the up axis
	waveRenderer->setShared(true);

	//////////////
	// Emitters //
	//////////////

	// This zone will be used by several emitters
	SPK::Ref<SPK::Sphere> explosionSphere = SPK::Sphere::create(SPK::Vector3D(0.0f, 0.0f, 0.0f), 0.4f);

	// smoke emitter
	SPK::Ref<SPK::RandomEmitter> smokeEmitter = SPK::RandomEmitter::create();
	smokeEmitter->setZone(SPK::Sphere::create(SPK::Vector3D(0.0f, 0.0f, 0.0f), 0.6f), false);
	smokeEmitter->setTank(15);
	smokeEmitter->setFlow(-1);
	smokeEmitter->setForce(0.02f, 0.04f);

	// flame emitter
	SPK::Ref<SPK::NormalEmitter> flameEmitter = SPK::NormalEmitter::create();
	flameEmitter->setZone(explosionSphere);
	flameEmitter->setTank(15);
	flameEmitter->setFlow(-1);
	flameEmitter->setForce(0.06f, 0.1f);

	// flash emitter
	SPK::Ref<SPK::StaticEmitter> flashEmitter = SPK::StaticEmitter::create();
	flashEmitter->setZone(SPK::Sphere::create(SPK::Vector3D(0.0f, 0.0f, 0.0f), 0.1f));
	flashEmitter->setTank(3);
	flashEmitter->setFlow(-1);

	// spark 1 emitter
	SPK::Ref<SPK::NormalEmitter> spark1Emitter = SPK::NormalEmitter::create();
	spark1Emitter->setZone(explosionSphere);
	spark1Emitter->setTank(20);
	spark1Emitter->setFlow(-1);
	spark1Emitter->setForce(2.0f, 3.0f);
	spark1Emitter->setInverted(true);

	// spark 2 emitter
	SPK::Ref<SPK::NormalEmitter> spark2Emitter = SPK::NormalEmitter::create();
	spark2Emitter->setZone(explosionSphere);
	spark2Emitter->setTank(400);
	spark2Emitter->setFlow(-1);
	spark2Emitter->setForce(0.4f, 1.0f);
	spark2Emitter->setInverted(true);

	// wave emitter
	SPK::Ref<SPK::StaticEmitter> waveEmitter = SPK::StaticEmitter::create();
	waveEmitter->setZone(SPK::Point::create());
	waveEmitter->setTank(1);
	waveEmitter->setFlow(-1);

	////////////
	// Groups //
	////////////

	SPK::Ref<SPK::System> system = SPK::System::create(false); // not initialized as it is the base system
	system->setName("Explosion");

	SPK::Ref<SPK::ColorGraphInterpolator> colorInterpolator;
	SPK::Ref<SPK::FloatGraphInterpolator> paramInterpolator;

	// smoke group
	colorInterpolator = SPK::ColorGraphInterpolator::create();
	colorInterpolator->addEntry(0.0f, 0x33333300);
	colorInterpolator->addEntry(0.4f, 0x33333366, 0x33333399);
	colorInterpolator->addEntry(0.6f, 0x33333366, 0x33333399);
	colorInterpolator->addEntry(1.0f, 0x33333300);

	SPK::Ref<SPK::Group> smokeGroup = system->createGroup(15);
	smokeGroup->setName("Smoke");
	smokeGroup->setPhysicalRadius(0.0f);
	smokeGroup->setLifeTime(2.5f, 3.0f);
	smokeGroup->setRenderer(smokeRenderer);
	smokeGroup->addEmitter(smokeEmitter);
	smokeGroup->setColorInterpolator(colorInterpolator);
	smokeGroup->setParamInterpolator(SPK::PARAM_SCALE, SPK::FloatRandomInterpolator::create(0.3f, 0.4f, 0.5f, 0.7f));
	smokeGroup->setParamInterpolator(SPK::PARAM_TEXTURE_INDEX, SPK::FloatRandomInitializer::create(0.0f, 4.0f));
	smokeGroup->setParamInterpolator(SPK::PARAM_ANGLE, SPK::FloatRandomInterpolator::create(0.0f, M_PI * 0.5f, 0.0f, M_PI * 0.5f));
	smokeGroup->addModifier(SPK::Gravity::create(SPK::Vector3D(0.0f, 0.05f, 0.0f)));

	// flame group
	colorInterpolator = SPK::ColorGraphInterpolator::create();
	colorInterpolator->addEntry(0.0f, 0xFF8033FF);
	colorInterpolator->addEntry(0.5f, 0x995933FF);
	colorInterpolator->addEntry(1.0f, 0x33333300);

	paramInterpolator = SPK::FloatGraphInterpolator::create();
	paramInterpolator->addEntry(0.0f, 0.125f);
	paramInterpolator->addEntry(0.02f, 0.3f, 0.4f);
	paramInterpolator->addEntry(1.0f, 0.5f, 0.7f);

	SPK::Ref<SPK::Group> flameGroup = system->createGroup(15);
	flameGroup->setName("Flame");
	flameGroup->setLifeTime(1.5f, 2.0f);
	flameGroup->setRenderer(flameRenderer);
	flameGroup->addEmitter(flameEmitter);
	flameGroup->setColorInterpolator(colorInterpolator);
	flameGroup->setParamInterpolator(SPK::PARAM_SCALE, paramInterpolator);
	flameGroup->setParamInterpolator(SPK::PARAM_TEXTURE_INDEX, SPK::FloatRandomInitializer::create(0.0f, 4.0f));
	flameGroup->setParamInterpolator(SPK::PARAM_ANGLE, SPK::FloatRandomInterpolator::create(0.0f, M_PI * 0.5f, 0.0f, M_PI * 0.5f));

	// flash group
	paramInterpolator = SPK::FloatGraphInterpolator::create();
	paramInterpolator->addEntry(0.0f, 0.1f);
	paramInterpolator->addEntry(0.25f, 0.5f, 1.0f);

	SPK::Ref<SPK::Group> flashGroup = system->createGroup(3);
	flashGroup->setName("Flash");
	flashGroup->setLifeTime(0.2f, 0.2f);
	flashGroup->addEmitter(flashEmitter);
	flashGroup->setRenderer(flashRenderer);
	flashGroup->setColorInterpolator(SPK::ColorSimpleInterpolator::create(0xFFFFFFFF, 0xFFFFFF00));
	flashGroup->setParamInterpolator(SPK::PARAM_SCALE, paramInterpolator);
	flashGroup->setParamInterpolator(SPK::PARAM_ANGLE, SPK::FloatRandomInitializer::create(0.0f, 2.0f * M_PI));

	// spark 1 group
	SPK::Ref<SPK::Group> spark1Group = system->createGroup(20);
	spark1Group->setName("Spark 1");
	spark1Group->setPhysicalRadius(0.0f);
	spark1Group->setLifeTime(0.2f, 1.0f);
	spark1Group->addEmitter(spark1Emitter);
	spark1Group->setRenderer(spark1Renderer);
	spark1Group->setColorInterpolator(SPK::ColorSimpleInterpolator::create(0xFFFFFFFF, 0xFFFFFF00));
	spark1Group->setParamInterpolator(SPK::PARAM_SCALE, SPK::FloatRandomInitializer::create(0.1f, 0.2f));
	spark1Group->addModifier(SPK::Gravity::create(SPK::Vector3D(0.0f, -0.75f, 0.0f)));

	// spark 2 group
	SPK::Ref<SPK::Group> spark2Group = system->createGroup(400);
	spark2Group->setName("Spark 2");
	spark2Group->setGraphicalRadius(0.01f);
	spark2Group->setLifeTime(1.0f, 3.0f);
	spark2Group->addEmitter(spark2Emitter);
	spark2Group->setRenderer(spark2Renderer);
	spark2Group->setColorInterpolator(SPK::ColorRandomInterpolator::create(0xFFFFB2FF, 0xFFFFB2FF, 0xFF4C4C00, 0xFFFF4C00));
	spark2Group->setParamInterpolator(SPK::PARAM_MASS, SPK::FloatRandomInitializer::create(0.5f, 2.5f));
	spark2Group->addModifier(SPK::Gravity::create(SPK::Vector3D(0.0f, -0.1f, 0.0f)));
	spark2Group->addModifier(SPK::Friction::create(0.4f));

	// wave group
	paramInterpolator = SPK::FloatGraphInterpolator::create();
	paramInterpolator->addEntry(0.0f, 0.0f);
	paramInterpolator->addEntry(0.2f, 0.0f);
	paramInterpolator->addEntry(1.0f, 3.0f);

	SPK::Ref<SPK::Group> waveGroup = system->createGroup(1);
	waveGroup->setName("Wave");
	waveGroup->setLifeTime(0.8f, 0.8f);
	waveGroup->addEmitter(waveEmitter);
	waveGroup->setRenderer(waveRenderer);
	waveGroup->setColorInterpolator(SPK::ColorSimpleInterpolator::create(0xFFFFFF20, 0xFFFFFF00));
	waveGroup->setParamInterpolator(SPK::PARAM_SCALE, paramInterpolator);

	// Gets a pointer to the base
	return system;
}

void ExplosionParticleSystem::render() {

	// Renders all the particle systems
	SPK::GL::GLRenderer::saveGLStates();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthFunc(GL_LEQUAL);

	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);
	glDisable(GL_SCISSOR_TEST);
	glEnable(GL_TEXTURE_2D);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	for (SystemList::const_iterator it = particleSystems.begin(); it != particleSystems.end(); ++it) {
		//drawBoundingBox(**it);

		(*it)->renderParticles();
	}
	SPK::GL::GLRenderer::restoreGLStates();
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_SCISSOR_TEST);
	
}

// Creates a particle system from the base system

SPK::Ref<SPK::System> ExplosionParticleSystem::createParticleSystem(Vec3<float> &position) {
	// Creates a copy of the base system
	SPK::Ref<SPK::System> system = SPK::SPKObject::copy(baseSystem);

	SPK::Vector3D pos;

	pos.x = position.getX();
	pos.y = position.getY();
	pos.z = position.getZ();

	// Locates the system at the given position
	system->initialize();
	system->getTransform().setPosition(pos);
	system->updateTransform(); // updates the world transform of system and its children
	system->enableAABBComputation(false);

	particleSystems.push_back(system);
	return system;
}

// Draws the bounding box for a particle group

void ExplosionParticleSystem::drawBoundingBox(const SPK::System & system) {
	if (!system.isAABBComputationEnabled())
		return;

	const SPK::Vector3D& AABBMin = system.getAABBMin();
	const SPK::Vector3D& AABBMax = system.getAABBMax();

	glDisable(GL_TEXTURE_2D);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(AABBMin.x, AABBMin.y, AABBMin.z);
	glVertex3f(AABBMax.x, AABBMin.y, AABBMin.z);

	glVertex3f(AABBMin.x, AABBMin.y, AABBMin.z);
	glVertex3f(AABBMin.x, AABBMax.y, AABBMin.z);

	glVertex3f(AABBMin.x, AABBMin.y, AABBMin.z);
	glVertex3f(AABBMin.x, AABBMin.y, AABBMax.z);

	glVertex3f(AABBMax.x, AABBMax.y, AABBMax.z);
	glVertex3f(AABBMin.x, AABBMax.y, AABBMax.z);

	glVertex3f(AABBMax.x, AABBMax.y, AABBMax.z);
	glVertex3f(AABBMax.x, AABBMin.y, AABBMax.z);

	glVertex3f(AABBMax.x, AABBMax.y, AABBMax.z);
	glVertex3f(AABBMax.x, AABBMax.y, AABBMin.z);

	glVertex3f(AABBMin.x, AABBMin.y, AABBMax.z);
	glVertex3f(AABBMax.x, AABBMin.y, AABBMax.z);

	glVertex3f(AABBMin.x, AABBMin.y, AABBMax.z);
	glVertex3f(AABBMin.x, AABBMax.y, AABBMax.z);

	glVertex3f(AABBMin.x, AABBMax.y, AABBMin.z);
	glVertex3f(AABBMax.x, AABBMax.y, AABBMin.z);

	glVertex3f(AABBMin.x, AABBMax.y, AABBMin.z);
	glVertex3f(AABBMin.x, AABBMax.y, AABBMax.z);

	glVertex3f(AABBMax.x, AABBMin.y, AABBMin.z);
	glVertex3f(AABBMax.x, AABBMax.y, AABBMin.z);

	glVertex3f(AABBMax.x, AABBMin.y, AABBMin.z);
	glVertex3f(AABBMax.x, AABBMin.y, AABBMax.z);
	glEnd();
}

