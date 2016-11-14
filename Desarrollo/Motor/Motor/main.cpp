//GLEW
#define GLEW_STATIC
#include <GLEW\glew.h>

//GLFW
#include <GLFW\glfw3.h>

#include <iostream>
using namespace std;
#include "EngineDevice.h"

#include "Shader.h"
#include "Camera.h"
#include "TModel.h"

#include "TModelNode.h"

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other Libs
#include <soil/SOIL.h>

// Properties
GLuint screenWidth = 1280, screenHeight = 720;
EngineDevice engine;


void Do_Movement();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

int main() {
	if (!engine.createEngineDevice(screenWidth, screenHeight, u8"Motor gráfico / Visor OpenGL - Last Bullet")) {
		return -1;
	}

	TModelNode modelNode;
	modelNode.setEntity();

	glfwSetKeyCallback(engine.getWindow(), key_callback);
	glfwSetCursorPosCallback(engine.getWindow(), mouse_callback);
	glfwSetScrollCallback(engine.getWindow(), scroll_callback);

	SceneManager *sm = engine.getSceneManager();
	Shader* shader;
	TNode* n = sm->addMesh(sm->getMesh("assets/nanosuit.obj"));
	//TModel * modelo = (TModel*)n->getEntity();
	//modelo->setShader();
	while (!glfwWindowShouldClose(engine.getWindow())){
		engine.updateCurrentFrame();

		glfwPollEvents();
		Do_Movement();
		//RENDER
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader = ResourceManager::i().getShader("assets/model_loading.vs");
		shader->Use();   // <-- Don't forget this one!

		
		/*glUniformMatrix4fv(glGetUniformLocation(shader->Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "view"), 1, GL_FALSE, glm::value_ptr(view));*/

		// Draw the loaded model
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));

		//ourModel.beginDraw(shader);

		sm->draw();
		// Swap the buffers
		glfwSwapBuffers(engine.getWindow());
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