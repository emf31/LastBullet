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

	//GLFWmonitor* prMonitor = glfwGetPrimaryMonitor();
	//Para pantalla completa se debe especificar un monitor (el principal en caso de haber mas de uno) en el cuarto parametro
	//de la funcion glfwCreateWindow()

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
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_SCISSOR_TEST);
	//glEnable(GL_FRAMEBUFFER_SRGB);
	//glfwSwapInterval(-1); //vSync adaptativa!

	//glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;

	//KeyCallbacks
	setKeyCallbacks();

	
	//sm.camera_ptr = &input.camera;
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
	//glfwPollEvents();
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
	//glfwSetCharCallback(window, &Input::textInput_callback);
	glfwSetCharModsCallback(window, &Input::textInput_callback);
}

void EngineDevice::setWindowTitle(std::string title) {
	glfwSetWindowTitle(window, title.c_str());
}


