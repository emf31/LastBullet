#pragma once

#include "TNode.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "Camera.h"

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
	TNode* addMesh(TModel* model);
	void draw(GLFWwindow* window);

	glm::mat4 projection;
	glm::mat4 view;

	Camera *camera_ptr;
	float *screenWidth, *screenHeight;
private:
	ResourceManager *rm;
	TNode scene;
	//Motor::GUI gui;

};
