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

	//Menu principal
	Titulo = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));

	LastBullet = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(0));

	CrearPartida = static_cast<CEGUI::PushButton*>(LastBullet->getChild(0));
	CrearPartida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onCrearPartidaClicked, this));

	UnirPartida = static_cast<CEGUI::PushButton*>(LastBullet->getChild(1));
	UnirPartida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onUnirPartidaClicked, this));

	Salir = static_cast<CEGUI::PushButton*>(LastBullet->getChild(2));
	Salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onSalirClicked, this));

	//Unirse a partida

	UnirWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));

	UnirLabel = static_cast<CEGUI::DefaultWindow*>(UnirWindow->getChild(0));

	Conexion1 = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(1));
	Conexion1->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onConexion1Clicked, this));

	Conexion2 = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(2));
	Conexion2->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onConexion2Clicked, this));

	Actualizar = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(3));
	Actualizar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onUnirPartidaClicked, this));

	Atras = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(4));
	Atras->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onAtrasClicked, this));

	escribirIP = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(6));
	escribirIP->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onescribirIPClicked, this));

	ConecarIP = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(7));
	ConecarIP->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onconectarIPClicked, this));

	UnirWindow->setVisible(false);
	
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

bool MenuGUI::onescribirIPClicked(const CEGUI::EventArgs & e)
{
	escribirIP->setText("");
	return true;
}

bool MenuGUI::onconectarIPClicked(const CEGUI::EventArgs & e)
{
	p->m_network->unirseLobby(escribirIP->getText().c_str());
	return true;
}

bool MenuGUI::onAtrasClicked(const CEGUI::EventArgs & e)
{
	UnirWindow->setVisible(false);
	LastBullet->setVisible(true);
	return true;
}

void MenuGUI::escribir(const std::string& w )
{
	escribirIP->insertText(w, escribirIP->getText().size());
}

void MenuGUI::borrarUltimo()
{
	CEGUI::String str = escribirIP->getText().substr(0,escribirIP->getText().size() - 1);
	escribirIP->setText(str);
}
