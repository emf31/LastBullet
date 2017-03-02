#include "DebugMenuGUI.h"
#include <Map.h>
#include <events\DebugNetEvent.h>


DebugMenuGUI::DebugMenuGUI() : GUI()
{

}

DebugMenuGUI::~DebugMenuGUI()
{
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

	GraphicEngine::i().createCamera("CamaraAerea",Vec3<float>(100, 200, 100), Vec3<float>(100, 0, 100));


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

	CamaraAerea = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(20));
	CamaraAerea->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCamaraAerea, this));

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
	closePushButtonIA->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonIAClicked, this));


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
	/*updateProgressBars();
	updateNetworkWindowInfo();*/

	updateFuzzyProgressBars();


	if (VerEstadosIA) {


		if (nodos[0]) {

			std::list<Entity*>bots = EntityManager::i().getBots();


			for (std::list<Entity*>::iterator it = bots.begin(); it != bots.end(); it++) {

				Entity* myentity = *it;

				Vec3<float>posBox = myentity->getRenderState()->getPosition();
				posBox.addY(posBox.getY() + 15);

				std::string estado = myentity->getStateActual();

				int i = myentity->getID();

				nodos[i]->setPosition(posBox);

				if (myentity->isDying()) {
					Color4f color(255, 255, 255, 0);
					nodos[i]->setColor(color);

				}
				else {
					nodos[i]->setColor(elegirColor(estado));
				}

			}
		}
		

	}

}

Color4f DebugMenuGUI::elegirColor(std::string estadoActual) {


		if (estadoActual == "BuscarVida") {
			Color4f color(0, 255, 0, 1);
			return color;
		}

		if (estadoActual == "BuscarWeapon") {
			Color4f color(255, 168, 0, 1);
			return color;
		}

		if (estadoActual == "Disparar") {
			Color4f color(255, 0, 0, 1);
			return color;
		}

		if (estadoActual == "Patrullar") {
			Color4f color(0, 0, 255, 1);
			return color;

		}

		if (estadoActual == "Perseguir") {
			Color4f color(255, 0, 255, 1);
			return color;
		}

	
		Color4f color(0, 0, 0, 1);
		return color;

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


	std::list<Entity*>bots = EntityManager::i().getBots();


	for (std::list<Entity*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Entity* myentity = *it;

		Vec3<float>posBox = myentity->getRenderState()->getPosition();
		posBox.addY(posBox.getY() + 15);

		nodos[myentity->getID()] = GraphicEngine::i().createNode(posBox, Vec3<float>(2, 2, 2), "", "");

	}

}

bool DebugMenuGUI::onDebugBotAClicked(const CEGUI::EventArgs & e) {

	std::list<Entity*>bots = EntityManager::i().getBots();

	for (std::list<Entity*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Entity* myentity = *it;

		if(myentity->getID()==0){

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

	}
	return true;

}



bool DebugMenuGUI::onDebugBotBClicked(const CEGUI::EventArgs & e) {

	std::list<Entity*>bots = EntityManager::i().getBots();

	for (std::list<Entity*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Entity* myentity = *it;

		if (myentity->getID() == 1) {

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

	}
	return true;

}

bool DebugMenuGUI::onDebugBotCClicked(const CEGUI::EventArgs & e) {

	std::list<Entity*>bots = EntityManager::i().getBots();

	for (std::list<Entity*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Entity* myentity = *it;

		if (myentity->getID() == 2) {

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

	}
	return true;

}



bool DebugMenuGUI::onDebugBotDClicked(const CEGUI::EventArgs & e) {

	std::list<Entity*>bots = EntityManager::i().getBots();

	for (std::list<Entity*>::iterator it = bots.begin(); it != bots.end(); it++) {

		Entity* myentity = *it;

		if (myentity->getID() == 3) {

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


bool DebugMenuGUI::onUpdateSlider(const CEGUI::EventArgs & e) {

	std::cout << "entra" << std::endl;

	std::cout << "Valor del slider: "<< sliderUpdate->getCurrentValue() << std::endl;


	entActual->setNumCiclos(sliderUpdate->getCurrentValue());

	return true;
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
	getContext()->getRootWindow()->getChild(0)->getChild(10)->setVisible(false);
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

bool DebugMenuGUI::onCamaraAerea(const CEGUI::EventArgs & e) {

	
	if (GraphicEngine::i().getActiveCamera()->getNameCamera() != "CamaraAerea") {

		GraphicEngine::i().setActiveCamera("CamaraAerea");
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