#include "Menu.h"
#include <SoundManager.h>

#include <NetworkManager.h>
#include "../global.h"
Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Inicializar()
{
	//Creamos la red (abrir server, crear peer, conectarse, etc.) 
	NetworkManager::i().configureNetwork();

	menuGUI.inicializar();

	//GraphicEngine::i().getActiveCamera()->setInputReceiver(false);

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	GraphicEngine::i().enableMouse(true);

	SoundManager::i().stopAllSounds();
	SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("MenuSong2.mp3", "sounds"), Sound::type::music,true);
	//SoundManager::i().playSound("../media/shoot.mp3", static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getRenderState()->getPosition());
}

void Menu::Clear()
{
	menuGUI.destroy();
	//TODO: Terminar Steam
}

void Menu::HandleEvent()
{

	if (Input::i().leftMouseDown()) {

		menuGUI.injectLeftMouseButton();

	}
	else if (Input::i().leftMouseUp()) {

		menuGUI.injectLeftMouseButtonUp();

	}
	menuGUI.injectKeyUp(Input::i().getLastTextInput());
	menuGUI.injectChar(Input::i().getLastTextInput());


}

void Menu::Update(Time timeElapsed)
{
	menuGUI.update();

	if (USING_STEAM) {
		NetworkManager::i().getNetPlayer()->receiveSteamPackets();
	}

	Input::i().endEventProcess();
}

void Menu::Render(float interpolation, Time elapsedTime)
{

	float mouseX = (float)Input::i().getMouseX();
	float mouseY = (float)Input::i().getMouseY();


	//GUI
	menuGUI.injectMousePosition(mouseX, mouseY);

	
	GraphicEngine::i().renderAll();
}






