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
	
	
}

void Menu::Clear()
{
	
}

void Menu::HandleEvent()
{

	if (MastEventReceiver::i().leftMouseDown()) {

		//debugMenu.injectLeftMouseButton();

	}
	else if (MastEventReceiver::i().leftMouseUp()) {

		//debugMenu.injectLeftMouseButtonUp();

	}


}

void Menu::Update(Time timeElapsed)
{
	
}

void Menu::Render(float interpolation, Time elapsedTime)
{
	
}






