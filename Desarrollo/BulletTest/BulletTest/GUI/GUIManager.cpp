#include "GUIManager.h"

void GUIManager::init(const std::string & resourcesPath) {
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

void GUIManager::addGui(const std::string & name, Motor::GUI * gui) {
	m_guis[name] = gui;
}

void GUIManager::updateAllGuis() {
	std::map<std::string, Motor::GUI*>::iterator it;
	for (it = m_guis.begin(); it != m_guis.end(); ++it) {
		it->second->update();
	}
}

void GUIManager::drawAllGuis() {
	std::map<std::string, Motor::GUI*>::iterator it;
	for (it = m_guis.begin(); it != m_guis.end(); ++it) {
		it->second->draw();
	}
}

void GUIManager::removeGUI(const std::string & gui)
{
	auto found = m_guis.find(gui);
	if (found != m_guis.end())
		m_guis.erase(gui);
}

Motor::GUI * GUIManager::getGUIbyName(const std::string & name) {
	auto found = m_guis.find(name);
	if (found != m_guis.end())
		return found->second;
	//no existe devolvemos 
	return NULL;
}


