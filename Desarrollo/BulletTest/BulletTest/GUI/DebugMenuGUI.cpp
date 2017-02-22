#include "DebugMenuGUI.h"
#include <Map.h>
#include <events\DebugNetEvent.h>


DebugMenuGUI::DebugMenuGUI() : GUI()
{

}

DebugMenuGUI::~DebugMenuGUI()
{
}

void DebugMenuGUI::update() {
	/*updateProgressBars();
	updateNetworkWindowInfo();*/

	updateFuzzyProgressBars();
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

void DebugMenuGUI::inicializar() {
	init("../GUI", GraphicEngine::i().getDevice(), "DebugMenuGUI");

	loadScheme("AlfiskoSkin.scheme");
	loadScheme("VanillaSkin.scheme");
	loadScheme("VanillaCommonDialogs.scheme");
	loadLayout("SimpleDebug.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(false);

	//MENU PRINCIPAL
	DebugShapesButton = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(12));
	DebugShapesButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugShapesClicked, this));

	closePushButton = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(99)->getChild(100));
	closePushButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonClicked, this));

	DebugNetwork = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(11));
	DebugNetwork->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugNetworkClicked, this));

	DebugIA = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(14));
	DebugIA->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAClicked, this));

	IAWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(30));

	DesirabilityWeapons = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(40));
	
	DesiAsalto = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(40)->getChild(1));
	DesiRocketLauncher = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(40)->getChild(2));
	DesiSniper = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(40)->getChild(3));
	

	//MENU NETWORK
	NetworkWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(60));

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
	closePushButtonNetDebug->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonNetDebugClicked, this));


	//MENU IA
	mapa = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(20));
	mapa->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onMapClicked, this));

	BotonMapa = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(5));
	BotonMapa->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAMapaClicked, this));

	BuscarVida = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(1));
	BuscarVida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAVIDAClicked, this));

	BuscarRocket = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(2));
	BuscarRocket->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAROCKETClicked, this));

	BuscarAsalto = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(3));
	BuscarAsalto->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAASALTOClicked, this));

	BuscarPistola = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(4));
	BuscarPistola->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAPISTOLAClicked, this));

	BotA = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(6));
	BotA->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugBotAClicked, this));

	BotB = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(7));
	BotB->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugBotBClicked, this));

	closePushButtonIA = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(30)->getChild(99)->getChild(100));
	closePushButtonIA->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonIAClicked, this));



	


}

bool DebugMenuGUI::onDebugShapesClicked(const CEGUI::EventArgs & e) {
	GraphicEngine::i().toggleDebug();
	return true;
}
bool DebugMenuGUI::onDebugNetworkClicked(const CEGUI::EventArgs & e) {
	networkOpen = !networkOpen;
	//Cliente::i().windowsPacketOpen = !Cliente::i().windowsPacketOpen;
	NetworkWindow->setVisible(networkOpen);
	//NetworSyncWindow->setVisible(Cliente::i().windowsPacketOpen);
	
	return true;
}
bool DebugMenuGUI::onDebugIAClicked(const CEGUI::EventArgs & e) {
	IAWindow->setVisible(!IAWindow->isVisible());
	return true;
}
bool DebugMenuGUI::onDebugIAMapaClicked(const CEGUI::EventArgs & e) {
	mapa->setVisible(!mapa->isVisible());
	return true;
}

bool DebugMenuGUI::onDebugIAVIDAClicked(const CEGUI::EventArgs & e)
{
	return true;
}

bool DebugMenuGUI::onDebugBotAClicked(const CEGUI::EventArgs & e) {

	std::list<Entity*>bots = EntityManager::i().getBots();

	for (std::list<Entity*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Entity* myentity = *it;

		if(myentity->getID()==0){

			std::cout << myentity->getClassName() << std::endl;
			std::cout << myentity->getID() << std::endl;

			DesirabilityWeapons->setVisible(!DesirabilityWeapons->isVisible());

			IDBotAbierto = myentity->getID();

			

		}

	}
	return true;

}

bool DebugMenuGUI::onDebugBotBClicked(const CEGUI::EventArgs & e) {

	std::list<Entity*>bots = EntityManager::i().getBots();

	for (std::list<Entity*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Entity* myentity = *it;

		if (myentity->getID() == 1) {


			std::cout << myentity->getClassName() << std::endl;
			std::cout << myentity->getID() << std::endl;

			IDBotAbierto = myentity->getID();

			DesirabilityWeapons->setVisible(!DesirabilityWeapons->isVisible());


		}



	}
	return true;

}

void DebugMenuGUI::updateFuzzyProgressBars() {

	std::list<Entity*>bots = EntityManager::i().getBots();


	for (std::list<Entity*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Entity* myentity = *it;

		if (myentity->getID() == IDBotAbierto) {

			progresoAsalto = myentity->getDesiAsalto();
			progresoRocketLauncher = myentity->getDesiRocketLauncher();
			progresoSniper = myentity->getDesiSniper();

		}

	}


	DesiAsalto->setProgress(progresoAsalto / 100);
	DesiRocketLauncher->setProgress(progresoRocketLauncher / 100);
	DesiSniper->setProgress(progresoSniper / 100);


}

bool DebugMenuGUI::onDebugIAPISTOLAClicked(const CEGUI::EventArgs & e) {
	//Obama->createPathToItem("LifeObject");
	return true;
}
bool DebugMenuGUI::onDebugIAROCKETClicked(const CEGUI::EventArgs & e) {
	//Obama->createPathToItem("RocketLauncherDrop");
	return true;
}
bool DebugMenuGUI::onDebugIAASALTOClicked(const CEGUI::EventArgs & e) {
	//Obama->createPathToItem("AsaltoDrop");
	return true;
}


bool DebugMenuGUI::onCloseMenuButtonClicked(const CEGUI::EventArgs & e) {
	getContext()->getRootWindow()->getChild(0)->getChild(10)->setAlpha(0.0f);
	debugInput = !debugInput;
	showMouseCursor(debugInput);
	GraphicEngine::i().getActiveCamera()->setInputReceiver(!debugInput);
	onCloseMenuButtonIAClicked(e);
	return true;
}

bool DebugMenuGUI::onCloseMenuButtonIAClicked(const CEGUI::EventArgs & e) {
	getContext()->getRootWindow()->getChild(0)->getChild(30)->setVisible(false);
	mapa->setVisible(false);
	return true;
}
bool DebugMenuGUI::onCloseMenuButtonNetSyncClicked(const CEGUI::EventArgs & e) {
	NetworSyncWindow->setVisible(false);
	//Cliente::i().windowsPacketOpen = false;
	return true;
}

bool DebugMenuGUI::onCloseMenuButtonNetDebugClicked(const CEGUI::EventArgs & e)
{
	NetworkWindow->setVisible(false);
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