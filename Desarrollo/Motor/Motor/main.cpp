//GLEW
#define GLEW_STATIC
#include <GLEW/glew.h>

//GLFW
#include <GLFW/glfw3.h>

#include <iostream>
using namespace std;
#include "EngineDevice.h"

#include "Shader.h"
#include "Camera.h"
#include "TModel.h"

// Other Libs
#include <soil/SOIL.h>

// Properties
GLuint screenWidth = 1280, screenHeight = 720;
EngineDevice engine;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void Do_Movement();
int main() {
	if (!engine.createEngineDevice(screenWidth, screenHeight, u8"Motor gráfico / Visor OpenGL - Last Bullet")) {
		return -1;
	}

	glfwSetKeyCallback(engine.getWindow(), key_callback);
	glfwSetCursorPosCallback(engine.getWindow(), mouse_callback);
	glfwSetScrollCallback(engine.getWindow(), scroll_callback);

	SceneManager *sm = engine.getSceneManager();
	TNode* n = sm->addMesh(sm->getMesh("assets/nanosuit.obj"));

	n->setPosition(Vec3<float>(0.0f, -1.75f, 0.0f));
	n->setScale(Vec3<float>(0.2f, 0.2f, 0.2f));

	while (!glfwWindowShouldClose(engine.getWindow())){
		engine.updateCurrentFrame();

		//TODO: Mover esto a otro sitio
		glfwPollEvents();
		Do_Movement();

		sm->draw(engine.getWindow());
	}

	glfwTerminate();
	return 0;
}


void Do_Movement() {
	// Camera controls
	if (engine.keys[GLFW_KEY_W])
		engine.camera.ProcessKeyboard(FORWARD, engine.deltaTime);
	if (engine.keys[GLFW_KEY_S])
		engine.camera.ProcessKeyboard(BACKWARD, engine.deltaTime);
	if (engine.keys[GLFW_KEY_A])
		engine.camera.ProcessKeyboard(LEFT, engine.deltaTime);
	if (engine.keys[GLFW_KEY_D])
		engine.camera.ProcessKeyboard(RIGHT, engine.deltaTime);
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS)
		engine.keys[key] = true;
	else if (action == GLFW_RELEASE)
		engine.keys[key] = false;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	if (engine.firstMouse) {
		engine.lastX = xpos;
		engine.lastY = ypos;
		engine.firstMouse = false;
	}

	GLfloat xoffset = xpos - engine.lastX;
	GLfloat yoffset = engine.lastY - ypos;

	engine.lastX = xpos;
	engine.lastY = ypos;

	engine.camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	engine.camera.ProcessMouseScroll(yoffset);
}