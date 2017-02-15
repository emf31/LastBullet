#pragma once

//GLEW
#define GLEW_STATIC
#include <GLEW/glew.h>
//GLFW
#include <GLFW/glfw3.h>

#include "SceneManager.h"

#include "Camera.h"

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

	void updateCurrentFrame();
	int getFPS();
	
	void doMovement();
	void end();

	bool shouldCloseWindw();

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

private:
	SceneManager& sm = SceneManager::i();
	GLFWwindow *window;
	GLfloat lastTime;

	int numFrames = 0;
	int fps;
	float screenWidth, screenHeight;

	Input &input = Input::getInstance();

	void setKeyCallbacks();
};

