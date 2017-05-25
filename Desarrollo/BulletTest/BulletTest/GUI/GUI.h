#pragma once

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GL3Renderer.h>

#include <EventListener.h>


struct vec4f{
	float x, y, z, w;
};

namespace Motor{
	class GUI : public EventListener {

	public:
		GUI();
		~GUI();

		void init(const std::string& resourcesPath, const std::string& name);
		void destroy();
		void draw();

		virtual void update() = 0;

		// Heredado vía EventListener
		virtual void handleEvent(Event * ev) = 0;

		void loadScheme(const std::string& schemeFile);
		void setFont(const std::string& fontFile);

		CEGUI::Window* createWidget(const std::string& type, const vec4f& destRectPerc, const vec4f& destRectPix, const std::string& name="");

		CEGUI::Window* loadLayout(const std::string& layout);


		void showMouseCursor(bool show);

		void setMouseCursor(const std::string& mouse);

		CEGUI::Key::Scan GlfwToCeguiKey( int glfwKey);
		CEGUI::MouseButton GlfwToCeguiButton( int glfwButton);

		void injectChar(unsigned int key);

		void injectKeyDown(int key);

		void injectKeyUp(int key);

		void injectMousePosition(float x, float y);

		void injectLeftMouseButton() { m_context->injectMouseButtonDown(CEGUI::MouseButton::LeftButton); }

		void injectLeftMouseButtonUp() { m_context->injectMouseButtonUp(CEGUI::MouseButton::LeftButton); }

		void injectRightMouseButton() { m_context->injectMouseButtonDown(CEGUI::MouseButton::RightButton); }


		static void setWidgetDestRect(CEGUI::Window* widget, const vec4f& destRectPerc, const vec4f& destRectPix);

		//Getters
		//CEGUI::OpenGL3Renderer* getRenderer() { return m_renderer; }
		const CEGUI::GUIContext* getContext() { return m_context; }

		bool debugInput = false;
		bool escapeInput = false;


		void toggleVisible() { getContext()->getRootWindow()->setVisible(!getContext()->getRootWindow()->isVisible()); }

	protected:
		CEGUI::OpenGL3Renderer* m_renderer;

		CEGUI::GUIContext* m_context = nullptr;

		CEGUI::Window* m_root = nullptr;

		unsigned int m_lastTime = 0;
		
		std::string m_name;

		

	};
}

