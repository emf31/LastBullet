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

	void init(const std::string& resourcesPath, irr::IrrlichtDevice *device) {
		if (m_IrrlichtRenderer == nullptr) {
			m_IrrlichtRenderer = &CEGUI::IrrlichtRenderer::bootstrapSystem(*device);

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

	Motor::GUI* getGUIbyName(const std::string& name) {
		auto found = m_guis.find(name);
		if (found != m_guis.end())
			return found->second;
		//no existe devolvemos 0
		return NULL;
	}

	CEGUI::IrrlichtRenderer* getIrrlichtRenderer() { return m_IrrlichtRenderer; }
private:
	GUIManager() {

	}
	CEGUI::IrrlichtRenderer *m_IrrlichtRenderer; //TODO: CAMBIAR A OPENGL3RENDERER CUANDO CAMBIEMOS A NUESTRO MOTOR

	std::map<std::string , Motor::GUI*> m_guis;
};