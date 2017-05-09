#pragma once

#include <list>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GL3Renderer.h>
#include <GUI.h>

class GUIManager {
public:
	static GUIManager& i() {
		static GUIManager singleton;
		return singleton;
	}

	void init(const std::string& resourcesPath);
	void addGui(const std::string& name, Motor::GUI *gui);

	void updateAllGuis();

	void drawAllGuis();

	void removeGUI(const std::string& gui);
	Motor::GUI* getGUIbyName(const std::string& name);

	CEGUI::OpenGL3Renderer* getRenderer() { return m_renderer; }

private:
	GUIManager() {

	}
	CEGUI::OpenGL3Renderer *m_renderer; //TODO: CAMBIAR A OPENGL3RENDERER CUANDO CAMBIEMOS A NUESTRO MOTOR

	std::map<std::string , Motor::GUI*> m_guis;
};