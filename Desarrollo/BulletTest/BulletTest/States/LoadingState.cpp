#include "LoadingState.h"
#include <StateStack.h>
#include <AssetsReader.h>


LoadingState::LoadingState()
{
}

LoadingState::~LoadingState()
{
}

void LoadingState::Inicializar()
{
	loadingStateGUI.inicializar();
	readAllAssets();

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
	loadingStateGUI.update();
	std::cout << timeElapsed.asMilliseconds() << std::endl;
	if (!colaAssets.empty()) {
		std::string path = colaAssets.front();
		ResourceManager::i().getMesh(path);
		colaAssets.pop();

	}
	
	if (colaAssets.empty()) {
		StateStack::i().GetCurrentState()->Clear();
		StateStack::i().SetCurrentState(States::ID::InGame);
		StateStack::i().GetCurrentState()->Inicializar();
	}
		
}

void LoadingState::Render(float interpolation, Time elapsedTime)
{

	float mouseX = (float)Input::i().getMouseX();
	float mouseY = (float)Input::i().getMouseY();

	//GUI
	loadingStateGUI.injectMousePosition(mouseX, mouseY);

	GraphicEngine::i().renderAll();
}

void LoadingState::readAllAssets()
{
	AssetsReader::read("../media/Props",colaAssets);
	AssetsReader::read("../media/arma", colaAssets);
	AssetsReader::read("../media/bullets", colaAssets);
	AssetsReader::read("../media/Granada", colaAssets);
}




