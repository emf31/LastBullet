#include <LoadingStateGUI.h>
#include <iostream>
#include <NetPlayer.h>

LoadingStateGUI::LoadingStateGUI() : GUI() {
}

void LoadingStateGUI::inicializar() {
	init("../GUI", "LoadingStateGUI");
	loadScheme("SampleBrowser.scheme");
	loadScheme("AlfiskoSkin.scheme");
	loadScheme("Generic.scheme");
	loadScheme("LastBulletMenuBackground.scheme");
	loadLayout("LoadingStateGUI.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(true);

	//Menu principal



}

void LoadingStateGUI::update()
{
	int a;
}

void LoadingStateGUI::handleEvent(Event * ev)
{

}