//GLEW
#define GLEW_STATIC
#include <GLEW\glew.h>

//GLFW
#include <GLFW\glfw3.h>

#include <iostream>

#include "EngineDevice.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


	//GLFWmonitor* prMonitor = glfwGetPrimaryMonitor();
	//Para pantalla completa se debe especificar un monitor (el principal en caso de haber mas de uno) en el cuarto parametro
	//de la funcion glfwCreateWindow()

	GLFWwindow* window = glfwCreateWindow(1280, 720, "TBA - OpenGL Viewer / Engine", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK){
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	int width, height;

	glfwGetFramebufferSize(window, &width, &height);
	glfwSetKeyCallback(window, key_callback);

	glViewport(0, 0, width, height);

	EngineDevice engine;
	SceneManager *sm = engine.getSceneManager();

	sm->addMesh(sm->getMesh("../resources/MeshPlayer.obj"));
	

	while (!glfwWindowShouldClose(window)){
		// Check and call events
		glfwPollEvents();

		//RENDER
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		sm->draw();

		//Swap Buffers
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	// When a user presses the escape key, we set the WindowShouldClose property to true, 
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}