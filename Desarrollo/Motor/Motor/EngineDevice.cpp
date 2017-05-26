#include "EngineDevice.h"
#include <functional>

EngineDevice::EngineDevice() {

}


EngineDevice::~EngineDevice() {
	glfwDestroyWindow(window);
}



bool EngineDevice::createEngineDevice(int screenWidth, int screenHeight, std::string titleWindow) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 16);

	window = glfwCreateWindow(screenWidth, screenHeight, titleWindow.c_str(), nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	glViewport(0, 0, screenWidth, screenHeight);
	
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_SCISSOR_TEST);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;

	setKeyCallbacks();

	

	sm.screenWidth = &this->screenWidth;
	sm.screenHeight = &this->screenHeight;
	sm.inicializar();

	return true;
}

void EngineDevice::vSync(int a) {
	glfwSwapInterval(a);
}

GLFWwindow* EngineDevice::getWindow() {
	return window;
}

void EngineDevice::updateCurrentFrame() {
	glfwPollEvents();

	GLfloat currentFrame = (GLfloat)glfwGetTime();

	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	numFrames++;
}

int EngineDevice::getFPS() {

	GLfloat currentFrame = (GLfloat)glfwGetTime();

	if (currentFrame - lastTime >= 1.0) {
		fps = numFrames;
		numFrames = 0;
		lastTime += 1.0;
	}
	return fps;
}

void EngineDevice::doMovement() {
	
	input.Do_Movement(deltaTime);
	m_rotarDerecha = &Input::rotarDerecha;
	m_rotarIzquierda = &Input::rotarIzquierda;
}

void EngineDevice::end() {
	glfwTerminate();
}

bool  EngineDevice::shouldCloseWindw() {
	if (glfwWindowShouldClose(window)) {
		return true;
	}
	return false;
}

void EngineDevice::enableMouse(bool enable) {
	if (enable) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	} else {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
}

void EngineDevice::shutdown()
{
	sm.shutdown();
	
}

void EngineDevice::toggleWindowMode() {
	if (glfwGetWindowMonitor(window))
	{
		glfwSetWindowMonitor(window, NULL,
			0, screenWidth,
			0, screenHeight, 60);
	}
	else
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		if (monitor)
		{
			glfwSetWindowMonitor(window, monitor, 0, 0, screenWidth, screenHeight, 60);
		}
	}
}

void EngineDevice::setKeyCallbacks() {
	glfwSetKeyCallback(window, &Input::key_callback);
	glfwSetCursorPosCallback(window, &Input::mouse_callback);
	glfwSetMouseButtonCallback(window, &Input::mouseButtonCallback);
	glfwSetScrollCallback(window, &Input::scroll_callback);
	glfwSetCharModsCallback(window, &Input::textInput_callback);
}

void EngineDevice::setWindowTitle(std::string title) {
	glfwSetWindowTitle(window, title.c_str());
}


