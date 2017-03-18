#include <MenuGUI.h>
#include <iostream>
#include <NetPlayer.h>
#include <StateStack.h>

MenuGUI::MenuGUI() : GUI() {
}

void MenuGUI::inicializar() {
	init("../GUI",  "MenuGUI");
	loadScheme("SampleBrowser.scheme");
	loadScheme("AlfiskoSkin.scheme");
	loadScheme("Generic.scheme");
	loadScheme("AssetsMenu.scheme");
	loadScheme("LastBulletMenuBackground.scheme");
	loadLayout("LastBulletMENU.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(true);

	//Menu principal

	LastBullet = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(0));

	CrearPartida = static_cast<CEGUI::PushButton*>(LastBullet->getChild(0));
	CrearPartida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onCrearPartidaClicked, this));
	CrearPartida->setVisible(false);

	UnirPartida = static_cast<CEGUI::PushButton*>(LastBullet->getChild(1));
	UnirPartida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onUnirPartidaClicked, this));
	UnirPartida->setVisible(false);

	Salir = static_cast<CEGUI::PushButton*>(LastBullet->getChild(2));
	Salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onSalirClicked, this));
	Salir->setVisible(false);

	IconoPartida = static_cast<CEGUI::PushButton*>(LastBullet->getChild(3));

	IconoSalir = static_cast<CEGUI::PushButton*>(LastBullet->getChild(4));

	IconoOpciones = static_cast<CEGUI::PushButton*>(LastBullet->getChild(5));

	SchemePartida = static_cast<CEGUI::PushButton*>(LastBullet->getChild(6)); 
	SchemePartida->setVisible(false);

	SchemeOpciones= static_cast<CEGUI::PushButton*>(LastBullet->getChild(7)); 
	SchemeOpciones->setVisible(false);

	SchemeSalir = static_cast<CEGUI::PushButton*>(LastBullet->getChild(8));
	SchemeSalir->setVisible(false);

	//Unirse a partida

	UnirWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));

	UnirLabel = static_cast<CEGUI::DefaultWindow*>(UnirWindow->getChild(0));

	Conexion1 = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(1));
	Conexion1->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onConexion1Clicked, this));

	Conexion2 = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(2));
	Conexion2->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onConexion2Clicked, this));

	Actualizar = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(3));
	Actualizar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onUnirPartidaClicked, this));

	UnirWindow->setVisible(false);
	
	p = static_cast<Player*>(EntityManager::i().getEntity(PLAYER));


	
}

void MenuGUI::update()
{
	if (IconoPartida->isHovering()|| SchemePartida->isHovering() || CrearPartida->isHovering() || UnirPartida->isHovering()) {
		SchemePartida->setVisible(true);
		CrearPartida->setVisible(true);
		UnirPartida->setVisible(true);
	}
	else {
		SchemePartida->setVisible(false);
		CrearPartida->setVisible(false);
		UnirPartida->setVisible(false);
	}

	if (IconoOpciones->isHovering() || SchemeOpciones->isHovering()) {
		SchemeOpciones->setVisible(true);
	}
	else {
		SchemeOpciones->setVisible(false);
	}

	if (IconoSalir->isHovering() || SchemeSalir->isHovering() || Salir->isHovering()) {
		SchemeSalir->setVisible(true);
		Salir->setVisible(true);
	}
	else {
		SchemeSalir->setVisible(false);
		Salir->setVisible(false);
	}
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
	UnirWindow->setVisible(true);
	LastBullet->setVisible(false);
	p->m_network->searchServersOnLAN();
	std::vector<std::string> servers= p->m_network->getServers();
	int size = servers.size();
	//std::cout << size << std::endl;
	if (size == 2) {
		Conexion1->setText(servers.at(0));
		Conexion2->setText(servers.at(1));
	}
	if (size == 1) {
		Conexion1->setText(servers.at(0));
		Conexion2->setVisible(false);
	}
	if (size == 0){
		Conexion1->setVisible(false);
		Conexion2->setVisible(false);
	}
		
	std::cout << "Le has dado a unir" << std::endl;
	return true;
}

bool MenuGUI::onSalirClicked(const CEGUI::EventArgs & e)
{
	std::cout << "Le has dado a salir" << std::endl;
	return true;
}

bool MenuGUI::onConexion1Clicked(const CEGUI::EventArgs & e)
{
	p->m_network->unirseLobby(Conexion1->getText().c_str());
	return true;
}

bool MenuGUI::onConexion2Clicked(const CEGUI::EventArgs & e)
{
	p->m_network->unirseLobby(Conexion1->getText().c_str());
	return true;
}
