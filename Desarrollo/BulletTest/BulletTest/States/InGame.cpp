#include "InGame.h"
#include <EntityManager.h>
#include <TriggerSystem.h>
#include <EventSystem.h>
#include <PhysicsEngine.h>
#include <GraphicEngine.h>
#include <MessageHandler.h>
#include <GUIManager.h>
#include "../MastEventReceiver.hpp"
#include <World.h>

InGame::InGame() : ingameGUI(), debugMenu()
{
}

InGame::~InGame()
{
}

void InGame::Inicializar()
{

	PhysicsEngine::i().inicializar();

	ingameGUI.inicializar();
	debugMenu.inicializar();

	World::i().inicializar();

	
	
}

void InGame::Clear()
{
	EntityManager::i().apagar();
	
	TriggerSystem::i().apagar();

	MessageHandler::i().borrarContenido();
}

void InGame::HandleEvent()
{

	if (!debugMenu.debugInput) {
		EntityManager::i().getEntity(PLAYER)->handleInput();
	}

	//Teclas debug
	if (MastEventReceiver::i().keyPressed(KEY_KEY_1)) {

		GraphicEngine::i().toggleDebug();

	}
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_2)) {

		GraphicEngine::i().toggleCamera();

	}
	else if (MastEventReceiver::i().keyReleased(KEY_TAB)) {

		ingameGUI.setTablaVisible(false);

	}
	else if (MastEventReceiver::i().keyDown(KEY_TAB)) {

		ingameGUI.setTablaVisible(true);
		World::i().getPartida()->muestraTabla();

	}
	else if (MastEventReceiver::i().keyPressed(KEY_F2)) {

		debugMenu.debugInput = !debugMenu.debugInput;
		//GraphicEngine::i().setCursorVisible(GraphicEngine::i().getGui().debugInput);
		debugMenu.showMouseCursor(debugMenu.debugInput);
		GraphicEngine::i().getActiveCamera()->setInputReceiver(!debugMenu.debugInput);
		debugMenu.getContext()->getRootWindow()->getChild(0)->getChild(10)->setAlpha(1.0f);

		//TODO llevarlo al otro sitio
		//debugMenu.mapa->setVisible(debugMenu.debugInput);

	}
	else if (MastEventReceiver::i().leftMouseDown()) {

		debugMenu.injectLeftMouseButton();

	}
	else if (MastEventReceiver::i().leftMouseUp()) {

		debugMenu.injectLeftMouseButtonUp();

	}


}

void InGame::Update(Time timeElapsed)
{
	PhysicsEngine::i().cleanDeleteObjects();
	EntityManager::i().cleanDeleteQueue();


	EntityManager::i().update(timeElapsed);

	TriggerSystem::i().Update();

	PhysicsEngine::i().notifyCollisions();

	MessageHandler::i().update();

	EventSystem::i().update();

	GUIManager::i().updateAllGuis();
}

void InGame::Render(float interpolation, Time elapsedTime)
{
	EntityManager::i().updateRender(interpolation);

	GraphicEngine::i().updateCamera();

	//GUI
	debugMenu.injectMousePosition(MastEventReceiver::i().mouseX(), MastEventReceiver::i().mouseY());

	GraphicEngine::i().renderAll();
}






