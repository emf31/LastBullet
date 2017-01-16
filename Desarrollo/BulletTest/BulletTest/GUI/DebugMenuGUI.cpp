#include "DebugMenuGUI.h"


void DebugMenuGUI::update() {
}

void DebugMenuGUI::inicializar() {
	init("../GUI", GraphicEngine::i().getDevice());

	loadScheme("AlfiskoSkin.scheme");
	loadLayout("SimpleDebug.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(false);

	DebugShapesButton = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(12));
	DebugShapesButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onDebugShapesClicked, this));

	closePushButton = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(99)->getChild(100));
	closePushButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&DebugMenuGUI::onCloseMenuButtonClicked, this));


}

bool DebugMenuGUI::onDebugShapesClicked(const CEGUI::EventArgs & e) {
	GraphicEngine::i().toggleDebug();
	return true;
}

bool DebugMenuGUI::onCloseMenuButtonClicked(const CEGUI::EventArgs & e) {
	getContext()->getRootWindow()->getChild(0)->getChild(10)->setAlpha(0.0f);
	debugInput = !debugInput;
	showMouseCursor(debugInput);
	GraphicEngine::i().getActiveCamera()->setInputReceiver(!debugInput);
	return true;
}
