#pragma once

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GL3Renderer.h>

struct vec4f{
	float x, y, z, w;
};

namespace Motor{
	class GUI {
	public:
		void init(const std::string& resourcesPath);
		void destroy();
		void draw();

		void loadScheme(const std::string& schemeFile);
		void setFont(const std::string& fontFile);

		CEGUI::Window* createWidget(const std::string& type, const vec4f& destRectPerc, const vec4f& destRectPix, const std::string& name="");

		CEGUI::Window* loadLayout(const std::string& layout);

		static void setWidgetDestRect(CEGUI::Window* widget, const vec4f& destRectPerc, const vec4f& destRectPix);
		//Getters
		CEGUI::OpenGL3Renderer* getRenderer() { return m_renderer; }
		const CEGUI::GUIContext* getContext() { return m_context; }

	private:
		CEGUI::OpenGL3Renderer* m_renderer;
		CEGUI::GUIContext* m_context = nullptr;

		CEGUI::Window* m_root = nullptr;
	};
}

