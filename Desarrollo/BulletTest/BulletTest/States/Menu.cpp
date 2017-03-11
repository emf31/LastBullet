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

	//GraphicEngine::i().getActiveCamera()->setInputReceiver(false);

	
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

	float mouseX = (float)Input::i().getMouseX();
	float mouseY = (float)Input::i().getMouseY();

	//GUI
	menuGUI.injectMousePosition(mouseX, mouseY);

	GraphicEngine::i().renderAll();
}






