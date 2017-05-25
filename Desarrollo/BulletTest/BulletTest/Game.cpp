#include <iostream>
#include "Game.h"
#include <Clock.hpp>
#include <PhysicsEngine.h>
#include <GraphicEngine.h>
#include <SceneNode.h>
#include <MessageHandler.h>
#include <EventSystem.h>
#include <MapLoader.h>
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <TriggerSystem.h>
#include <MessageHandler.h>
#include <TimePerFrame.h>

#include <Map.h>
#include <GUIManager.h>

#include <PathPlanner.h>
#include <Enemy_Bot.h>

#include <NetworkManager.h>

#include <Settings.h>

#include <World.h>

#include <steam_api.h>

#include "global.h"

const int Game::server_port = 65535;
//const Time Game::timePerFrame = seconds(1.f / 15.f);

Game::Game() : stateStack(StateStack::i())
{

}


Game::~Game()
{
}

void Game::run()
{
	try{
	//Game loop from Bullet Physics documentation example
	TimePerFrameClass::timePerFrameDefault();

	Clock clock;

	inicializar();

	/// The physics clock is just used to run the physics and runs asynchronously with the gameclock
	Time time_physics_prev, time_physics_curr, time_client_prev, time_client_curr;

	/// There's an inner loop in here where things happen once every TickMs. These variables are for that.
	Time time_gameclock;

	/// Reset all of our timers
	time_physics_prev = time_physics_curr = clock.getElapsedTime();
	time_gameclock = clock.getElapsedTime();

	
	while (GraphicEngine::i().isWindowActive()) {

			///Las fisicas se ejecutan 60 veces por segundo

			time_physics_curr = clock.getElapsedTime();

			PhysicsEngine::i().update(time_physics_curr - time_physics_prev);

			time_physics_prev = time_physics_curr;


			// Game Clock part of the loop
			/*  This ticks once every TickMs milliseconds on average */
			Time dt = clock.getElapsedTime() - time_gameclock;

			//Llevamos control en las actualizaciones por frame
			while (dt >= TimePerFrameClass::GetTimePerFrame()) // 15 veces/segundo
			{
				dt -= TimePerFrameClass::GetTimePerFrame();
				time_gameclock += TimePerFrameClass::GetTimePerFrame();

				processEvents();

				//Realizamos actualizaciones
				update(TimePerFrameClass::GetTimePerFrame());

				time_client_curr = clock.getElapsedTime();

				if (NetworkManager::i().isConnected()) {
					NetworkManager::i().updateNetwork(time_client_curr - time_client_prev);
				}
				

				time_client_prev = time_client_curr;

			}
			if (GraphicEngine::i().exit) {
				break;
			}
			if (GraphicEngine::i().isWindowActive()) {
				interpolation = (float)std::min(1.f, dt.asSeconds() / TimePerFrameClass::GetTimePerFrame().asSeconds());

				render(interpolation, TimePerFrameClass::GetTimePerFrame());
			}
		
		

			
	}

	clear();
	}
	catch(std::exception e){
		clear();
		std::cout << e.what() << std::endl;
	}
	/*EntityManager::i().apagar();
	GraphicEngine::i().apagar();
	PhysicsEngine::i().apagar();
	TriggerSystem::i().apagar();

	NetworkManager::i().apagar();

	MessageHandler::i().borrarContenido();*/

}

void Game::inicializarRutas() {

	//We get the resource provider
	ResourceProvider& resourceProvider = Settings::i().GetResourceProvider();

	resourceProvider.setResourceGroupDirectory("characters", "../media/personaje1");
	resourceProvider.setResourceGroupDirectory("weapons", "../media/Weapons");
	resourceProvider.setResourceGroupDirectory("sounds", "../media/Sounds");
	resourceProvider.setResourceGroupDirectory("bullets", "../media/Bullets");
	resourceProvider.setResourceGroupDirectory("props", "../media/Props/");
}

void Game::inicializar()
{
	
	//Cargamos configuraciones de la aplicación y esablecemos rutas para las resources
	Settings::i().LoadSettings();
	inicializarRutas();

	if (USING_STEAM) {
		//Inicializamos la API de Steam :)
		if (SteamAPI_RestartAppIfNecessary(480)) {
			// if Steam is not running or the game wasn't started through Steam, SteamAPI_RestartAppIfNecessary starts the 
			// local Steam client and also launches this game again.

			// Once you get a public Steam AppID assigned for this game, you need to replace k_uAppIdInvalid with it and
			// removed steam_appid.txt from the game depot.
			printf("Fatal Error\n", "Steam must be running to play this game (SteamAPI_RestartAppIfNecessary() failed).\n");
			//exit(0);
		}

		if (!SteamAPI_Init()) {
			//OutputDebugString("SteamAPI_Init() failed\n");
			printf("Fatal Error\n", "Steam must be running to play this game (SteamAPI_Init() failed).\n");
			//exit(0);
		}
	}

	GraphicEngine::i().inicializar();
	

	GraphicEngine::i().createCamera("CamaraPlayer", Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));

	//Inicializamos el MENU
	StateStack::i().GetCurrentState()->Inicializar();

	
}

bool Game::processEvents()
{
	stateStack.GetCurrentState()->HandleEvent();

	return true;
}

void Game::update(Time elapsedTime)
{

	stateStack.GetCurrentState()->Update(elapsedTime);

}

void Game::render(float interpolation, Time elapsedTime)
{
	

	GraphicEngine::i().getDevice().updateCurrentFrame();
	GraphicEngine::i().getDevice().doMovement();
	stateStack.GetCurrentState()->Render(interpolation, elapsedTime);

}

void Game::clear()
{
	GraphicEngine::i().apagar();

	SoundManager::i().drop();

	stateStack.GetCurrentState()->Clear();
}


