#include <MenuGUI.h>
#include <iostream>
#include <NetPlayer.h>
#include <StateStack.h>
#include <NetworkManager.h>


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
	loadScheme("Planeta.scheme");
	loadLayout("LastBulletMENU.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(true);

	//Menu principal

	imagen1_x = 0;
	imagen2_x = -1280;
	FrameActual = 0;
	m_stateMenu = stateMenu::enumPrincipal;

	imagen = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	imagen2 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));

	LastBullet = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(0));
	

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

	Planeta = static_cast<CEGUI::DefaultWindow*>(LastBullet->getChild(8)->getChild(0));

	//Unirse a partida

	UnirWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));

	UnirLabel = static_cast<CEGUI::DefaultWindow*>(UnirWindow->getChild(0));

	Conexion1 = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(1));
	Conexion1->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onConexion1Clicked, this));

	Conexion2 = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(2));
	Conexion2->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onConexion2Clicked, this));

	Actualizar = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(3));
	Actualizar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onUnirPartidaClicked, this));

	connect = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(201));
	connect->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onConnectClicked, this));

	editBox = static_cast<CEGUI::Editbox*>(UnirWindow->getChild(200));
	editBox->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onEditBoxClicked, this));

	Atras1 = static_cast<CEGUI::PushButton*>(UnirWindow->getChild(99));
	Atras1->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onAtrasClicked, this));

	UnirWindow->setVisible(false);

	//Opciones Audio

	OpcionesAudioWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(5));

	Atras2 = static_cast<CEGUI::PushButton*>(OpcionesAudioWindow->getChild(99));
	Atras2->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onAtrasClicked, this));

	OpcionesAudioWindow->setVisible(false);

	//Opciones Video

	OpcionesVideoWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(6));

	Atras3 = static_cast<CEGUI::PushButton*>(OpcionesVideoWindow->getChild(99));
	Atras3->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onAtrasClicked, this));

	OpcionesVideoWindow->setVisible(false);

	//Opciones Game

	OpcionesGameWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));

	Atras4 = static_cast<CEGUI::PushButton*>(OpcionesGameWindow->getChild(99));
	Atras4->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuGUI::onAtrasClicked, this));

	OpcionesGameWindow->setVisible(false);

	//------------------------------------------------
	
	netPlayer = NetworkManager::i().getNetPlayer();

	rellenarAnimacionPlaneta();
	
}

void MenuGUI::update()
{

	updateFondo(2);
	reproducirAnimacionPlaneta();

	for(int i=2;i<=7;i++)
	static_cast<CEGUI::PushButton*>(LastBullet->getChild(i))->moveToFront();

	//Planeta->setProperty("Image","Planeta/1Planeta2");

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

	NetworkManager::i().getNetPlayer()->crearPartida();
	return true;
}

bool MenuGUI::onUnirPartidaClicked(const CEGUI::EventArgs & e)
{
	changeState(stateMenu::enumUnir);
	netPlayer->searchServersOnLAN();
	std::vector<std::string> servers= netPlayer->getServers();
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
	changeState(stateMenu::enumOpcionesAudio);
	std::cout << "Le has dado a opciones audio" << std::endl;
	return false;
}

bool MenuGUI::onOpcionesVideoClicked(const CEGUI::EventArgs & e)
{
	changeState(stateMenu::enumOpcionesVideo);
	std::cout << "Le has dado a opciones video" << std::endl;
	return false;
}

bool MenuGUI::onOpcionesGameClicked(const CEGUI::EventArgs & e)
{
	changeState(stateMenu::enumOpcionesGame);
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
	netPlayer->unirseLobby(Conexion1->getText().c_str());
	return true;
}

bool MenuGUI::onConexion2Clicked(const CEGUI::EventArgs & e)
{
	netPlayer->unirseLobby(Conexion1->getText().c_str());
	return true;
}

bool MenuGUI::onAtrasClicked(const CEGUI::EventArgs & e)
{
	changeState(stateMenu::enumPrincipal);
	return true;
}

bool MenuGUI::onConnectClicked(const CEGUI::EventArgs & e)
{
	
	netPlayer->unirseLobby("2.155.130.30");

	return false;
}

bool MenuGUI::onEditBoxClicked(const CEGUI::EventArgs & e)
{



	return false;
}

void MenuGUI::updateFondo(int velocidad)
{
	CEGUI::UDim suma;
	suma.d_offset = (float) velocidad;

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

void MenuGUI::rellenarAnimacionPlaneta()
{
	for (int i = 1; i <= 11; i++) {
		std::string auxi = std::to_string(i);
		for (int j = 1; j <= 26; j++) {
			std::string auxj = std::to_string(j);
			animacionPlaneta.push_back("Planeta/"+auxi+"Planeta" + auxj);
			//std::cout << "Planeta/" + auxj + "Planeta" + auxi << std::endl;
		}
	}

	for (int i = 1; i <= 15; i++) {
		std::string auxi = std::to_string(i);
		animacionPlaneta.push_back("Planeta/12Planeta" + auxi);
	}
}

void MenuGUI::reproducirAnimacionPlaneta()
{
	//Planeta->setProperty();
	CEGUI::Property* PropiedadesPlaneta=Planeta->getPropertyInstance("Image");
	PropiedadesPlaneta->set(Planeta,animacionPlaneta.at(FrameActual));
	//std::cout << animacionPlaneta.at(FrameActual) << std::endl;
	FrameActual++;
	if (FrameActual == animacionPlaneta.size()) {
		FrameActual = 0;
	}
}

void MenuGUI::changeState(stateMenu Newstate)
{
	setStateVisible(m_stateMenu, false);

	m_stateMenu = Newstate;

	setStateVisible(m_stateMenu, true);



}

void MenuGUI::setStateVisible(stateMenu state, bool visible)
{
	if (state == stateMenu::enumPrincipal) {
		LastBullet->setVisible(visible);
	}
	else if (state == stateMenu::enumUnir) {
		UnirWindow->setVisible(visible);
	}
	else if (state == stateMenu::enumOpcionesAudio) {
		OpcionesAudioWindow->setVisible(visible);
	}
	else if (state == stateMenu::enumOpcionesVideo) {
		OpcionesVideoWindow->setVisible(visible);
	}
	else if (state == stateMenu::enumOpcionesGame) {
		OpcionesGameWindow->setVisible(visible);
	}
}

void MenuGUI::actualizarTopOpciones()
{
	
}
