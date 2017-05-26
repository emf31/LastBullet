#include "TAnimation.h"
#include "SceneManager.h"
TAnimation::TAnimation(TAnimationGroupMesh* meshGroup) : sm(SceneManager::i()), meshes(meshGroup)
{

	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
	visible = true;
	numAnims = 0;
	currentFrame = 0;
	timeFrame = seconds(0.175f);
}

TAnimation::~TAnimation()
{
	for (auto it = animMap.begin(); it != animMap.end(); it++) {
		delete it->second;
		it->second = nullptr;
	}

	animMap.clear();
}

void TAnimation::restartAnimation()
{
	currentFrame = 0;
	currentTime.restart();
	currentAnimation->finished = false;
	currentAnimation->paused = false;
}

void TAnimation::removeEntity()
{
	transRotacion->getMiNodo()->removeNode();
}

bool TAnimation::setAnimation(const std::string& animName,int desde, int hasta, bool loop)
{
	int tam = hasta - desde;
	if (tam < 0 || ((size_t)(tam + numAnims) >= meshes->vectorModelos.size())) {
		std::cout << "error, estas intentando poner mas animaciones que obj" << std::endl;
		return false;
	}

	CurrentAnim* curr = new CurrentAnim();

	curr->loop = loop;
	curr->finished = false;
	curr->paused = false;

	for (int i = desde; i <= hasta; i++) {
		curr->animacion.push_back(meshes->vectorModelos[i]);
	}


	animMap[animName] = curr;
	
	numAnims += curr->animacion.size();

	return true;
}



void TAnimation::setCurrentAnimation(const std::string & animName)
{
	currentAnimation = animMap[animName];
	currentFrame = 0;
	currentTime.restart();
	currentAnimation->finished = false;
}



void TAnimation::selectCurrentFrame()
{	
	if (!currentAnimation->finished && !currentAnimation->paused) {
		if (currentTime.getElapsedTime().asMilliseconds() > timeFrame.asMilliseconds()) {

			currentFrame++;
			currentTime.restart();

			if ((size_t)currentFrame >= currentAnimation->animacion.size()) {
				if (currentAnimation->loop) {
					currentFrame = 0;
				}
				else {
					currentAnimation->finished = true;
					currentFrame--;
				}
			}
		}
	}
	

}

void TAnimation::setFrameTime(Time time)
{
	timeFrame = time;
}

void TAnimation::beginDraw() {
	if (visible) {

		const glm::mat4& view = sm.getViewMatrix();
		const glm::mat4& projection = sm.getProjectionMatrix();
		glm::mat4& model = sm.getMatrizActual();

		glm::mat4 modelview = projection * view * model;


		sm.shaderGeometria->Use();

		glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "modelview"), 1, GL_FALSE, glm::value_ptr(modelview));
		glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//color
		glUniform3f(glGetUniformLocation(sm.shaderGeometria->Program, "objectColor"), m_r, m_g, m_b);

		//Dibujamos el modelo
		currentAnimation->animacion[currentFrame]->draw();
		selectCurrentFrame();

	}

}

void TAnimation::beginDrawSombras()
{
	if (visible) {

		const glm::mat4& viewproj = sm.getSunLight()->getLightSpaceMatrix();
		glm::mat4& model = sm.getMatrizActual();
		glm::mat4 Lightmvp = viewproj * model;
		sm.shaderSombras->Use();
		glUniformMatrix4fv(glGetUniformLocation(sm.shaderSombras->Program, "Lightmvp"), 1, GL_FALSE, glm::value_ptr(Lightmvp));
		//Dibujamos el modelo
		currentAnimation->animacion[currentFrame]->draw();
		selectCurrentFrame();

	}

}

void TAnimation::endDraw() {
}



void TAnimation::setPosition(Vec3<float> pos) {
	transTraslacion->setPosition(pos);
}

void TAnimation::updatePosition(Vec3<float> pos)
{
	transTraslacion->updatePosition(pos);
}

void TAnimation::setPaused(bool a)
{
	currentAnimation->paused = a;
}

void TAnimation::setRotationXYZ(Vec3<float> rot) {
	transRotacion->resetMatrix();
	transRotacion->setRotationY(rot.getY());
	transRotacion->setRotationX(rot.getX());
	transRotacion->setRotationZ(rot.getZ());
}



void TAnimation::setScale(Vec3<float> esc) {
	transEscalado->setScale(esc);
}



Vec3<float> TAnimation::getRotation() {
	return transRotacion->getRotation();
}

Vec3<float> TAnimation::getPosition()
{
	return transTraslacion->getPosition();
}

Vec3<float> TAnimation::getScale()
{
	return transEscalado->getScale();
}

glm::mat4 TAnimation::getRotationMatrix()
{
	return transRotacion->getMatrix();
}

glm::mat4 TAnimation::getPositionMatrix()
{
	return transTraslacion->getMatrix();
}

glm::mat4 TAnimation::getScaleMatrix()
{
	return transEscalado->getMatrix();
}
