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



class EngineDevice {



public:
	EngineDevice();
	~EngineDevice();
	SceneManager* getSceneManager();
	bool createEngineDevice(int screenWidth, int screenHeight, std::string titleWindow);
	GLFWwindow * getWindow();

	// Camera
	Camera camera;
	// Moves/alters the camera positions based on user input
	
	void setWindowTitle(std::string title);

	void updateCurrentFrame() {
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
	}
	

	//TODO: Mover esto a otro sitio
	bool keys[1024];
	GLfloat lastX = 400, lastY = 300;
	bool firstMouse = true;

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;



	

private:
	SceneManager *sm;
	GLFWwindow *window;

	float screenWidth, screenHeight;

};

