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
	void addGui(Motor::GUI *gui) {
		m_guis.push_back(gui);
	}

	void updateAllGuis() {
		std::list<Motor::GUI*>::iterator it;
		for (it = m_guis.begin(); it != m_guis.end(); ++it) {
			(*it)->update();
		}
	}

	void drawAllGuis() {
		std::list<Motor::GUI*>::iterator it;
		for (it = m_guis.begin(); it != m_guis.end(); ++it) {
			(*it)->draw();
		}
	}

	CEGUI::IrrlichtRenderer* getIrrlichtRenderer() { return m_IrrlichtRenderer; }
private:
	GUIManager() {

	}
	CEGUI::IrrlichtRenderer *m_IrrlichtRenderer; //TODO: CAMBIAR A OPENGL3RENDERER CUANDO CAMBIEMOS A NUESTRO MOTOR
	std::list<Motor::GUI*> m_guis;
};