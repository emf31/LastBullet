#include "LoadingState.h"
#include <StateStack.h>
#include <AssetsReader.h>
#include <TimePerFrame.h>
#include <Estructuras.h>
#include <NetworkManager.h>
#include <SoundManager.h>
#include <Settings.h>
#include <Engine/AnimationReader.h>

LoadingState::LoadingState()
{
}

LoadingState::~LoadingState()
{
}

void LoadingState::Inicializar()
{
	SoundManager::i().stopAllSounds();
	SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("LoadingSong.mp3", "sounds"), Sound::type::music,true);
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

void LoadingState::NotificarServerCargaCompletada() {
	RakID rak;
	rak.guid = NetworkManager::i().getNetPlayer()->getMyGUID();

	NetworkManager::i().dispatchMessage(rak, CARGA_COMPLETA);

	

}

void LoadingState::Update(Time timeElapsed)
{
	if (!needRender) {

		if (!colaAssets.empty()) {
			std::string path = colaAssets.front();
			ResourceManager::i().getMesh(path);
			colaAssets.pop();
			loadingStateGUI.setAssetName(path);
			loadingStateGUI.update();
		}

		if (colaAssets.empty()) {

			if (queueAnimaciones.empty()) {
				TimePerFrameClass::timePerFrameDefault();

				StateStack::i().GetCurrentState()->Clear();
				StateStack::i().SetCurrentState(States::ID::InGame);
				StateStack::i().GetCurrentState()->Inicializar();

				//Notify to other players
				NotificarServerCargaCompletada();
			}
			
			AnimationStruct& pathAnim = queueAnimaciones.front();
			ResourceManager::i().getAnimationMesh(pathAnim.path, pathAnim.numAnimations);
			queueAnimaciones.pop();

			loadingStateGUI.setAssetName(pathAnim.path);
			loadingStateGUI.update();
		}

		

		needRender = true;
	}

		
}

void LoadingState::Render(float interpolation, Time elapsedTime)
{

	GraphicEngine::i().renderAll();

	needRender = false;
}

void LoadingState::readAllAssets()
{
	AssetsReader::read("../media/Props",colaAssets);
	AssetsReader::read("../media/Weapons", colaAssets);
	AssetsReader::read("../media/bullets", colaAssets);
	queueAnimaciones.push(AnimationStruct{ "../media/personaje1", 191 });

}




