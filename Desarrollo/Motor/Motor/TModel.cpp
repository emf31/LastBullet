#include "TModel.h"
#include "ResourceManager.h"
#include <glm/gtc/type_ptr.hpp>
#include "SceneManager.h"


TModel::TModel(TMeshGroup* meshGroup) : sm(SceneManager::i()) {
	m_meshGroup = meshGroup;

	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
	setModelColor(1.0f, 1.0f, 1.0f);
}

TModel::~TModel() {
	
}

void TModel::beginDraw() {


		
		const glm::mat4& view = sm.getViewMatrix();
		const glm::mat4& projection = sm.getProjectionMatrix();
		glm::mat4& model = sm.getMatrizActual();
		glm::mat4 modelview = projection * view * model;
		

		
		sm.shaderGeometria->Use();
		glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "modelview"), 1, GL_FALSE, glm::value_ptr(modelview));
		glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(glGetUniformLocation(sm.shaderGeometria->Program, "material.objectColor"), m_r, m_g, m_b);

		//Dibujamos el modelo
		m_meshGroup->draw();
			

}

void TModel::beginDrawSombras() {
	if (getMiNodo()->isVisible()) {

		const glm::mat4& viewproj = sm.getSunLight()->getLightSpaceMatrix();
		glm::mat4& model = sm.getMatrizActual();
		glm::mat4 Lightmvp = viewproj * model;
		sm.shaderSombras->Use();
		glUniformMatrix4fv(glGetUniformLocation(sm.shaderSombras->Program, "Lightmvp"), 1, GL_FALSE, glm::value_ptr(Lightmvp));
		//Dibujamos el modelo
		m_meshGroup->draw();


	}

}

void TModel::endDraw() {
}

void TModel::setPosition(Vec3<float> pos) {
	transTraslacion->setPosition(pos);
}

void TModel::updatePosition(Vec3<float> pos)
{
	transTraslacion->updatePosition(pos);
}


void TModel::setRotationXYZ(Vec3<float> rot) {
	transRotacion->resetMatrix();
	transRotacion->setRotationY(rot.getY());
	transRotacion->setRotationX(rot.getX());
	transRotacion->setRotationZ(rot.getZ());
}


void TModel::setScale(Vec3<float> esc) {
	transEscalado->setScale(esc);
}

void TModel::setRotationMatrix(glm::mat4 matRot)
{
	transRotacion->loadMatrix(matRot);
}

Vec3<float> TModel::getRotation() {
	return transRotacion->getRotation();
}

Vec3<float> TModel::getPosition()
{
	return transTraslacion->getPosition();
}

Vec3<float> TModel::getScale()
{
	return transEscalado->getScale();
}

glm::mat4 TModel::getRotationMatrix()
{
	return transRotacion->getMatrix();
}

glm::mat4 TModel::getPositionMatrix()
{
	return transTraslacion->getMatrix();
}

glm::mat4 TModel::getScaleMatrix()
{
	return transEscalado->getMatrix();
}

//Llamar a esto desencadena que todos los hijos de este TModel se borren
void TModel::removeEntity()
{
	transRotacion->getMiNodo()->removeNode();
}

