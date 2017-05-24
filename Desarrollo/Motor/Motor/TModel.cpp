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
	//visible = true;
	setModelColor(1.0f, 1.0f, 1.0f);
}

TModel::~TModel() {
	
}

void TModel::beginDraw() {
	//if (visible) {

		
		const glm::mat4& view = sm.getViewMatrix();
		const glm::mat4& projection = sm.getProjectionMatrix();
		glm::mat4& model = sm.getMatrizActual();
		glm::mat4 modelview = projection * view * model;
		glm::mat4 normMatrix = glm::transpose(glm::inverse(glm::mat3(model)));

		
		sm.shaderGeometria->Use();
		
		glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "normMatrix"), 1, GL_FALSE, glm::value_ptr(normMatrix));
		glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "modelview"), 1, GL_FALSE, glm::value_ptr(modelview));
		glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(glGetUniformLocation(sm.shaderGeometria->Program, "material.objectColor"), m_r, m_g, m_b);

		//Dibujamos el modelo
		m_meshGroup->draw();
			
	//}

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

void TModel::setOrientation(const Vec3<float>& orientation)
{

	//m_node->setOrientation(orientation);

	glm::mat4 m_matrix = glm::mat4();
	glm::vec3 column1;
	glm::vec3 column2;
	glm::vec3 column3;
	glm::vec3 up = glm::vec3(0, 1, 0);
	glm::vec3 direction = glm::vec3(orientation.getX(), orientation.getY(), orientation.getZ());

	glm::vec3 xaxis = glm::cross(up, direction);
	xaxis = glm::normalize(xaxis);

	glm::vec3 yaxis = glm::cross(direction, xaxis);

	yaxis = glm::normalize(yaxis);

	column1.x = xaxis.x;
	column1.y = yaxis.x;
	column1.z = direction.x;

	column2.x = xaxis.y;
	column2.y = yaxis.y;
	column2.z = direction.y;

	column3.x = xaxis.z;
	column3.y = yaxis.z;
	column3.z = direction.z;

	m_matrix[0][0] = column1.x;
	m_matrix[1][0] = column1.y;
	m_matrix[2][0] = column1.z;

	m_matrix[0][1] = column2.x;
	m_matrix[1][1] = column2.y;
	m_matrix[2][1] = column2.z;

	m_matrix[0][2] = column3.x;
	m_matrix[1][2] = column3.y;
	m_matrix[2][2] = column3.z;

	setRotationMatrix(m_matrix);

}