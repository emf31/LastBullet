#include "Menu.h"

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
	menuGUI.inicializar();

	//GraphicEngine::i().getActiveCamera()->setInputReceiver(false);

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	GraphicEngine::i().enableMouse(true);
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


}

void Menu::Update(Time timeElapsed)
{
	menuGUI.update();
	if (USING_STEAM) {
		NetworkManager::i().getNetPlayer()->receiveSteamPackets();
	}
}

void Menu::Render(float interpolation, Time elapsedTime)
{

	float mouseX = (float)Input::i().getMouseX();
	float mouseY = (float)Input::i().getMouseY();


	//GUI
	menuGUI.injectMousePosition(mouseX, mouseY);

	GraphicEngine::i().renderAll();
}






