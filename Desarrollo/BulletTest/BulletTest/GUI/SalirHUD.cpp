
#include <GraphicEngine.h>
#include <GUIManager.h>
#include <IngameHUD.h>
#include <StateStack.h>
#include "SalirHUD.h"

SalirHUD::SalirHUD() : GUI()
{
}

void SalirHUD::inicializar()
{
	init("../GUI", "LastBulletSalir");
	loadScheme("SampleBrowser.scheme");
	loadScheme("AlfiskoSkin.scheme");
	loadScheme("Generic.scheme");
	loadScheme("AssetsMenu.scheme");
	loadScheme("LastBulletSalir.scheme");
	loadLayout("LastBulletSalir.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(true);

	Salir = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(0)->getChild(1));
	Salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SalirHUD::onContinuarClicked, this));

	Continuar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(0)->getChild(2));
	Continuar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SalirHUD::onSalirClicked, this));

	Opciones = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(0)->getChild(3));
	Opciones->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SalirHUD::onOpcionesClicked, this));

	Window = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0));
	Window->setVisible(false);


}

void SalirHUD::update()
{
	Window->getChild(0)->moveToBack();
}

void SalirHUD::handleEvent(Event * ev)
{
}

bool SalirHUD::onContinuarClicked()
{
	clear();
	InGameHUD* hud = static_cast<InGameHUD*>(GUIManager::i().getGUIbyName("DebugMenuGUI"));
	hud->getContext()->getRootWindow()->getChild(0)->setVisible(!escapeInput);
	return true;
}

bool SalirHUD::onSalirClicked()
{
	clear();
	StateStack::i().GetCurrentState()->Clear();
	StateStack::i().SetCurrentState(States::ID::Menu);
	StateStack::i().GetCurrentState()->Inicializar();
	return true;
}

bool SalirHUD::onOpcionesClicked()
{
	return true;
}

void SalirHUD::clear()
{
		escapeInput = !escapeInput;
		GraphicEngine::i().enableMouse(escapeInput);
		showMouseCursor(escapeInput);
		GraphicEngine::i().getActiveCamera()->setInputReceiver(!escapeInput);
		Window->setVisible(escapeInput);
}
