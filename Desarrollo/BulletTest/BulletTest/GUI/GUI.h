#pragma once

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GL3Renderer.h>
#include <CEGUI/RendererModules/Irrlicht/Renderer.h>
#include <irrlitch/IEventReceiver.h>

#include "../MastEventReceiver.hpp"

struct vec4f{
	float x, y, z, w;
};

namespace Motor{
	class GUI {
	public:
		void init(const std::string& resourcesPath, irr::IrrlichtDevice *device);
		void destroy();
		void draw();

		void loadScheme(const std::string& schemeFile);
		void setFont(const std::string& fontFile);

		CEGUI::Window* createWidget(const std::string& type, const vec4f& destRectPerc, const vec4f& destRectPix, const std::string& name="");

		CEGUI::Window* loadLayout(const std::string& layout);

		void showMouseCursor(bool show) {
			if (show) {
				m_context->getMouseCursor().show();
			} else {
				m_context->getMouseCursor().hide();
			}
			
		}

		void setMouseCursor(const std::string& mouse) {
			m_context->getMouseCursor().setDefaultImage(mouse);
		}
		CEGUI::Key::Scan irrlichtToCeguiKey(irr::EKEY_CODE key) {
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

		}
		void injectKeyDown(irr::EKEY_CODE key) {
			m_context->injectKeyDown(irrlichtToCeguiKey(key));
		}

		void injectKeyUp(irr::EKEY_CODE key) {
			m_context->injectKeyUp(irrlichtToCeguiKey(key));
		}

		void injectMousePosition(float x, float y) {
			m_context->injectMousePosition(x, y);
		}

		static void setWidgetDestRect(CEGUI::Window* widget, const vec4f& destRectPerc, const vec4f& destRectPix);
		//Getters
		CEGUI::OpenGL3Renderer* getRenderer() { return m_renderer; }
		CEGUI::IrrlichtRenderer* getIrrlichtRenderer() { return m_rendererIrrlicht; }
		const CEGUI::GUIContext* getContext() { return m_context; }

		bool debugInput = false;

	private:
		CEGUI::OpenGL3Renderer* m_renderer;
		CEGUI::IrrlichtRenderer* m_rendererIrrlicht;
		CEGUI::GUIContext* m_context = nullptr;

		CEGUI::Window* m_root = nullptr;

		
	};
}

