#include "Input.h"

void Input::key_callbackImpl(GLFWwindow * window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);


	if (action == GLFW_PRESS)
		keys[key] = true;
	else if (action == GLFW_RELEASE)
		keys[key] = false;
}

void Input::mouse_callbackImpl(GLFWwindow * window, double xpos, double ypos) {
	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;
	
	sm.camaraActiva->ProcessMouseMovement(xoffset, yoffset);
}

void Input::scroll_callbackImpl(GLFWwindow * window, double xoffset, double yoffset) {
	sm.camaraActiva->ProcessMouseScroll(yoffset);
}

void Input::Do_Movement(GLfloat deltaTime) {
	// Camera controls
	if (keys[GLFW_KEY_W])
		sm.camaraActiva->ProcessKeyboard(FORWARD, deltaTime);
	if (keys[GLFW_KEY_S])
		sm.camaraActiva->ProcessKeyboard(BACKWARD, deltaTime);
	if (keys[GLFW_KEY_A])
		sm.camaraActiva->ProcessKeyboard(LEFT, deltaTime);
	if (keys[GLFW_KEY_D])
		sm.camaraActiva->ProcessKeyboard(RIGHT, deltaTime);
	if (keys[GLFW_KEY_R]) {
		rotarDerecha = true;
	}
	else {
		rotarDerecha = false;
	}
		
	if (keys[GLFW_KEY_T]) {
		rotarIzquierda = true;
	}
	else {
		rotarIzquierda = false;
	}

}
