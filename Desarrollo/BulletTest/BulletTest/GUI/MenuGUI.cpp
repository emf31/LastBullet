#include <MenuGUI.h>
#include <iostream>
#include <NetPlayer.h>

MenuGUI::MenuGUI() : GUI() {
}

void MenuGUI::inicializar() {
	init("../GUI", GraphicEngine::i().getDevice(), "MenuGUI");
	loadScheme("SampleBrowser.scheme");
	loadScheme("AlfiskoSkin.scheme");
	loadScheme("Generic.scheme");
	loadLayout("LastBulletMENU.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(true);

	CrearPartida = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	CrearPartida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onCrearPartidaClicked, this));

	UnirPartida = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
	UnirPartida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onUnirPartidaClicked, this));

	Salir = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(4));
	Salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onSalirClicked, this));

	LastBullet = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));
	p = static_cast<Player*>(EntityManager::i().getEntity(PLAYER));
}

void MenuGUI::update()
{

}

void MenuGUI::handleEvent(Event * ev)
{

}

bool MenuGUI::onCrearPartidaClicked(const CEGUI::EventArgs & e)
{
	std::cout << "Le has dado a crear" << std::endl;
	p->m_network->crearPartida();
	return true;
}

bool MenuGUI::onUnirPartidaClicked(const CEGUI::EventArgs & e)
{
	std::cout << "Le has dado a unir" << std::endl;
	return true;
}

bool MenuGUI::onSalirClicked(const CEGUI::EventArgs & e)
{
	std::cout << "Le has dado a salir" << std::endl;
	return true;
}
