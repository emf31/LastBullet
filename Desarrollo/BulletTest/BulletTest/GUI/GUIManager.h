#pragma once

#include <list>
#include <CEGUI/CEGUI.h>
#include <GUI.h>

class GUIManager {
public:
	static GUIManager& i() {
		static GUIManager singleton;
		return singleton;
	}

	void init(const std::string& resourcesPath) {
		if (m_renderer == nullptr) {
			m_renderer = &CEGUI::OpenGL3Renderer::bootstrapSystem();

			CEGUI::DefaultResourceProvider* resourceProvider = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());

			resourceProvider->setResourceGroupDirectory("imagesets", resourcesPath + "/imagesets/");
			resourceProvider->setResourceGroupDirectory("schemes", resourcesPath + "/schemes/");
			resourceProvider->setResourceGroupDirectory("fonts", resourcesPath + "/fonts/");
			resourceProvider->setResourceGroupDirectory("layouts", resourcesPath + "/layouts/");
			resourceProvider->setResourceGroupDirectory("looknfeels", resourcesPath + "/looknfeel/");
			resourceProvider->setResourceGroupDirectory("lua_scripts", resourcesPath + "/lua_scripts/");

			CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
			CEGUI::Scheme::setDefaultResourceGroup("schemes");
			CEGUI::Font::setDefaultResourceGroup("fonts");
			CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
			CEGUI::WindowManager::setDefaultResourceGroup("layouts");
			CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");
		}
	}
	void addGui(const std::string& name, Motor::GUI *gui) {
		m_guis[name] = gui;
	}

	void updateAllGuis() {
		std::map<std::string, Motor::GUI*>::iterator it;
		for (it = m_guis.begin(); it != m_guis.end(); ++it) {
			it->second->update();
		}
	}

	void drawAllGuis() {
		std::map<std::string, Motor::GUI*>::iterator it;
		for (it = m_guis.begin(); it != m_guis.end(); ++it) {
			it->second->draw();
		}
	}

	void removeGUI(const std::string& gui)
	{
		auto found = m_guis.find(gui);
		if (found != m_guis.end())
			m_guis.erase(gui);
	}
	Motor::GUI* getGUIbyName(const std::string& name) {
		auto found = m_guis.find(name);
		if (found != m_guis.end())
			return found->second;
		//no existe devolvemos 
		return NULL;
	}

	CEGUI::OpenGL3Renderer* getRenderer() { return m_renderer; }
private:
	GUIManager() {

	}
	CEGUI::OpenGL3Renderer *m_renderer; //TODO: CAMBIAR A OPENGL3RENDERER CUANDO CAMBIEMOS A NUESTRO MOTOR

	std::map<std::string , Motor::GUI*> m_guis;
};