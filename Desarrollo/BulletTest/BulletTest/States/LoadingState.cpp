#include "LoadingState.h"
#include <StateStack.h>
#include <AssetsReader.h>
#include <TimePerFrame.h>


LoadingState::LoadingState()
{
}

LoadingState::~LoadingState()
{
}

void LoadingState::Inicializar()
{
	loadingStateGUI.inicializar();
	TimePerFrameClass::timePerFrameLoadingState();
	readAllAssets();
	loadingStateGUI.setTotalAssets(colaAssets.size());
	needRender = false;

}

void LoadingState::Clear()
{
	loadingStateGUI.destroy();
}

void LoadingState::HandleEvent()
{

	if (Input::i().leftMouseDown()) {

	loadingStateGUI.injectLeftMouseButton();

	}
	else if (Input::i().leftMouseUp()) {

	loadingStateGUI.injectLeftMouseButtonUp();

	}


}

void LoadingState::Update(Time timeElapsed)
{
	if (!needRender) {
	//std::cout << "Entro en update" << std::endl;
	//loadingStateGUI.update();
	//std::cout << timeElapsed.asMilliseconds() << std::endl;
	if (!colaAssets.empty()) {
		std::string path = colaAssets.front();
		ResourceManager::i().getMesh(path);
		colaAssets.pop();
		loadingStateGUI.setAssetName(path);
		loadingStateGUI.update();
	}
	
	if (colaAssets.empty()) {
	//	float mytime = pruebas.getElapsedTime().asSeconds();
		TimePerFrameClass::timePerFrameDefault();
		StateStack::i().GetCurrentState()->Clear();
		StateStack::i().SetCurrentState(States::ID::InGame);
		StateStack::i().GetCurrentState()->Inicializar();
	}
	needRender = true;
}

		
}

void LoadingState::Render(float interpolation, Time elapsedTime)
{
//	std::cout << "Entro en render" << std::endl;
	/*float mouseX = (float)Input::i().getMouseX();
	float mouseY = (float)Input::i().getMouseY();

	//GUI
	loadingStateGUI.injectMousePosition(mouseX, mouseY);*/

	GraphicEngine::i().renderAll();

	needRender = false;
}

void LoadingState::readAllAssets()
{
	AssetsReader::read("../media/Props",colaAssets);
	AssetsReader::read("../media/arma", colaAssets);
	AssetsReader::read("../media/bullets", colaAssets);
	AssetsReader::read("../media/Granada", colaAssets);
}




