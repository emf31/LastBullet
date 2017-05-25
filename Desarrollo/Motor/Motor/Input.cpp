#include "Input.h"
#include "TCamera.h"

Input::Input() : sm(SceneManager::i()) {

}


void Input::endEventProcess() {
	//Keyboard Key States
	for (std::size_t i = 0; i < 348; i++)
	{
		if (keys[i] == RELEASED) {
			keys[i] = UP;
			
		}
			

		if (keys[i] == PRESSED) {
			keys[i] = DOWN;
		}
			
	}

	//Mouse Button States
	for (std::size_t i = 0; i < 3; i++)
	{
		if (mouseButtonState[i] == RELEASED)
			mouseButtonState[i] = UP;

		if (mouseButtonState[i] == PRESSED)
			mouseButtonState[i] = DOWN;
	}

	textInput = 0;

}



void Input::key_callbackImpl(GLFWwindow * window, int key, int scancode, int action, int mode) {
	
	// si alguna tecla se presiona
	if (action == GLFW_PRESS)
	{
		//Si la tecla no estaba ya pulsada
		if (keys[key] != DOWN)
			keys[key] = PRESSED; // Set to Pressed
		else
			// si ya estaba en down la ponemos a down
			keys[key] = DOWN; // Set to Down
	}
	else if(action == GLFW_RELEASE)
	{
		// if the key is down
		if (keys[key] != UP) {
			keys[key] = RELEASED; // Set to Released
		}
			
	}
	else if (action == GLFW_REPEAT) {
		
		keys[key] = DOWN;
	}
	
	if (key == GLFW_KEY_ENTER && mode == GLFW_MOD_ALT) {
		if (glfwGetWindowMonitor(window))
		{
			glfwSetWindowMonitor(window, NULL,
				0, *SceneManager::i().screenWidth,
				0, *SceneManager::i().screenHeight, 60);
		}
		else
		{
			GLFWmonitor* monitor = glfwGetPrimaryMonitor();
			if (monitor)
			{
				glfwSetWindowMonitor(window, monitor, 0, 0, *SceneManager::i().screenWidth, *SceneManager::i().screenHeight, 60);
			}
		}
	}

	/*if (action == GLFW_PRESS)
		keys[key] = PRESSED;
	else if (action == GLFW_RELEASE)
		keys[key] = RELEASED;*/
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

	mouse.X = (unsigned int)lastX;
	mouse.Y = (unsigned int)lastY;

	
	if (sm.camaraActiva != nullptr) {
		sm.camaraActiva->ProcessMouseMovement(xoffset, yoffset);
	}
}
	

void Input::mouseButtonCallbackImpl(int key, int action, int mods) {
	
	if (key == GLFW_MOUSE_BUTTON_1) {
		//std::cout << "MOUSE - " << key << " - " << action << std::endl;
		if (action == GLFW_PRESS) {
			mouseButtonState[0] = PRESSED;
			keys[key] = PRESSED;
		} else if(action == GLFW_RELEASE) {
			mouseButtonState[0] = RELEASED;
			keys[key] = RELEASED;
		}
	} else if (key == GLFW_MOUSE_BUTTON_2) {
		if(action == GLFW_PRESS) {
			mouseButtonState[2] = PRESSED;
			keys[key] = PRESSED;
		} else if (action == GLFW_RELEASE) {
			mouseButtonState[2] = RELEASED;
			keys[key] = RELEASED;
		}
	}
}

void Input::scroll_callbackImpl(GLFWwindow * window, double xoffset, double yoffset) {
	yScroll = (float)yoffset;
}

void Input::textInput_callbackImpl(GLFWwindow* window, unsigned int codePoint, int mods) {
	textInput = codePoint;
}

void Input::Do_Movement(GLfloat deltaTime) {
	
	//NOTA: esto no se usa en el juego, solo se usa para el debug del motor grafico sin usarse en ninguna aplicacion.
	if (keys[GLFW_KEY_W] == DOWN)
		sm.camaraActiva->ProcessKeyboard(FORWARD, deltaTime);
	if (keys[GLFW_KEY_S] == DOWN)
		sm.camaraActiva->ProcessKeyboard(BACKWARD, deltaTime);
	if (keys[GLFW_KEY_A] == DOWN)
		sm.camaraActiva->ProcessKeyboard(LEFT, deltaTime);
	if (keys[GLFW_KEY_D] == DOWN)
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

bool Input::rightMousePressed() {
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

bool Input::keyPressed(unsigned int keycode) {
	if (keys[keycode] == PRESSED)
		return true;
	else
		return false;
}

bool Input::keyDown(unsigned int keycode) {
	if (keys[keycode] == DOWN || keys[keycode] == PRESSED)
		return true;
	else
		return false;
}

bool Input::keyUp(unsigned int keycode) {
	if (keys[keycode] == UP || keys[keycode] == RELEASED)
		return true;
	else
		return false;
}

bool Input::keyReleased(unsigned int keycode) {
	if (keys[keycode] == RELEASED)
		return true;
	else
		return false;
}

unsigned int Input::getLastTextInput() {
	return textInput;
}