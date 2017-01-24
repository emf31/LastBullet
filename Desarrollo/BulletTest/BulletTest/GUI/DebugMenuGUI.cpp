#include "DebugMenuGUI.h"
#include <Map.h>


void DebugMenuGUI::update() {
}

void DebugMenuGUI::inicializar() {
	init("../GUI", GraphicEngine::i().getDevice());

	loadScheme("AlfiskoSkin.scheme");
	loadScheme("VanillaSkin.scheme");
	loadScheme("VanillaCommonDialogs.scheme");
	loadLayout("SimpleDebug.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(false);

	DebugShapesButton = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(12));
	DebugShapesButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugShapesClicked, this));

	closePushButton = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(99)->getChild(100));
	closePushButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonClicked, this));

	mapa = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(20));
	mapa->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onMapClicked, this));

	DebugNetwork= static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(11));
	DebugNetwork->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugNetworkClicked, this));

	DebugIA = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(14));
	DebugIA->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugIAClicked, this));

	
	NetworkWindow = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(60));
	

	botJuliyo = new Enemy_Bot("BOTJULIYO");
	botJuliyo->inicializar();
	botJuliyo->cargarContenido();
	botJuliyo->setPosition(Map::i().searchSpawnPoint());

	/*botTonire = new Enemy_Bot("BOTTONIRE");
	botTonire->inicializar();
	botTonire->cargarContenido();
	botTonire->setPosition(Map::i().searchSpawnPoint());

	botRucri = new Enemy_Bot("BOTRUCRI");
	botRucri->inicializar();
	botRucri->cargarContenido();
	botRucri->setPosition(Map::i().searchSpawnPoint());*/

}

bool DebugMenuGUI::onDebugShapesClicked(const CEGUI::EventArgs & e) {
	GraphicEngine::i().toggleDebug();
	return true;
}
bool DebugMenuGUI::onDebugNetworkClicked(const CEGUI::EventArgs & e) {
	NetworkWindow->setVisible(!NetworkWindow->isVisible());
	return true;
}
bool DebugMenuGUI::onDebugIAClicked(const CEGUI::EventArgs & e) {
	mapa->setVisible(!mapa->isVisible());
	return true;
}

bool DebugMenuGUI::onCloseMenuButtonClicked(const CEGUI::EventArgs & e) {
	getContext()->getRootWindow()->getChild(0)->getChild(10)->setAlpha(0.0f);
	debugInput = !debugInput;
	showMouseCursor(debugInput);
	GraphicEngine::i().getActiveCamera()->setInputReceiver(!debugInput);
	mapa->setVisible(debugInput);
	return true;
}

bool DebugMenuGUI::onMapClicked(const CEGUI::EventArgs & e) {
	float x = getContext()->getMouseCursor().getPosition().d_x;
	float y = getContext()->getMouseCursor().getPosition().d_y;
	std::cout << "Se pincha en la posicion: x= " << x << " y= " << y << std::endl;
	float nodoX=y/3+6;
	float nodoY=x/3+2;
	std::cout << "El bot ira a la posicion: x= " << nodoX << " y= " << nodoY << std::endl;
	botJuliyo->createPathToPosition(Vec2f(nodoX, nodoY));
	/*botTonire->createPathToPosition(Vec2f(nodoX, nodoY));
	botRucri->createPathToPosition(Vec2f(nodoX, nodoY));*/


	return true;
}