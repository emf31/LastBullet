#pragma once

#include "TNode.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "Camera.h"
#include "enum.h"

#include "GUI.h"

#include <GLEW/glew.h>
//GLFW
#include <GLFW/glfw3.h>

class SceneManager {
public:
	SceneManager();
	~SceneManager();

	//void getTexture(std::string path);
	TModel* getMesh(std::string path, Shader* shader=nullptr);
	void draw(GLFWwindow* window);
	TModel* crearNodoMalla(TModel * model);
	TNode* crearNodoTransformacion();
	TNode* crearNodoTraslacion(TNode* nodoPadre);
	TNode* crearNodoRotacion(TNode* nodoPadre);
	TNode* crearNodoEscalado(TNode* nodoPadre);
	TNode* crearNodoLuz();
	TNode* crearNodoCamara();

	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 m_matrizActual;
	Camera *camera_ptr;
	float *screenWidth, *screenHeight;
private:
	ResourceManager *rm;
	TNode* scene;
	//Motor::GUI gui;

};
