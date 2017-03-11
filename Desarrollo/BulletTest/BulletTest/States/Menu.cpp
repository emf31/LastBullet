#include "Menu.h"


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

	if (Input::i().leftMouseDown()) {

		menuGUI.injectLeftMouseButton();

	}
	else if (Input::i().leftMouseUp()) {

		menuGUI.injectLeftMouseButtonUp();

	}


}

void Menu::Update(Time timeElapsed)
{
	
}

void Menu::Render(float interpolation, Time elapsedTime)
{
	//GUI
	menuGUI.injectMousePosition((float)Input::i().mouse.X, (float)Input::i().mouse.Y);

	GraphicEngine::i().renderAll();
}






