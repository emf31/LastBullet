#include "TModel.h"
#include "ResourceManager.h"
#include <glm/gtc/type_ptr.hpp>
#include "SceneManager.h"


TModel::TModel(TMeshGroup* meshGroup) : sm(SceneManager::i()) {
	/*Shader* shader;
	if (*shaderPath) {
		shader = ResourceManager::i().getShader(shaderPath);
	} else {
		shader = ResourceManager::i().getShader("assets/model_loading.vs", "assets/model_loading.frag");
	}*/


	m_meshGroup = meshGroup;

	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
	visible = true;
}

TModel::~TModel() {
	
}

void TModel::beginDraw() {
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
		m_meshGroup->beginDraw();
			
	}

}

void TModel::endDraw() {
	//std::cout << u8"Adiós" << std::endl;
	//TEntity::endDraw();
}

void TModel::setPosition(Vec3<float> pos) {
	transTraslacion->setPosition(pos);
}

void TModel::updatePosition(Vec3<float> pos)
{
	transTraslacion->updatePosition(pos);
}

void TModel::setRotation(Vec3<float> rot) {
	transRotacion->setRotationDirection(rot);
}

void TModel::setRotationX(float angu) {
	transRotacion->setRotationX(angu);
}

void TModel::setRotationY(float angu) {
	transRotacion->setRotationY(angu);
}

void TModel::setRotationZ(float angu) {
	transRotacion->setRotationZ(angu);
}

void TModel::setScale(Vec3<float> esc) {
	transEscalado->setScale(esc);
}

void TModel::setTransformacionRotacion(TTransform * rot) {
	transRotacion = rot;
}

void TModel::setTransformacionEscalado(TTransform * esc) {
	transEscalado = esc;
}

void TModel::setTransformacionTraslacion(TTransform * tras) {
	transTraslacion = tras;
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
