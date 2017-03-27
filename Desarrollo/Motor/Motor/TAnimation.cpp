#include "TAnimation.h"
#include "SceneManager.h"
TAnimation::TAnimation(TAnimationGroupMesh* meshGroup) : sm(SceneManager::i()), meshes(meshGroup)
{

	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
	visible = true;
	numAnims = 0;
	currentFrame = 0;
	timeFrame = seconds(0.175);
}

TAnimation::~TAnimation()
{
}

bool TAnimation::setAnimation(const std::string& animName,int desde, int hasta)
{
	int tam = hasta - desde;
	if (tam < 0 || (tam + numAnims >= meshes->vectorModelos.size())) {
		std::cout << "error, estas intentando poner mas animaciones que obj" << std::endl;
		return false;
	}
	std::vector<AnimationMesh*> animacion;
	for (int i = desde; i <= hasta; i++) {
		animacion.push_back(meshes->vectorModelos[i]);
	}

	//al salir del moto animacion se borra pork es local pero su contenido no ya que son punteros a TMeshGroup
	//la duda es si animMAp se iguala a animacion cuando se borre animacion que va a pasar? (creo que esta bien pork se hace una copia del vector pero no del contenido)
	animMap[animName] = animacion;
	
	numAnims += animacion.size();

	return true;
}

void TAnimation::setCurrentAnimation(const std::string & animName)
{
	//TODO mostrar mensaje de error si no encuentra la animacion que le pasas
	currentAnimation = animMap[animName];
	currentFrame = 0;
	currentTime.restart();
}



void TAnimation::selectCurrentFrame()
{	

	if (currentTime.getElapsedTime().asMilliseconds() > timeFrame.asMilliseconds()) {
		
		currentFrame++;
		currentTime.restart();
		if (currentFrame >= currentAnimation.size()) {
			currentFrame = 0;
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
		currentAnimation[currentFrame]->beginDraw();
		selectCurrentFrame();

	}

}

void TAnimation::endDraw() {
	//std::cout << u8"Adiós" << std::endl;
	//TEntity::endDraw();
}



void TAnimation::setPosition(Vec3<float> pos) {
	transTraslacion->setPosition(pos);
}

void TAnimation::updatePosition(Vec3<float> pos)
{
	transTraslacion->updatePosition(pos);
}

void TAnimation::setOrientation(Vec3<float> rot) {
	transRotacion->setRotationDirection(rot);
}

void TAnimation::setRotationXYZ(Vec3<float> rot) {

	transRotacion->setRotationY(rot.getY());
	transRotacion->setRotationX(rot.getX());
	transRotacion->setRotationZ(rot.getZ());
}

void TAnimation::setRotationRadians(Vec3<float> rot)
{
	transRotacion->setRotationRadians(rot);
}

void TAnimation::setRotation(Vec3<float> rot) {
	transRotacion->setRotationDegrees(rot);
}

void TAnimation::setRotationLeftHand(Vec3<float> rot)
{
	transRotacion->setRotationDegreesLeftHand(rot);
}

void TAnimation::setScale(Vec3<float> esc) {
	transEscalado->setScale(esc);
}

void TAnimation::setTransformacionRotacion(TTransform * rot) {
	transRotacion = rot;
}

void TAnimation::setTransformacionEscalado(TTransform * esc) {
	transEscalado = esc;
}

void TAnimation::setTransformacionTraslacion(TTransform * tras) {
	transTraslacion = tras;
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
	return transRotacion->getRotationMatrix();
}

glm::mat4 TAnimation::getPositionMatrix()
{
	return transTraslacion->getPositionMatrix();
}

glm::mat4 TAnimation::getScaleMatrix()
{
	return transEscalado->getScaleMatrix();
}
