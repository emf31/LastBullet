#pragma once
//GLEW
#define GLEW_STATIC
#include <GLEW/glew.h>

#include <GLFW/glfw3.h>
#include "Camera.h"
class Input {
public:

	// Camera
	Camera camera;

	bool keys[1024];
	GLfloat lastX = 400, lastY = 300;
	bool firstMouse = true;

	static Input& getInstance() { // Singleton
		static Input instance;
		return instance;
	}
	static void mouseButtonCallback(int key, int action){
		getInstance().mouseButtonCallbackImpl(key, action);
	}

	void mouseButtonCallbackImpl(int key, int action){

	}
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
		getInstance().key_callbackImpl(window, key, scancode, action, mode);
	}
	void  key_callbackImpl(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
		getInstance().mouse_callbackImpl(window, xpos, ypos);
	}
	void mouse_callbackImpl(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
		getInstance().scroll_callbackImpl(window, xoffset, yoffset);
	}
	void scroll_callbackImpl(GLFWwindow* window, double xoffset, double yoffset);

	void Do_Movement(GLfloat deltaTime);
private:
	Input(void)
	{
	}

	Input(Input const&);
};

