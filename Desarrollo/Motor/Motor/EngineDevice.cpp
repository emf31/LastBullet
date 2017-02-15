#include "EngineDevice.h"
#include <functional>

EngineDevice::EngineDevice() {

}


EngineDevice::~EngineDevice() {
	glfwDestroyWindow(window);
	delete sm;
}



bool EngineDevice::createEngineDevice(int screenWidth, int screenHeight, std::string titleWindow) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//GLFWmonitor* prMonitor = glfwGetPrimaryMonitor();
	//Para pantalla completa se debe especificar un monitor (el principal en caso de haber mas de uno) en el cuarto parametro
	//de la funcion glfwCreateWindow()

	window = glfwCreateWindow(screenWidth, screenHeight, titleWindow.c_str(), nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	glViewport(0, 0, screenWidth, screenHeight);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_CULL_FACE);
	
	glfwSwapInterval(-1); //vSync adaptativa!

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;

	//KeyCallbacks
	setKeyCallbacks();

	return 1;
}



SceneManager* EngineDevice::getSceneManager() {
	if (sm != nullptr) {
		return sm;
	} else {
		sm = new SceneManager();
		sm->camera_ptr = &input.camera;
		sm->screenWidth = &screenWidth;
		sm->screenHeight = &screenHeight;
		sm->inicializar();
		return sm;
	}
}

GLFWwindow* EngineDevice::getWindow() {
	return window;
}

void EngineDevice::updateCurrentFrame() {
	GLfloat currentFrame = glfwGetTime();

	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	numFrames++;
}

int EngineDevice::getFPS() {

	GLfloat currentFrame = glfwGetTime();

	if (currentFrame - lastTime >= 1.0) {
		fps = numFrames;
		numFrames = 0;
		lastTime += 1.0;
	}
	return fps;
}

void EngineDevice::doMovement() {
	glfwPollEvents();
	input.Do_Movement(deltaTime);
	m_rotarDerecha = &Input::rotarDerecha;
	m_rotarIzquierda = &Input::rotarIzquierda;
}

void EngineDevice::end() {
	glfwTerminate();
}

bool  EngineDevice::shouldCloseWindw() {
	return glfwWindowShouldClose(window);
}

void EngineDevice::setKeyCallbacks() {
	glfwSetKeyCallback(window, &Input::key_callback);
	glfwSetCursorPosCallback(window, &Input::mouse_callback);
	glfwSetScrollCallback(window, &Input::scroll_callback);
}

void EngineDevice::setWindowTitle(std::string title) {
	glfwSetWindowTitle(window, title.c_str());
}


