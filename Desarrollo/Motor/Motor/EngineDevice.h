#pragma once

//GLEW
#include <GLEW/glew.h>
//GLFW
#include <GLFW/glfw.h>

#include "SceneManager.h"

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Input
#include "Input.h"

class EngineDevice {



public:

	EngineDevice();
	~EngineDevice();

	bool m_rotarDerecha;
	bool m_rotarIzquierda;
	
	bool createEngineDevice(int screenWidth, int screenHeight, std::string titleWindow);
	
	GLFWwindow * getWindow();
	
	void setWindowTitle(std::string title);
	void vSync(int a);

	void updateCurrentFrame();
	int getFPS();
	
	void doMovement();
	void end();

	bool shouldCloseWindw();

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	void enableMouse(bool enable);

	void shutdown();

	void toggleWindowMode();

private:
	SceneManager& sm = SceneManager::i();
	GLFWwindow *window;
	GLfloat lastTime;

	int numFrames = 0;
	int fps;
	int screenWidth, screenHeight;

	Input &input = Input::i();

	void setKeyCallbacks();
};

