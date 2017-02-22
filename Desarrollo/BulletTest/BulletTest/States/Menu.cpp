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

	if (MastEventReceiver::i().keyPressed(KEY_KEY_0))		{ menuGUI.escribir("0"); }
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_1))	{ menuGUI.escribir("1"); }
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_2))	{ menuGUI.escribir("2"); }
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_3))	{ menuGUI.escribir("3"); }
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_4))	{ menuGUI.escribir("4"); }
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_5))	{ menuGUI.escribir("5"); }
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_6))	{ menuGUI.escribir("6"); }
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_7))	{ menuGUI.escribir("7"); }
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_8))	{ menuGUI.escribir("8"); }
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_9))	{ menuGUI.escribir("9"); }
	else if (MastEventReceiver::i().keyPressed(KEY_PERIOD)) { menuGUI.escribir("."); }
	else if (MastEventReceiver::i().keyPressed(KEY_BACK)) { menuGUI.borrarUltimo(); }

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






