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
	loadScheme("LastBulletMenuBackgroundVolteado.scheme");
	loadScheme("LastBulletHeader.scheme");
	loadLayout("LastBulletMENU.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(true);

	//Menu principal

	imagen1_x = 0;
	imagen2_x = -1280;



	imagen = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	imagen2 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));

	LastBullet = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(0));

	Planeta = static_cast<CEGUI::Image*>(LastBullet->getChild(0));

	CrearPartida = static_cast<CEGUI::PushButton*>(LastBullet->getChild(2));
	CrearPartida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onCrearPartidaClicked, this));

	UnirPartida = static_cast<CEGUI::PushButton*>(LastBullet->getChild(3));
	UnirPartida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onUnirPartidaClicked, this));

	OpcionesAudio = static_cast<CEGUI::PushButton*>(LastBullet->getChild(4));
	OpcionesAudio->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onOpcionesAudioClicked, this));

	OpcionesVideo = static_cast<CEGUI::PushButton*>(LastBullet->getChild(5));
	OpcionesVideo->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onOpcionesVideoClicked, this));

	OpcionesGame = static_cast<CEGUI::PushButton*>(LastBullet->getChild(6));
	OpcionesGame->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onOpcionesGameClicked, this));

	Salir = static_cast<CEGUI::PushButton*>(LastBullet->getChild(7));
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

	UnirWindow->setVisible(false);
	
	p = static_cast<Player*>(EntityManager::i().getEntity(PLAYER));


	
}

void MenuGUI::update()
{

	updateFondo(2);

	/*if (IconoPartida->isHovering()|| SchemePartida->isHovering() || CrearPartida->isHovering() || UnirPartida->isHovering()) {
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
	}*/
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
	std::cout << size << std::endl;
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
		
	//std::cout << "Le has dado a unir" << std::endl;
	return true;
}

bool MenuGUI::onOpcionesAudioClicked(const CEGUI::EventArgs & e)
{
	std::cout << "Le has dado a opciones audio" << std::endl;
	return false;
}

bool MenuGUI::onOpcionesVideoClicked(const CEGUI::EventArgs & e)
{
	std::cout << "Le has dado a opciones video" << std::endl;
	return false;
}

bool MenuGUI::onOpcionesGameClicked(const CEGUI::EventArgs & e)
{
	std::cout << "Le has dado a opciones game" << std::endl;
	return false;
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

void MenuGUI::updateFondo(int velocidad)
{
	CEGUI::UDim suma;
	suma.d_offset = velocidad;

	CEGUI::UVector2 newposition(CEGUI::UDim(imagen->getPosition().d_x) + suma, CEGUI::UDim(imagen->getPosition().d_y));
	CEGUI::UVector2 newposition2(CEGUI::UDim(imagen2->getPosition().d_x) + suma, CEGUI::UDim(imagen2->getPosition().d_y));

	imagen->setPosition(newposition);
	imagen2->setPosition(newposition2);

	imagen1_x += velocidad;
	imagen2_x += velocidad;

	if (imagen1_x >= 1280) {
		CEGUI::UDim resta;
		resta.d_offset = 2560;
		CEGUI::UVector2 newposition(CEGUI::UDim(imagen->getPosition().d_x) - resta, CEGUI::UDim(imagen->getPosition().d_y));
		imagen->setPosition(newposition);
		imagen1_x = -1280;
	}
	if (imagen2_x >= 1280) {
		CEGUI::UDim resta;
		resta.d_offset = 2560;
		CEGUI::UVector2 newposition2(CEGUI::UDim(imagen2->getPosition().d_x) - resta, CEGUI::UDim(imagen2->getPosition().d_y));
		imagen2->setPosition(newposition2);
		imagen2_x = -1280;
	}
}
