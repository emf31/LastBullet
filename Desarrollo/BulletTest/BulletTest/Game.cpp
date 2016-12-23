#include <iostream>
#include <algorithm>
#include "Game.h"
#include "MastEventReceiver.hpp"
#include "Otros\Clock.hpp"
#include "Motor\PhysicsEngine.h"
#include "Entities\EntityManager.h"
#include "Entities\PhysicsEntity.h"
#include "Entities\LifeObject.h"
#include "Entities\WeaponDrops\RocketLauncherDrop.h"
#include "Entities\WeaponDrops\PistolaDrop.h"
#include "Entities\WeaponDrops\AsaltoDrop.h"
#include "Entities/GroupEntity.h"
#include "Motor\GraphicEngine.h"
#include "Motor\SceneNode.h"
#include "Handlers\MessageHandler.h"
#include "States\StateStack.hpp"
#include "Motor\MapLoader.h"


#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <thread> 
#include "Motor de Red\Cliente.h"
#include "TriggerSystem.h"

#define SERVER_PORT 65535

#include "Handlers\MessageHandler.h"
#include <Windows.h>


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
	Time time_physics_prev, time_physics_curr;

	/// There's an inner loop in here where things happen once every TickMs. These variables are for that.
	Time time_gameclock;

	/// Reset all of our timers
	time_physics_prev = time_physics_curr = clock.getElapsedTime();
	time_gameclock = clock.getElapsedTime();

	bool wantToExit = false;
	

	while (GraphicEngine::i().isRuning()) {
		//if (GraphicEngine::i().isWindowActive()) {
		//if (Cliente::i().isConected() ) {

		///Las fisicas se ejecutan 60 veces por segundo

		time_physics_curr = clock.getElapsedTime();

		if (GraphicEngine::i().isWindowActive()) {
			PhysicsEngine::i().update(time_physics_curr - time_physics_prev);
		}

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
				if (processEvents()) {
					wantToExit = true;
				}
				MastEventReceiver::i().startEventProcess();

				//Realizamos actualizaciones
				update(timePerFrame);

				if (Cliente::i().isConected()) {
					Cliente::i().update();
				}

			}
		if (GraphicEngine::i().isWindowActive()) {

			interpolation = (float)min(1.f, dt.asSeconds() / timePerFrame.asSeconds());

			render(interpolation, timePerFrame);




			if (wantToExit) {
				break;
			}
		}

		
		//}
		
	}

	
	EntityManager::i().apagar();
	GraphicEngine::i().apagar();
	PhysicsEngine::i().apagar();
	TriggerSystem::i().apagar();

	if (Cliente::i().isConected()) {
		Cliente::i().apagar();
	}
	
	MessageHandler::i().borrarContenido();
	
}


//Tenemos que hacer patron fachada
void Game::inicializar()
{
	

	//inicializamos bullet
	PhysicsEngine::i().inicializar();
	GraphicEngine::i().inicializar();
	//Esto resetea valores
	EntityManager::i().inicializarEntityManager();

	MapLoader map;
	map.readMap("..\rust_export.txt");

	GroupEntity *ge = new GroupEntity("GrupoLifeObjects",9000);
	ge->addEntityList(EntityManager::i().getLifeObjects());
	TriggerSystem::i().RegisterEntity(ge);

	GroupEntity *grupoAsaltos = new GroupEntity("grupoAsalto", 9001);
	grupoAsaltos->addEntityList(EntityManager::i().getAsalto());
	TriggerSystem::i().RegisterEntity(grupoAsaltos);

	GroupEntity *grupoPistolas = new GroupEntity("grupoPistolas", 9002);
	grupoPistolas->addEntityList(EntityManager::i().getPistolas());
	TriggerSystem::i().RegisterEntity(grupoPistolas);

	GroupEntity *grupoRockets = new GroupEntity("grupoRockets", 9003);
	grupoRockets->addEntityList(EntityManager::i().getRockets());
	TriggerSystem::i().RegisterEntity(grupoRockets);


	/*Enemy *e = new Enemy("Rambo");
	e->inicializar();
	e->cargarContenido();
	e->setPosition(Vec3<float>(-4,-55, 400));

	Enemy *e1 = new Enemy("Chuck Norris");
	e1->inicializar();
	e1->cargarContenido();
	e1->setPosition(Vec3<float>(216, -2.6, 156.3));

	Enemy *e2 = new Enemy("Messi");
	e2->inicializar();
	e2->cargarContenido();
	e2->setPosition(Vec3<float>(74.06, 17.6, -66.41));*/

	/*Enemy *e = new Enemy("Son Goku");
	e->inicializar();
	e->cargarContenido();
	e->setPosition();

	Enemy *e = new Enemy("Bruce Lee");
	e->inicializar();
	e->cargarContenido();
	e->setPosition();*/

	int a;
	/*do {
		std::cout << "Elige un modo:" << std::endl;
		std::cout << "[1] - Un jugador" << std::endl;
		std::cout << "[2] - Multijugador" << std::endl;

		std::cin >> a;
	} while (a != 1 && a != 2);*/
	
	a = 1;
	if (a == 1) {
		//LLama al inicializar de todas las entities
		EntityManager::i().inicializar();

		EntityManager::i().cargarContenido();

		//Creamos el player
		Player* player = new Player("NombreA", map.getSpawnPoints());
		player->inicializar();
		player->cargarContenido();

	}
	else {
		EntityManager::i().inicializar();

		EntityManager::i().cargarContenido();

		//raknet
		Cliente::i().inicializar();

		
		//Bucle infinito hasta que se conecte
		while (Cliente::i().isConected() == false) {
			Cliente::i().update();
		}

		Cliente::i().createPlayer(map.getSpawnPoints());

		//enviamos los paquetes del vida al servidor para que los cree
		std::list<Entity*>lifeObj = EntityManager::i().getLifeObjects();
		for (std::list<Entity*>::const_iterator it = lifeObj.begin(); it != lifeObj.end(); ++it) {
			Cliente::i().nuevaVida((*it)->getID());
		}
			
		//enviamos los paquetes de armas al servidor para que los cree

		std::list<Entity*>weapon = EntityManager::i().getWeapons();
		for (std::list<Entity*>::const_iterator it = weapon.begin(); it != weapon.end(); ++it) {
			Cliente::i().nuevaArma((*it)->getID());
		}


	}

	
	

}

bool Game::processEvents()
{
	EntityManager::i().handleInput();

	//Teclas debug
	if (MastEventReceiver::i().keyPressed(KEY_KEY_1)) {
		GraphicEngine::i().toggleDebug();
	}
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_2)) {
		GraphicEngine::i().toggleCamera();
	}
	else if (MastEventReceiver::i().keyPressed(KEY_TAB)) {
		EntityManager::i().muestraTabla();
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
}

void Game::render(float interpolation, Time elapsedTime)
{

	EntityManager::i().updateRender(interpolation);

	GraphicEngine::i().updateCamera();

	GraphicEngine::i().renderAll();

}


