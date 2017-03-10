#include <iostream>
#include "Game.h"
#include "MastEventReceiver.hpp"
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

#include <Map.h>
#include <GUIManager.h>

#include <PathPlanner.h>
#include <Enemy_Bot.h>

#include <NetworkManager.h>

#include <Settings.h>

#include <World.h>

const int Game::server_port = 65535;
const Time Game::timePerFrame = seconds(1.f / 15.f);



Game::Game() : stateStack(StateStack::i())
{

}


Game::~Game()
{
}

void Game::run()
{
	//Game loop from Bullet Physics documentation example

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

				if (NetworkManager::i().isConnected()) {
					NetworkManager::i().updateNetwork(time_client_curr - time_client_prev);
				}
				

				time_client_prev = time_client_curr;

			}

			if (GraphicEngine::i().isWindowActive()) {
				interpolation = (float)std::min(1.f, dt.asSeconds() / timePerFrame.asSeconds());

				render(interpolation, timePerFrame);
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
	GraphicEngine::i().inicializar();
	

	Player *player = new Player("UNDEFINED", RakNet::UNASSIGNED_RAKNET_GUID);

	player->m_network->inicializar();
	
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
}


