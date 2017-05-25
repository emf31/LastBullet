#include "TModelEstatico.h"
#include "ResourceManager.h"
#include <glm/gtc/type_ptr.hpp>
#include "SceneManager.h"


TModelEstatico::TModelEstatico(TMeshGroup* meshGroup, Vec3<float> posicion, Vec3<float> rotacion, Vec3<float> escala) : sm(SceneManager::i()) {

	m_meshGroup = meshGroup;
	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
	setModelColor(1.0f, 1.0f, 1.0f);

	setRotationXYZ(rotacion);
	glm::mat4 rot = transformMatrix.getMatrix();
	setScale(escala);
	glm::mat4 esc = transformMatrix.getMatrix();
	setPosition(posicion);
	glm::mat4 pos = transformMatrix.getMatrix();

	glm::mat4 model = pos * esc * rot ;
	transformMatrix.loadMatrix(model);
	
}

TModelEstatico::~TModelEstatico() {

}

void TModelEstatico::setTransformMatrix(Vec3<float> posicion, Vec3<float> rotacion, Vec3<float> escala)
{
	setRotationXYZ(rotacion);
	glm::mat4 rot = transformMatrix.getMatrix();
	setScale(escala);
	glm::mat4 esc = transformMatrix.getMatrix();
	setPosition(posicion);
	glm::mat4 pos = transformMatrix.getMatrix();

	glm::mat4 model = pos * esc * rot;
	transformMatrix.loadMatrix(model);
}

void TModelEstatico::beginDraw() {
	


	const glm::mat4& view = sm.getViewMatrix();
	const glm::mat4& projection = sm.getProjectionMatrix();
	glm::mat4& model = transformMatrix.getMatrix();
	glm::mat4 modelview = projection * view * model;


	sm.shaderGeometria->Use();

	glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "modelview"), 1, GL_FALSE, glm::value_ptr(modelview));
	glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniform3f(glGetUniformLocation(sm.shaderGeometria->Program, "material.objectColor"), m_r, m_g, m_b);

	
	m_meshGroup->draw();

	

}

void TModelEstatico::beginDrawSombras() {
	if (getMiNodo()->isVisible()) {

		const glm::mat4& viewproj = sm.getSunLight()->getLightSpaceMatrix();
		glm::mat4& model = transformMatrix.getMatrix();
		glm::mat4 Lightmvp = viewproj * model;
		sm.shaderSombras->Use();
		glUniformMatrix4fv(glGetUniformLocation(sm.shaderSombras->Program, "Lightmvp"), 1, GL_FALSE, glm::value_ptr(Lightmvp));
		//Dibujamos el modelo
		m_meshGroup->draw();

	}

}

void TModelEstatico::endDraw() {
}

void TModelEstatico::setPosition(Vec3<float> pos) {
	transformMatrix.setPosition(pos);
}


void TModelEstatico::setRotationXYZ(Vec3<float> rot) {
	transformMatrix.resetMatrix();
	transformMatrix.setRotationY(rot.getY());
	transformMatrix.setRotationX(rot.getX());
	transformMatrix.setRotationZ(rot.getZ());
}

void TModelEstatico::setScale(Vec3<float> esc) {
	transformMatrix.setScale(esc);
}

Vec3<float> TModelEstatico::getRotation() {
	return transformMatrix.getRotation();
}

Vec3<float> TModelEstatico::getPosition()
{
	return transformMatrix.getPosition();
}

Vec3<float> TModelEstatico::getScale()
{
	return transformMatrix.getScale();
}

glm::mat4 TModelEstatico::getMatrix()
{
	return transformMatrix.getMatrix();
}

//Llamar a esto desencadena que todos los hijos de este TModel se borren
void TModelEstatico::removeEntity()
{
	transRotacion->getMiNodo()->removeNode();
}
