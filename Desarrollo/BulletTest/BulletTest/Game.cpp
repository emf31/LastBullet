#include <iostream>
#include "Game.h"
#include "MastEventReceiver.hpp"
#include <Clock.hpp>
#include <PhysicsEngine.h>
#include <EntityManager.h>
#include <PhysicsEntity.h>
#include <LifeObject.h>
#include <WeaponDrops/RocketLauncherDrop.h>
#include <WeaponDrops/PistolaDrop.h>
#include <WeaponDrops/AsaltoDrop.h>
#include <GraphicEngine.h>
#include <SceneNode.h>
#include <MessageHandler.h>
#include <EventSystem.h>
#include <StateStack.hpp>
#include <MapLoader.h>
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <TriggerSystem.h>
#include <MessageHandler.h>

#include <Map.h>
#include <GUIManager.h>

#include <PathPlanner.h>
#include <Enemy_Bot.h>

#include <NetworkManager.h>

#include <Settings.h>



const int Game::server_port = 65535;
const Time Game::timePerFrame = seconds(1.f / 15.f);



Game::Game()
{

}


Game::~Game()
{
}

void Game::run()
{
	Clock clock;

	inicializar();

	/// The physics clock is just used to run the physics and runs asynchronously with the gameclock
	Time time_physics_prev, time_physics_curr, time_client_prev, time_client_curr;

	/// There's an inner loop in here where things happen once every TickMs. These variables are for that.
	Time time_gameclock;

	/// Reset all of our timers
	time_physics_prev = time_physics_curr = clock.getElapsedTime();
	time_gameclock = clock.getElapsedTime();

	
	while (GraphicEngine::i().isRuning()) {
		if (World::i().gamestarted) {
			///Las fisicas se ejecutan 60 veces por segundo

			time_physics_curr = clock.getElapsedTime();

			//if (GraphicEngine::i().isWindowActive()) {
			PhysicsEngine::i().update(time_physics_curr - time_physics_prev);
			//}

			time_physics_prev = time_physics_curr;


			// Game Clock part of the loop
			/*  This ticks once every TickMs milliseconds on average */
			Time dt = clock.getElapsedTime() - time_gameclock;

			//Llevamos control en las actualizaciones por frame
			while (dt >= timePerFrame) // 15 veces/segundo
			{
				dt -= timePerFrame;
				time_gameclock += timePerFrame;

				MastEventReceiver::i().endEventProcess();
				processEvents();
				MastEventReceiver::i().startEventProcess();

				//Realizamos actualizaciones
				update(timePerFrame);

				time_client_curr = clock.getElapsedTime();

				NetworkManager::i().updateNetwork(time_client_curr - time_client_prev);

				time_client_prev = time_client_curr;

			}

			if (GraphicEngine::i().isWindowActive()) {
				interpolation = (float)std::min(1.f, dt.asSeconds() / timePerFrame.asSeconds());

				render(interpolation, timePerFrame);
			}
		}
		


	}




	


	EntityManager::i().apagar();
	GraphicEngine::i().apagar();
	PhysicsEngine::i().apagar();
	TriggerSystem::i().apagar();

	NetworkManager::i().apagar();


	MessageHandler::i().borrarContenido();

}



void Game::inicializar()
{


	
	Settings::i().LoadSettings();
	PhysicsEngine::i().inicializar();
	GraphicEngine::i().inicializar();


	std::string str;

	printf("Introduce un nombre \n");
	std::cin >> str;

	Player *player = new Player(str, RakNet::UNASSIGNED_RAKNET_GUID);
	player->m_network->inicializar();

	/*Enemy_Bot* bot = new Enemy_Bot("JULIYO BOT", RakNet::UNASSIGNED_RAKNET_GUID);
	bot->m_network->inicializar();*/

	

	/*while (player->m_network->isConnected() == false) {
		NetworkManager::i().updateNetwork(Time::Zero);
	}*/
	

	//world.inicializar();


	/*int a = 1;
	do {
		std::cout << "Elige un modo:" << std::endl;
		std::cout << "[1] - Un jugador" << std::endl;
		std::cout << "[2] - Multijugador" << std::endl;

		std::cin >> a;
	} while (a != 1 && a != 2);

	if (a == 1) {
		


	}
	else {
		EntityManager::i().inicializar();

		EntityManager::i().cargarContenido();

		//raknet
		Cliente::i().inicializar();


		//Bucle infinito hasta que se conecte
		while (Cliente::i().isConected() == false) {
			Cliente::i().update(Time::Zero);
		}

		

		


	}*/

	ingameGUI.inicializar();
	debugMenu.inicializar();



}

bool Game::processEvents()
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
		//partida.muestraTabla();

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

	return false;
}

void Game::update(Time elapsedTime)
{

	PhysicsEngine::i().cleanDeleteObjects();
	EntityManager::i().cleanDeleteQueue();


	EntityManager::i().update(elapsedTime);

	TriggerSystem::i().Update();

	PhysicsEngine::i().notifyCollisions();

	MessageHandler::i().update();

	EventSystem::i().update();

	GUIManager::i().updateAllGuis();


}

void Game::render(float interpolation, Time elapsedTime)
{

	EntityManager::i().updateRender(interpolation);

	GraphicEngine::i().updateCamera();

	//GUI
	debugMenu.injectMousePosition(MastEventReceiver::i().mouseX(), MastEventReceiver::i().mouseY());


	//GraphicEngine::i().getGui().update();

	GraphicEngine::i().renderAll();

}


