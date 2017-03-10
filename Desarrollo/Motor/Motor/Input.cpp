#include "Input.h"
#include "TCamera.h"

void Input::key_callbackImpl(GLFWwindow * window, int key, int scancode, int action, int mode) {
	/*if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);*/
	if (action == GLFW_PRESS)
		keys[key] = PRESSED;
	else if (action == GLFW_RELEASE)
		keys[key] = RELEASED;
}

void Input::mouse_callbackImpl(GLFWwindow * window, double xpos, double ypos) {
	if (firstMouse) {
		lastX = (GLfloat)xpos;
		lastY = (GLfloat)ypos;
		firstMouse = false;
	}

	GLfloat xoffset = (GLfloat)xpos - lastX;
	GLfloat yoffset = lastY - (GLfloat)ypos;

	lastX = (GLfloat)xpos;
	lastY = (GLfloat)ypos;

	mouse.X = (int)xoffset;
	mouse.Y = (int)yoffset;

	sm.camaraActiva->ProcessMouseMovement(xoffset, yoffset);
}

void Input::scroll_callbackImpl(GLFWwindow * window, double xoffset, double yoffset) {

	sm.camaraActiva->ProcessMouseScroll((GLfloat)yoffset);
}

void Input::Do_Movement(GLfloat deltaTime) {
	// Camera controls
	if (keys[GLFW_KEY_W] == PRESSED)
		sm.camaraActiva->ProcessKeyboard(FORWARD, deltaTime);
	if (keys[GLFW_KEY_S] == PRESSED)
		sm.camaraActiva->ProcessKeyboard(BACKWARD, deltaTime);
	if (keys[GLFW_KEY_A] == PRESSED)
		sm.camaraActiva->ProcessKeyboard(LEFT, deltaTime);
	if (keys[GLFW_KEY_D] == PRESSED)
		sm.camaraActiva->ProcessKeyboard(RIGHT, deltaTime);
}

int Input::getMouseX() {
	return mouse.X;
}

int Input::getMouseY() {
	return mouse.Y;
}

bool Input::leftMouseReleased() {
	if (mouseButtonState[0] == RELEASED)
		return true;
	else
		return false;
}

bool Input::leftMousePressed() {
	if (mouseButtonState[0] == PRESSED)
		return true;
	else
		return false;
}

bool Input::leftMouseUp() {
	if (mouseButtonState[0] == PRESSED || mouseButtonState[0] == DOWN)
		return false;
	else
		return true;
}

bool Input::leftMouseDown() {
	if (mouseButtonState[0] == PRESSED || mouseButtonState[0] == DOWN)
		return true;
	else
		return false;
}

bool Input::middleMouseReleased() {
	if (mouseButtonState[1] == RELEASED)
		return true;
	else
		return false;
}

bool Input::middleMouseUp() {
	if (mouseButtonState[1] == RELEASED || mouseButtonState[1] == UP)
		return true;
	else
		return false;
}

bool Input::middleMousePressed() {
	if (mouseButtonState[1] == PRESSED)
		return true;
	else
		return false;
}

bool Input::middleMouseDown() {
	if (mouseButtonState[1] == PRESSED || mouseButtonState[1] == DOWN)
		return true;
	else
		return false;
}

bool Input::rightMouseReleased() {
	if (mouseButtonState[2] == RELEASED)
		return true;
	else
		return false;
}

bool Input::rightMouseUp() {
	if (mouseButtonState[2] == RELEASED || mouseButtonState[2] == UP)
		return true;
	else
		return false;
}

bool Input::ightMousePressed() {
	if (mouseButtonState[2] == PRESSED)
		return true;
	else
		return false;
}

bool Input::rightMouseDown() {
	if (mouseButtonState[2] == PRESSED || mouseButtonState[2] == DOWN)
		return true;
	else
		return false;
}

bool Input::keyPressed(unsigned char keycode) {
	if (keys[keycode] == PRESSED)
		return true;
	else
		return false;
}

bool Input::keyDown(unsigned char keycode) {
	if (keys[keycode] == DOWN || keys[keycode] == PRESSED)
		return true;
	else
		return false;
}

bool Input::keyUp(unsigned char keycode) {
	if (keys[keycode] == UP || keys[keycode] == RELEASED)
		return true;
	else
		return false;
}

bool Input::keyReleased(unsigned char keycode) {
	if (keys[keycode] == RELEASED)
		return true;
	else
		return false;
}