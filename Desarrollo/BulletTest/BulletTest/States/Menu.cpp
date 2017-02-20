#include "Menu.h"
#include "../MastEventReceiver.hpp"


Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Inicializar()
{
	menuGUI.inicializar();
	
}

void Menu::Clear()
{
	menuGUI.destroy();
}

void Menu::HandleEvent()
{

	if (MastEventReceiver::i().leftMouseDown()) {

		menuGUI.injectLeftMouseButton();

	}
	else if (MastEventReceiver::i().leftMouseUp()) {

		menuGUI.injectLeftMouseButtonUp();

	}


}

void Menu::Update(Time timeElapsed)
{
	
}

void Menu::Render(float interpolation, Time elapsedTime)
{
	//GUI
	menuGUI.injectMousePosition(MastEventReceiver::i().mouseX(), MastEventReceiver::i().mouseY());

	GraphicEngine::i().renderAll();
}






