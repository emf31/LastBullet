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

	Salir = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(1));
	Salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SalirHUD::onContinuarClicked, this));

	Continuar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	Continuar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SalirHUD::onSalirClicked, this));

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
	return true;
}

bool SalirHUD::onSalirClicked()
{
	return true;
}
