#include "GUI.h"


void Motor::GUI::init(const std::string& resourcesPath, irr::IrrlichtDevice *device){
	//Solo inicializamos una vez m_renderer
	
	if (m_rendererIrrlicht == nullptr) {
		m_rendererIrrlicht = &CEGUI::IrrlichtRenderer::bootstrapSystem(*device);

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

	CEGUI::Logger::getSingleton().setLoggingLevel(CEGUI::Informative);

	m_context = &CEGUI::System::getSingleton().createGUIContext(m_rendererIrrlicht->getDefaultRenderTarget());
	m_root = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "root");
	m_context->setRootWindow(m_root);
}


void Motor::GUI::destroy() {
	CEGUI::System::getSingleton().destroyGUIContext(*m_context);
}

void Motor::GUI::draw() {
	
	m_rendererIrrlicht->beginRendering();
	m_context->draw();
	m_rendererIrrlicht->endRendering();
	//glDisable(GL_SCISSOR_TEST);
}

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

void Motor::GUI::setWidgetDestRect(CEGUI::Window* widget, const vec4f& destRectPerc, const vec4f& destRectPix) {
	widget->setPosition(CEGUI::UVector2(CEGUI::UDim(destRectPerc.x, destRectPix.x), CEGUI::UDim(destRectPerc.y, destRectPix.y)));
	widget->setSize(CEGUI::USize(CEGUI::UDim(destRectPerc.z, destRectPix.w), CEGUI::UDim(destRectPerc.z, destRectPix.w)));
}