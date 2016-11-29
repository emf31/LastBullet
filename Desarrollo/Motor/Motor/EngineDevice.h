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
	SceneManager* getSceneManager();
	bool createEngineDevice(int screenWidth, int screenHeight, std::string titleWindow);
	
	GLFWwindow * getWindow();
	
	void setWindowTitle(std::string title);

	void updateCurrentFrame() {
		GLfloat currentFrame = glfwGetTime();

		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		numFrames++;
	}
	int getFPS() {
		
		GLfloat currentFrame = glfwGetTime();

		if (currentFrame - lastTime >= 1.0) {
			fps = numFrames;
			numFrames = 0;
			lastTime += 1.0;
		}
		return fps;
		
	}
	
	void doMovement() {
		glfwPollEvents();
		input.Do_Movement(deltaTime);
	}
	//TODO: Mover esto a otro sitio
	
	void end() {
		glfwTerminate();
	}

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

private:
	SceneManager *sm;
	GLFWwindow *window;
	GLfloat lastTime;
	int numFrames = 0;
	int fps;
	float screenWidth, screenHeight;
	Input &input = Input::getInstance();
	void setKeyCallbacks();
};

