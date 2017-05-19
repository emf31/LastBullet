#include "DebugMenuGUI.h"
#include <Map.h>
#include <events\DebugNetEvent.h>
#include <NetworkManager.h>
#include <GUIManager.h>
#include <NetworkDebugger.h>
#include <NetworkLog.h>
#include <events\Event.h>
#include <EntityManager.h>
#include <ClippingManager.h>


DebugMenuGUI::DebugMenuGUI() : 
	GUI()
{
	netWorkLog = new NetworkLog();

}

DebugMenuGUI::~DebugMenuGUI()
{
	delete netWorkLog;
}


void DebugMenuGUI::handleEvent(Event * ev)
{
	switch (ev->event_type) {
		case E_NETWORK_DEBUGGER:
		{
			DebugNetEvent* deb = static_cast<DebugNetEvent*>(ev);
			updateProgressBars(deb->m_debugger);
			updateNetworkWindowInfo(deb->m_debugger);
			break;
		}
	}
}


//Imprime un texto por pantalla

void DebugMenuGUI::addPrintText(const std::string & str) {
	debugPrintText->setText(printable.addPrintText(str));
}

void DebugMenuGUI::inicializar() {
	init("../GUI", "DebugMenuGUI");

	loadScheme("AlfiskoSkin.scheme");
	loadScheme("VanillaSkin.scheme");
	loadScheme("VanillaCommonDialogs.scheme");
	loadLayout("SimpleDebug.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(false);

	GraphicEngine::i().createCamera("CamaraAerea",Vec3<float>(40, 150, -40), Vec3<float>(40, 0, -40));
	getContext()->getRootWindow()->getChild(0)->getChild(10)->setVisible(false);

	//PrintText
	debugPrintText = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(110));
	
	//MENU PRINCIPAL
	DebugShapesButton = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(12));
	DebugShapesButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugShapesClicked, this));

	closePushButton = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(99)->getChild(100));
	closePushButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonClicked, this));

	//DebugNetwork = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(11));
	//DebugNetwork->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugNetworkClicked, this));

	//DebugIA = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(14));
	//DebugIA->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAClicked, this));

//	IAWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(30));	

	CamaraAerea = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(20));
	CamaraAerea->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCamaraAerea, this));


	/*botonLoD = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(16));
	botonLoD->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onLoD, this));*/

	godMode = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(15));
	godMode->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onGodMode, this));

	prediction = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(16));
	prediction->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onMovementPrediction, this));

	Clipping = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(22));
	Clipping->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onClipping, this));

	Oclusions = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(21));
	Oclusions->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onOclusions, this));

	StaticShadows = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(23));
	StaticShadows->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onStaticShadows, this));

	DinamicShadows = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(24));
	DinamicShadows->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDinamicShadows, this));


	//MENU LOG NETWORK
	NetworkLogWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(200));
	serverLog = static_cast<CEGUI::MultiLineEditbox*>(NetworkLogWindow->getChild(201));
	clientLog = static_cast<CEGUI::MultiLineEditbox*>(NetworkLogWindow->getChild(202));

	NetworkLogButton = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(13));
	NetworkLogButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onLogNetworkClicked, this));

	UpdateLogButton = static_cast<CEGUI::PushButton*>(NetworkLogWindow->getChild(203));
	UpdateLogButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onUpdateLogButtonClicked, this));


	//MENU NETWORK
	/*NetworkWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(60));

	labelStatus = static_cast<CEGUI::DefaultWindow*>(NetworkWindow->getChild(1));
	labelPing = static_cast<CEGUI::DefaultWindow*>(NetworkWindow->getChild(2));
	labelTotalPackets = static_cast<CEGUI::DefaultWindow*>(NetworkWindow->getChild(3));
	labelPacketsIn = static_cast<CEGUI::DefaultWindow*>(NetworkWindow->getChild(4));
	labelPacketsOut = static_cast<CEGUI::DefaultWindow*>(NetworkWindow->getChild(5));
	labelServerIp = static_cast<CEGUI::DefaultWindow*>(NetworkWindow->getChild(6));
	labelNumPlayers = static_cast<CEGUI::DefaultWindow*>(NetworkWindow->getChild(7));

	toggleCountMovement = static_cast<CEGUI::ToggleButton*>(NetworkWindow->getChild(8));

	NetworSyncWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(80));

	movimientoPB = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(1));
	disparosPB = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(2));
	impactoPB = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(3));
	dropArmaPB = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(4));
	dropVidaPB = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(5));
	muertePB = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(6));
	granadaPB = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(7));
	aumentaKillPB = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(8));
	aumentaMuertePB = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(9));


	closePushButtonNetSync = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(80)->getChild(99)->getChild(100));
	closePushButtonNetSync->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonNetSyncClicked, this));
	closePushButtonNetDebug = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(60)->getChild(99)->getChild(100));
	closePushButtonNetDebug->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonNetDebugClicked, this));*/


	//MENU IA
	/*mapa = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(20));
	mapa->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onMapClicked, this));

	BotonMapa = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(5));//ID del menu de IA = 30
	BotonMapa->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAMapaClicked, this));

	BuscarVida = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(1));
	BuscarVida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAVIDAClicked, this));

	BuscarRocket = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(2));
	BuscarRocket->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAROCKETClicked, this));

	BuscarAsalto = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(3));
	BuscarAsalto->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAASALTOClicked, this));

	BuscarPistola = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(4));
	BuscarPistola->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAPISTOLAClicked, this));

	closePushButtonIA = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(99)->getChild(100));
	closePushButtonIA->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonIAClicked, this));*/


	BotA = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(6));
	BotA->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugBotAClicked, this));

	BotB = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(7));
	BotB->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugBotBClicked, this));

	BotC = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(8));
	BotC->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugBotCClicked, this));

	BotD = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(9));
	BotD->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugBotDClicked, this));

	estadosIA = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(10));
	estadosIA->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onEstadosIA, this));

	DesirabilityWeapons = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(40));//ID del menu de deseabilidad = 40

	DesiAsalto = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(40)->getChild(1));
	DesiRocketLauncher = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(40)->getChild(2));
	DesiSniper = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(40)->getChild(3));



	OpcionesIA = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(50));// ID del menu de opciones de IA = 50

	VaciarAsalto = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(1));
	VaciarAsalto->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onVaciarAsalto, this));

	VaciarRocket = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(2));
	VaciarRocket->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onVaciarRocket, this));

	VaciarSniper = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(3));
	VaciarSniper->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onVaciarSniper, this));

	VaciarPistola = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(4));
	VaciarPistola->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onVaciarPistola, this));



	InsAsalto = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(5));
	InsAsalto->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onInsAsalto, this));
	
	InsRocket = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(6));
	InsRocket->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onInsRocket, this));

	InsSniper = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(7));
	InsSniper->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onInsSniper, this));

	InsPistola = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(8));
	InsPistola->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onInsPistola, this));

	CamaraBot = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(11));
	CamaraBot->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCamaraBot, this));
	
	sliderUpdate = static_cast<CEGUI::Slider*>(getContext()->getRootWindow()->getChild(0)->getChild(50)->getChild(10));
	sliderUpdate->subscribeEvent(CEGUI::Slider::EventValueChanged, CEGUI::Event::Subscriber(&DebugMenuGUI::onUpdateSlider, this));


}

void DebugMenuGUI::update() {
	
	//Check duration of printable text
	//if (printable.checkIfShouldClearText()) { debugPrintText->setText(""); }

	updateFuzzyProgressBars();

	if (VerEstadosIA) {


		if (nodos[0]) {

			std::vector<Character*>bots = EntityManager::i().getBots();

			int i =0;


			for (std::vector<Character*>::iterator it = bots.begin(); it != bots.end(); it++) {

				Character* myentity = *it;

				Vec3<float>posBox = myentity->getPosition();
				posBox.addY(posBox.getY() + 15);

				std::string estado = myentity->getStateActual();


				nodos[i]->setPosition(posBox);

				if (myentity->isDying()) {


					nodos[i]->setColor(Vec3<float>(1, 1, 1));

				}
				else {
					nodos[i]->setColor(elegirColor(estado));
				}
				i++;

			}
		}
		

	}

}

Vec3<float> DebugMenuGUI::elegirColor(std::string estadoActual) {


		if (estadoActual == "BuscarVida") {
			return Vec3<float>(0,1,0);
		}

		if (estadoActual == "BuscarWeapon") {
			return Vec3<float>(1, 0.55f, 0);
		}

		if (estadoActual == "Disparar") {
			return Vec3<float>(1, 0, 0);
		}

		if (estadoActual == "Patrullar") {
			return Vec3<float>(0, 0, 1);

		}

		if (estadoActual == "Perseguir") {
			return Vec3<float>(1, 0, 1);
		}

	
		return Vec3<float>(0, 0, 0);

}


bool DebugMenuGUI::onDebugShapesClicked(const CEGUI::EventArgs & e) {
	GraphicEngine::i().toggleDebug();
	return true;
}
bool DebugMenuGUI::onDebugNetworkClicked(const CEGUI::EventArgs & e) {
	/*networkOpen = !networkOpen;
	//Cliente::i().windowsPacketOpen = !Cliente::i().windowsPacketOpen;
	NetworkWindow->setVisible(networkOpen);
	//NetworSyncWindow->setVisible(Cliente::i().windowsPacketOpen);*/
	
	return true;
}
bool DebugMenuGUI::onDebugIAClicked(const CEGUI::EventArgs & e) {
	/*IAWindow->setVisible(!IAWindow->isVisible());*/
	return true;
}
bool DebugMenuGUI::onDebugIAMapaClicked(const CEGUI::EventArgs & e) {
	/*mapa->setVisible(!mapa->isVisible());*/
	return true;
}

bool DebugMenuGUI::onDebugIAVIDAClicked(const CEGUI::EventArgs & e)
{
	return true;
}

bool DebugMenuGUI::onEstadosIA(const CEGUI::EventArgs & e) {

	if (!VerEstadosIA) {

		if (!nodos[0]) {
			crearNodosState();
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (nodos[i])
					nodos[i]->setVisible(true);
			}
		}

		VerEstadosIA = true;

	}
	else {
		VerEstadosIA = false;

		for (int i = 0; i < 4; i++) {
			if (nodos[i])
				nodos[i]->setVisible(false);
		}

	}

	return true;

}




void DebugMenuGUI::crearNodosState() {


	std::vector<Character*>bots = EntityManager::i().getBots();
	int i = 0;

	for (std::vector<Character*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Character* myentity = *it;

		Vec3<float>posBox = myentity->getPosition();
		posBox.addY(posBox.getY() + 15);

		nodos[i] = GraphicEngine::i().createNode(posBox, Vec3<float>(2, 2, 2), "", "../media/box.obj");
		i++;
	}

}

bool DebugMenuGUI::onDebugBotAClicked(const CEGUI::EventArgs & e) {

	std::vector<Character*>bots = EntityManager::i().getBots();

	if (!bots.empty()) {
		Character* myentity = bots[0];


		crearNodoBot(myentity);


		if (myentity == entActual) {

			DesirabilityWeapons->setVisible(!DesirabilityWeapons->isVisible());
			OpcionesIA->setVisible(!OpcionesIA->isVisible());


		}
		else {


			DesirabilityWeapons->setVisible(true);
			OpcionesIA->setVisible(true);

			entActual = myentity;
		}
	}
	
	return true;

}



bool DebugMenuGUI::onDebugBotBClicked(const CEGUI::EventArgs & e) {

	std::vector<Character*>bots = EntityManager::i().getBots();

	if (bots.size() > 1) {
		Character* myentity = bots[1];


		crearNodoBot(myentity);


		if (myentity == entActual) {

			DesirabilityWeapons->setVisible(!DesirabilityWeapons->isVisible());
			OpcionesIA->setVisible(!OpcionesIA->isVisible());


		}
		else {


			DesirabilityWeapons->setVisible(true);
			OpcionesIA->setVisible(true);

			entActual = myentity;
		}
	}

	return true;

}

bool DebugMenuGUI::onDebugBotCClicked(const CEGUI::EventArgs & e) {

	std::vector<Character*>bots = EntityManager::i().getBots();

	if (bots.size() > 2) {
		Character* myentity = bots[2];


		crearNodoBot(myentity);


		if (myentity == entActual) {

			DesirabilityWeapons->setVisible(!DesirabilityWeapons->isVisible());
			OpcionesIA->setVisible(!OpcionesIA->isVisible());


		}
		else {


			DesirabilityWeapons->setVisible(true);
			OpcionesIA->setVisible(true);

			entActual = myentity;
		}
	}

	return true;

}



bool DebugMenuGUI::onDebugBotDClicked(const CEGUI::EventArgs & e) {

	std::vector<Character*>bots = EntityManager::i().getBots();

	if (bots.size() > 3) {
		Character* myentity = bots[3];


		crearNodoBot(myentity);


		if (myentity == entActual) {

			DesirabilityWeapons->setVisible(!DesirabilityWeapons->isVisible());
			OpcionesIA->setVisible(!OpcionesIA->isVisible());


		}
		else {


			DesirabilityWeapons->setVisible(true);
			OpcionesIA->setVisible(true);

			entActual = myentity;
		}
	}

	return true;

}

void DebugMenuGUI::crearNodoBot(Entity* myentity) {


	if (!nodos[0]) {
		crearNodosState();
		VerEstadosIA = true;
	}


	for (int i = 0; i < 4; i++) {

		if (nodos[i]) {

			if (myentity->getID() == i) {
				nodos[i]->setVisible(true);
			}
			else {
				nodos[i]->setVisible(false);
			}
		}

	}

}


void DebugMenuGUI::updateFuzzyProgressBars() {

	if (entActual) {

		progresoAsalto = entActual->getDesiAsalto();
		progresoRocketLauncher = entActual->getDesiRocketLauncher();
		progresoSniper = entActual->getDesiSniper();


		DesiAsalto->setProgress(progresoAsalto / 100);
		DesiRocketLauncher->setProgress(progresoRocketLauncher / 100);
		DesiSniper->setProgress(progresoSniper / 100);

	}

}

bool DebugMenuGUI::onVaciarAsalto(const CEGUI::EventArgs & e){

	if (entActual)
		entActual->vaciarArma("Asalto");
	return true;
}

bool DebugMenuGUI::onVaciarRocket(const CEGUI::EventArgs & e) {

	if (entActual)
		entActual->vaciarArma("RocketLauncher");
	return true;

}

bool DebugMenuGUI::onVaciarSniper(const CEGUI::EventArgs & e) {

	if (entActual)
		entActual->vaciarArma("Sniper");
	return true;

}

bool DebugMenuGUI::onVaciarPistola(const CEGUI::EventArgs & e) {

	if (entActual)
		entActual->vaciarArma("Pistola");
	return true;

}

bool DebugMenuGUI::onInsAsalto(const CEGUI::EventArgs & e) {

	if (entActual)
		entActual->InsertarArmaDebug("Asalto");
	return true;
}

bool DebugMenuGUI::onInsRocket(const CEGUI::EventArgs & e) {

	if (entActual)
		entActual->InsertarArmaDebug("RocketLauncher");
	return true;

}

bool DebugMenuGUI::onInsSniper(const CEGUI::EventArgs & e) {

	if (entActual)
		entActual->InsertarArmaDebug("Sniper");
	return true;

}

bool DebugMenuGUI::onInsPistola(const CEGUI::EventArgs & e) {

	if (entActual)
		entActual->InsertarArmaDebug("Pistola");
	return true;

}

bool DebugMenuGUI::onLogNetworkClicked(const CEGUI::EventArgs & e)
{
	GUIManager::i().getGUIbyName("InGameHUD")->toggleVisible();
	NetworkLogWindow->setVisible(!NetworkLogWindow->isVisible());
	CEGUI::Window* MenuItems = getContext()->getRootWindow()->getChild(0)->getChild(10);
	MenuItems->setVisible(!MenuItems->isVisible());

	return true;
}

bool DebugMenuGUI::onUpdateLogButtonClicked(const CEGUI::EventArgs & e)
{
	//Llamar a NetworkManager?
	serverLog->setText(NetworkManager::i().serverLogInfo());

	clientLog->setText(netWorkLog->updateAndGenerateTable());

	return false;
}


bool DebugMenuGUI::onUpdateSlider(const CEGUI::EventArgs & e) {

	std::cout << "entra" << std::endl;

	std::cout << "Valor del slider: "<< sliderUpdate->getCurrentValue() << std::endl;


	entActual->setNumCiclos((int)sliderUpdate->getCurrentValue());

	return true;
}

bool DebugMenuGUI::onGodMode(const CEGUI::EventArgs & e)
{
	static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->godMode();
	return true;
}

bool DebugMenuGUI::onClipping(const CEGUI::EventArgs & e)
{
	ClippingManager::i().setUpdateClipping(!ClippingManager::i().getUpdateClipping());

	if (ClippingManager::i().getUpdateClipping()) {
		Clipping->setText("Disable Clipping");
	}
	else {
		Clipping->setText("Enable Clipping");
	}

	return true;
}

bool DebugMenuGUI::onOclusions(const CEGUI::EventArgs & e)
{
	ClippingManager::i().setUpdateOclusions(!ClippingManager::i().getUpdateOclusions());

	if (ClippingManager::i().getUpdateOclusions()) {
		Oclusions->setText("Disable Oclusions");
	}
	else {
		Oclusions->setText("Enable Oclusions");
	}

	return true;
}

bool DebugMenuGUI::onStaticShadows(const CEGUI::EventArgs & e)
{
	addPrintText("Sombras Estaticas");
	return true;
}

bool DebugMenuGUI::onDinamicShadows(const CEGUI::EventArgs & e)
{
	addPrintText("Sombras Dinamicas");
	return true;
}

bool DebugMenuGUI::onMovementPrediction(const CEGUI::EventArgs & e)
{
	NetworkManager::i().setMovementPrediction(!NetworkManager::i().isMovementPrediction());

	//prediction = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(16));

	if (NetworkManager::i().isMovementPrediction()) {
		prediction->setText("Disable MovPrediction");
	}
	else {
		prediction->setText("Enable MovPrediction");
	}

	return true;
}


bool DebugMenuGUI::onLoD(const CEGUI::EventArgs & e)
{

	std::vector<Character*>bots = EntityManager::i().getBots();

	for (std::vector<Character*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Character* myentity = *it;


		if (myentity->getLOD() == false) {
			myentity->setLoD(true);
		}
		else {
			myentity->setLoD(false);
		}

	}
	return true;
}



bool DebugMenuGUI::onDebugIAPISTOLAClicked(const CEGUI::EventArgs & e) {
	static_cast<Enemy_Bot*>(entActual)->createPathToItem("LifeObject");
	return true;
}
bool DebugMenuGUI::onDebugIAROCKETClicked(const CEGUI::EventArgs & e) {
	static_cast<Enemy_Bot*>(entActual)->createPathToItem("RocketLauncherDrop");
	return true;
}
bool DebugMenuGUI::onDebugIAASALTOClicked(const CEGUI::EventArgs & e) {
	static_cast<Enemy_Bot*>(entActual)->createPathToItem("AsaltoDrop");
	return true;
}


bool DebugMenuGUI::onCloseMenuButtonClicked(const CEGUI::EventArgs & e) {
	getContext()->getRootWindow()->getChild(0)->getChild(10)->setVisible(false);
	debugInput = !debugInput;
	showMouseCursor(debugInput);
	GraphicEngine::i().getActiveCamera()->setInputReceiver(!debugInput);
	onCloseMenuButtonIAClicked(e);
	return true;
}

bool DebugMenuGUI::onCloseMenuButtonIAClicked(const CEGUI::EventArgs & e) {
	/*getContext()->getRootWindow()->getChild(0)->getChild(30)->setVisible(false);
	mapa->setVisible(false);*/
	return true;
}

bool DebugMenuGUI::onCloseMenuButtonNetSyncClicked(const CEGUI::EventArgs & e) {
	/*NetworSyncWindow->setVisible(false);
	//Cliente::i().windowsPacketOpen = false;*/
	return true;
}

bool DebugMenuGUI::onCamaraAerea(const CEGUI::EventArgs & e) {

	
	if (GraphicEngine::i().getActiveCamera()->getNameCamera() != "CamaraAerea") {

		GraphicEngine::i().setActiveCamera("CamaraAerea");
		GraphicEngine::i().getActiveCamera()->setTarget(Vec3<float>(40, 0, -45) - GraphicEngine::i().getActiveCamera()->getPosition());

	}
	else {
		GraphicEngine::i().setActiveCamera("CamaraPlayer");
	}


	return true;
}

bool DebugMenuGUI::onCamaraBot(const CEGUI::EventArgs & e) {



	if (GraphicEngine::i().getActiveCamera()->getNameCamera() != entActual->getName()) {

		GraphicEngine::i().setActiveCamera(entActual->getName());
	}
	else {
		GraphicEngine::i().setActiveCamera("CamaraPlayer");
	}

	return true;
}



bool DebugMenuGUI::onCloseMenuButtonNetDebugClicked(const CEGUI::EventArgs & e)
{
	/*NetworkWindow->setVisible(false);*/
	return true;
}


bool DebugMenuGUI::onMapClicked(const CEGUI::EventArgs & e) {
	float x = getContext()->getMouseCursor().getPosition().d_x;
	float y = getContext()->getMouseCursor().getPosition().d_y;
	std::cout << "Se pincha en la posicion: x= " << x << " y= " << y << std::endl;
	float nodoX=y/3+6;
	float nodoY=x/3+2;
	std::cout << "El bot ira a la posicion: x= " << nodoX << " y= " << nodoY << std::endl;

	//botJuliyo->createPathToPosition(Vec2f(nodoX, nodoY));

	/*botTonire->createPathToPosition(Vec2f(nodoX, nodoY));
	botRucri->createPathToPosition(Vec2f(nodoX, nodoY));*/


	return true;
}

void DebugMenuGUI::updateProgressBars(NetworkDebugger* deb) {
	int numClientes = EntityManager::i().numClientes();
	float progreso = 1 / (float)numClientes;
	//Cliente cliente = Cliente::i();
	
	/*if (cliente.countGranada != 0)
		cliente.countGranada++;
	if (cliente.countDisparo != 0)
		cliente.countDisparo++;
	if (cliente.countMovimiento != 0)
		cliente.countMovimiento++;


	movimientoPB->setProgress(cliente.countMovimiento*progreso);
	disparosPB->setProgress(cliente.countDisparo*progreso);
	impactoPB->setProgress(cliente.countImpacto*progreso);
	dropArmaPB->setProgress(cliente.countDropArma*progreso);
	dropVidaPB->setProgress(cliente.countDropVida*progreso);
	muertePB->setProgress(cliente.countMuerte*progreso);
	granadaPB->setProgress(cliente.countGranada*progreso);
	aumentaKillPB->setProgress(cliente.countAumentaKill*progreso);
	aumentaMuertePB->setProgress(cliente.countAumentaMuerte*progreso);*/


}

void DebugMenuGUI::updateNetworkWindowInfo(NetworkDebugger* deb){
	/*Cliente cliente = Cliente::i();

	if (toggleCountMovement->isSelected()) {
		cliente.countPacketsTotal = cliente.countPacketsTotal + cliente.countMovementPacketsTotal;
		cliente.countPacketsIn = cliente.countPacketsIn + cliente.countMovementPacketsIn;
		cliente.countPacketsOut = cliente.countPacketsOut + cliente.countMovementPacketsOut;
	}

	std::ostringstream ossStatus;
	if (cliente.isConected()) {
		//labelStatus->setProperty("NormalTextColour", "tl:FF00FF00 tr:FF00FF00 bl:FF00FF00 br:FF00FF00");
		ossStatus << "Connected";
	} else {
		ossStatus << "Not Connected";
	}
	labelStatus->setText(ossStatus.str());

	if (cliente.isConected()) {
		std::ostringstream ossServerIp;
		std::string serverIp = cliente.getServerIp();
		size_t pos = serverIp.find("|");
		ossServerIp << serverIp.substr(0, pos);
		labelServerIp->setText(ossServerIp.str());
	}

	std::ostringstream ossNumPlayers;
	ossNumPlayers << EntityManager::i().numClientes();
	labelNumPlayers->setText(ossNumPlayers.str());

	std::ostringstream ossTotal;
	ossTotal << cliente.countPacketsTotal;
	labelTotalPackets->setText(ossTotal.str());

	std::ostringstream ossIn;
	ossIn << cliente.countPacketsIn;
	labelPacketsIn->setText(ossIn.str());

	std::ostringstream ossOut;
	ossOut << cliente.countPacketsOut;
	labelPacketsOut->setText(ossOut.str());

	std::ostringstream ossPing;
	ossPing << cliente.GetPing();
	labelPing->setText(ossPing.str());*/

	

}