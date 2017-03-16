#pragma once
//GLEW
#include <GLEW/glew.h>

#include <GLFW/glfw.h>
#include "SceneManager.h"

class Input {
private:
	enum keyStatesENUM { UP, DOWN, PRESSED, RELEASED };

	enum processStateENUM { STARTED, ENDED };

	keyStatesENUM keys[1024];

	processStateENUM processState; // STARTED = handling events, ENDED = not handling events



public:
	bool rotarDerecha;
	bool rotarIzquierda;

	keyStatesENUM mouseButtonState[2]; //Left(0), Middle(1), Right(2)

	struct Mouse {
		int X;
		int Y;
		float wheel; //wheel is how far the wheel has moved
	};

	Mouse mouse;
	GLfloat lastX = 400, lastY = 300;
	bool firstMouse = true;

	static Input& i() { // Singleton
		static Input instance;
		return instance;
	}
	static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
		i().mouseButtonCallbackImpl(button, action, mods);
	}

	void mouseButtonCallbackImpl(int button, int action, int mods);

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
		i().key_callbackImpl(window, key, scancode, action, mode);
	}
	
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
		i().mouse_callbackImpl(window, xpos, ypos);
	}
	
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
		i().scroll_callbackImpl(window, xoffset, yoffset);
	}

	void endEventProcess();

	void Do_Movement(GLfloat deltaTime);

	int getMouseX();

	int getMouseY();

	bool leftMouseReleased();

	bool leftMousePressed();

	bool leftMouseUp();

	bool leftMouseDown();

	bool middleMouseReleased();

	bool middleMouseUp();

	bool middleMousePressed();

	bool middleMouseDown();

	bool rightMouseReleased();

	bool rightMouseUp();

	bool rightMousePressed();

	bool rightMouseDown();

	bool keyPressed(unsigned char keycode);

	bool keyDown(unsigned char keycode);

	bool keyUp(unsigned char keycode);

	bool keyReleased(unsigned char keycode);

private:
	Input(void) {

	}

	Input(Input const&);
	SceneManager& sm = SceneManager::i();

	void mouse_callbackImpl(GLFWwindow* window, double xpos, double ypos);
	void scroll_callbackImpl(GLFWwindow* window, double xoffset, double yoffset);
	void key_callbackImpl(GLFWwindow* window, int key, int scancode, int action, int mode);

};
