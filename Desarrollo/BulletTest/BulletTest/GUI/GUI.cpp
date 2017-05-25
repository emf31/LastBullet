#include "GUI.h"
#include <GUIManager.h>
#include <EventSystem.h>
#include <GLFW/glfw3.h>

Motor::GUI::GUI() : EventListener()
{
	
}

Motor::GUI::~GUI()
{
}

void Motor::GUI::init(const std::string& resourcesPath, const std::string& name){
	GUIManager::i().init(resourcesPath);
	CEGUI::Logger::getSingleton().setLoggingLevel(CEGUI::Informative);
	m_context = &CEGUI::System::getSingleton().createGUIContext(GUIManager::i().getRenderer()->getDefaultRenderTarget());
	m_root = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "root");
	m_context->setRootWindow(m_root);

	GUIManager::i().addGui(name, this);
	m_name = name;
}


void Motor::GUI::destroy() {
	CEGUI::System::getSingleton().destroyGUIContext(*m_context);
	GUIManager::i().removeGUI(m_name);
}

void Motor::GUI::draw() {
	glDisable(GL_DEPTH_TEST);
	GUIManager::i().getRenderer()->beginRendering();
	m_context->draw();
	GUIManager::i().getRenderer()->endRendering();
	glDisable(GL_SCISSOR_TEST);
	//glDepthFunc(GL_NEVER);
	
	glEnable(GL_DEPTH_TEST);
}

/*void Motor::GUI::update() {
	unsigned int elapsed;
	Time time;
	if (m_lastTime == 0) {
		elapsed = 0;
		m_lastTime = time.asSeconds();
	} else {
		unsigned int nextTime = time.asSeconds();
		elapsed = nextTime - m_lastTime;
		m_lastTime = nextTime;
	}
	m_context->injectTimePulse(elapsed);
}*/

void Motor::GUI::loadScheme(const std::string& schemeFile){
	CEGUI::SchemeManager::getSingleton().createFromFile(schemeFile);
}

void Motor::GUI::setFont(const std::string& fontFile) {
	CEGUI::FontManager::getSingleton().createFromFile(fontFile + ".font");
	m_context->setDefaultFont(fontFile);
}

CEGUI::Window* Motor::GUI::createWidget(const std::string& type, const vec4f& destRectPerc, const vec4f& destRectPix, const std::string& name) {
	CEGUI::Window *newWindow = CEGUI::WindowManager::getSingleton().createWindow(type, name);
	m_root->addChild(newWindow);
	setWidgetDestRect(newWindow, destRectPerc, destRectPix);
	return newWindow;
}

CEGUI::Window * Motor::GUI::loadLayout(const std::string & layout) {
	CEGUI::Window *newWindow = CEGUI::WindowManager::getSingleton().loadLayoutFromFile(layout);
	m_root->addChild(newWindow);
	return newWindow;
}

void Motor::GUI::showMouseCursor(bool show) {
	if (show) {
		m_context->getMouseCursor().show();
	} else {
		m_context->getMouseCursor().hide();
	}

}

void Motor::GUI::setMouseCursor(const std::string & mouse) {
	m_context->getMouseCursor().setDefaultImage(mouse);
}

CEGUI::Key::Scan Motor::GUI::GlfwToCeguiKey(int glfwKey)
{
	switch (glfwKey)
	{
	case GLFW_KEY_UNKNOWN: return CEGUI::Key::Unknown;
	case GLFW_KEY_ESCAPE: return CEGUI::Key::Escape;
	case GLFW_KEY_F1: return CEGUI::Key::F1;
	case GLFW_KEY_F2: return CEGUI::Key::F2;
	case GLFW_KEY_F3: return CEGUI::Key::F3;
	case GLFW_KEY_F4: return CEGUI::Key::F4;
	case GLFW_KEY_F5: return CEGUI::Key::F5;
	case GLFW_KEY_F6: return CEGUI::Key::F6;
	case GLFW_KEY_F7: return CEGUI::Key::F7;
	case GLFW_KEY_F8: return CEGUI::Key::F8;
	case GLFW_KEY_F9: return CEGUI::Key::F9;
	case GLFW_KEY_F10: return CEGUI::Key::F10;
	case GLFW_KEY_F11: return CEGUI::Key::F11;
	case GLFW_KEY_F12: return CEGUI::Key::F12;
	case GLFW_KEY_F13: return CEGUI::Key::F13;
	case GLFW_KEY_F14: return CEGUI::Key::F14;
	case GLFW_KEY_F15: return CEGUI::Key::F15;
	case GLFW_KEY_UP: return CEGUI::Key::ArrowUp;
	case GLFW_KEY_DOWN: return CEGUI::Key::ArrowDown;
	case GLFW_KEY_LEFT: return CEGUI::Key::ArrowLeft;
	case GLFW_KEY_RIGHT: return CEGUI::Key::ArrowRight;
	case GLFW_KEY_LEFT_SHIFT: return CEGUI::Key::LeftShift;
	case GLFW_KEY_RIGHT_SHIFT: return CEGUI::Key::RightShift;
	case GLFW_KEY_LEFT_CONTROL: return CEGUI::Key::LeftControl;
	case GLFW_KEY_RIGHT_CONTROL: return CEGUI::Key::RightControl;
	case GLFW_KEY_LEFT_ALT: return CEGUI::Key::LeftAlt;
	case GLFW_KEY_RIGHT_ALT: return CEGUI::Key::RightAlt;
	case GLFW_KEY_TAB: return CEGUI::Key::Tab;
	case GLFW_KEY_ENTER: return CEGUI::Key::Return;
	case GLFW_KEY_BACKSPACE: return CEGUI::Key::Backspace;
	case GLFW_KEY_INSERT: return CEGUI::Key::Insert;
	case GLFW_KEY_DELETE: return CEGUI::Key::Delete;
	case GLFW_KEY_PAGE_UP: return CEGUI::Key::PageUp;
	case GLFW_KEY_PAGE_DOWN: return CEGUI::Key::PageDown;
	case GLFW_KEY_HOME: return CEGUI::Key::Home;
	case GLFW_KEY_END: return CEGUI::Key::End;
	case GLFW_KEY_KP_ENTER: return CEGUI::Key::NumpadEnter;
	case GLFW_KEY_A: return CEGUI::Key::A;
	case GLFW_KEY_B: return CEGUI::Key::B;
	case GLFW_KEY_C: return CEGUI::Key::C;
	case GLFW_KEY_D: return CEGUI::Key::D;
	case GLFW_KEY_E: return CEGUI::Key::E;
	case GLFW_KEY_F: return CEGUI::Key::F;
	case GLFW_KEY_G: return CEGUI::Key::G;
	case GLFW_KEY_H: return CEGUI::Key::H;
	case GLFW_KEY_I: return CEGUI::Key::I;
	case GLFW_KEY_J: return CEGUI::Key::J;
	case GLFW_KEY_K: return CEGUI::Key::K;
	case GLFW_KEY_L: return CEGUI::Key::L;
	case GLFW_KEY_M: return CEGUI::Key::M;
	case GLFW_KEY_N: return CEGUI::Key::N;
	case GLFW_KEY_O: return CEGUI::Key::O;
	case GLFW_KEY_P: return CEGUI::Key::P;
	case GLFW_KEY_Q: return CEGUI::Key::Q;
	case GLFW_KEY_R: return CEGUI::Key::R;
	case GLFW_KEY_S: return CEGUI::Key::S;
	case GLFW_KEY_T: return CEGUI::Key::T;
	case GLFW_KEY_U: return CEGUI::Key::U;
	case GLFW_KEY_V: return CEGUI::Key::V;
	case GLFW_KEY_W: return CEGUI::Key::W;
	case GLFW_KEY_X: return CEGUI::Key::X;
	case GLFW_KEY_Y: return CEGUI::Key::Y;
	case GLFW_KEY_Z: return CEGUI::Key::Z;
	case GLFW_KEY_0: return CEGUI::Key::Numpad0;
	case GLFW_KEY_1: return CEGUI::Key::Numpad1;
	case GLFW_KEY_2: return CEGUI::Key::Numpad2;
	case GLFW_KEY_3: return CEGUI::Key::Numpad3;
	case GLFW_KEY_4: return CEGUI::Key::Numpad4;
	case GLFW_KEY_5: return CEGUI::Key::Numpad5;
	case GLFW_KEY_6: return CEGUI::Key::Numpad6;
	case GLFW_KEY_7: return CEGUI::Key::Numpad7;
	case GLFW_KEY_8: return CEGUI::Key::Numpad8;
	case GLFW_KEY_9: return CEGUI::Key::Numpad9;
	default: return CEGUI::Key::Unknown;
	}
}

CEGUI::MouseButton  Motor::GUI::GlfwToCeguiButton(int glfwButton)
{
	switch (glfwButton)
	{
	case GLFW_MOUSE_BUTTON_LEFT: return CEGUI::LeftButton;
	case GLFW_MOUSE_BUTTON_RIGHT: return CEGUI::RightButton;
	case GLFW_MOUSE_BUTTON_MIDDLE: return CEGUI::MiddleButton;
	default: return CEGUI::NoButton;
	}
}
/*CEGUI::Key::Scan Motor::GUI::irrlichtToCeguiKey(irr::EKEY_CODE key) {
	using namespace irr;
	using namespace CEGUI;
	switch (key) {
		case     KEY_BACK:  return Key::Backspace;
		case     KEY_TAB:  return Key::Tab;
		case     KEY_RETURN:  return Key::Return;
		case     KEY_CAPITAL:  return Key::Capital;
		case     KEY_ESCAPE:  return Key::Escape;
		case     KEY_SPACE:  return Key::Space;
		case     KEY_LEFT:  return Key::ArrowLeft;
		case     KEY_UP:  return Key::ArrowUp;
		case     KEY_RIGHT:  return Key::ArrowRight;
		case     KEY_DOWN:  return Key::ArrowDown;
		case     KEY_KEY_0:  return Key::Zero;
		case     KEY_KEY_1:  return Key::One;
		case     KEY_KEY_2:  return Key::Two;
		case     KEY_KEY_3:  return Key::Three;
		case     KEY_KEY_4:  return Key::Four;
		case     KEY_KEY_5:  return Key::Five;
		case     KEY_KEY_6:  return Key::Six;
		case     KEY_KEY_7:  return Key::Seven;
		case     KEY_KEY_8:  return Key::Eight;
		case     KEY_KEY_9:  return Key::Nine;
		case     KEY_KEY_A:  return Key::A;
		case     KEY_KEY_B:  return Key::B;
		case     KEY_KEY_C:  return Key::C;
		case     KEY_KEY_D:  return Key::D;
		case     KEY_KEY_E:  return Key::E;
		case     KEY_KEY_F:  return Key::F;
		case     KEY_KEY_G:  return Key::G;
		case     KEY_KEY_H:  return Key::H;
		case     KEY_KEY_I:  return Key::I;
		case     KEY_KEY_J:  return Key::J;
		case     KEY_KEY_K:  return Key::K;
		case     KEY_KEY_L:  return Key::L;
		case     KEY_KEY_M:  return Key::M;
		case     KEY_KEY_N:  return Key::N;
		case     KEY_KEY_O:  return Key::O;
		case     KEY_KEY_P:  return Key::P;
		case     KEY_KEY_Q:  return Key::Q;
		case     KEY_KEY_R:  return Key::R;
		case     KEY_KEY_S:  return Key::S;
		case     KEY_KEY_T:  return Key::T;
		case     KEY_KEY_U:  return Key::U;
		case     KEY_KEY_V:  return Key::V;
		case     KEY_KEY_W:  return Key::W;
		case     KEY_KEY_X:  return Key::X;
		case     KEY_KEY_Y:  return Key::Y;
		case     KEY_KEY_Z:  return Key::Z;
		case     KEY_F1:  return Key::F1;
		case     KEY_F2:  return Key::F2;
		case     KEY_F3:  return Key::F3;
		case     KEY_F4:  return Key::F4;
		case     KEY_F5:  return Key::F5;
		case     KEY_F6:  return Key::F6;
		case     KEY_F7:  return Key::F7;
		case     KEY_F8:  return Key::F8;
		case     KEY_F9:  return Key::F9;
		case     KEY_F10:  return Key::F10;
		case     KEY_F11:  return Key::F11;
		case     KEY_F12:  return Key::F12;
		case     KEY_LSHIFT:  return Key::LeftShift;
		case     KEY_RSHIFT:  return Key::RightShift;
		case     KEY_LCONTROL:  return Key::LeftControl;
		case     KEY_RCONTROL:  return Key::RightControl;
	}

}*/

void Motor::GUI::injectChar(unsigned int key) {
	m_context->injectChar((char)key);
}

void Motor::GUI::injectKeyDown(int key) {
	m_context->injectKeyDown(GlfwToCeguiKey(key));
}

void Motor::GUI::injectKeyUp(int key) {
	m_context->injectKeyUp(GlfwToCeguiKey(key));
}

void Motor::GUI::injectMousePosition(float x, float y) {
	m_context->injectMousePosition(x, y);
}

void Motor::GUI::setWidgetDestRect(CEGUI::Window* widget, const vec4f& destRectPerc, const vec4f& destRectPix) {
	widget->setPosition(CEGUI::UVector2(CEGUI::UDim(destRectPerc.x, destRectPix.x), CEGUI::UDim(destRectPerc.y, destRectPix.y)));
	widget->setSize(CEGUI::USize(CEGUI::UDim(destRectPerc.z, destRectPix.w), CEGUI::UDim(destRectPerc.z, destRectPix.w)));
}
