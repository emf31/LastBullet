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
	loadScheme("LastBulletCarga.scheme");
	loadLayout("LoadingStateGUI.layout");
	setMouseCursor("AlfiskoSkin/MouseArrow");
	showMouseCursor(true);

	//Menu principal
	ProgressBar = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	Label = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));
	totalAssets = 1;
	assetActual = 0;

}

void LoadingStateGUI::update()
{
	assetActual++;
	ProgressBar->setProgress((float)assetActual / (float)totalAssets);
	Label->setText(Assetname.c_str());
}

void LoadingStateGUI::handleEvent(Event * ev)
{
}

void LoadingStateGUI::setTotalAssets(int total)
{
	totalAssets = total;
}

void LoadingStateGUI::setAssetName(std::string & name)
{
	Assetname = name;
}
