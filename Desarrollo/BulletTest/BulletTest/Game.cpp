#include <iostream>
#include <algorithm>
#include "Game.h"
#include "MastEventReceiver.hpp"
#include "Otros\Clock.hpp"
#include "Motor\PhysicsEngine.h"
#include "Entities\EntityManager.h"
#include "Entities\PhysicsEntity.h"
#include "Motor\GraphicEngine.h"
#include "Motor\SceneNode.h"
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
	Time timeSinceLastUpdate = Time::Zero;

	inicializar();
	
	while (GraphicEngine::i().isRuning()) {
		if (GraphicEngine::i().isWindowActive()) {
			Time elapsedTime = clock.restart();
			timeSinceLastUpdate += elapsedTime;
			MastEventReceiver::i().endEventProcess();
			
			processEvents();
			//Llevamos control en las actualizaciones por frame
			while (timeSinceLastUpdate > timePerFrame) // 15 veces/segundo
			{
				timeSinceLastUpdate -= timePerFrame;
				//Realizamos actualizaciones
				update(timePerFrame);
			}
			
			interpolation = (float)min(1.f, timeSinceLastUpdate.asSeconds() / timePerFrame.asSeconds());
			render(interpolation, timePerFrame);
			
		}
			MastEventReceiver::i().startEventProcess();
	}
	GraphicEngine::i().apagar();
}


//Tenemos que hacer patron fachada
void Game::inicializar()
{
	

	//inicializamos bullet
	PhysicsEngine::i().inicializar();
	GraphicEngine::i().inicializar();


	player = new Player();

	enemy = new Enemy();

	///////////////////////////////////////////////////////////////
	SceneNode* suelo = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt = new PhysicsEntity(suelo, "");
	sueloEnt->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt, Vec3<float>(100, 5.f, 100), 0));
	//sueloEnt->rotate(Vec3<float>(0.1, 0, 0));
	///////////////////////////////////////////////////////////////

	SceneNode* suelo2 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt2 = new PhysicsEntity(suelo2, "");
	sueloEnt2->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt2, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt2->rotate(Vec3<float>(90 * PI / 180.0,0,0));
	///////////////////////////////////////////////////////////////

	SceneNode* suelo3 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt3 = new PhysicsEntity(suelo3, "");
	sueloEnt3->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt3, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt3->rotate(Vec3<float>(0, 0, 35));
	sueloEnt3->setPosition(Vec3<float>(0, 0, 60));

	EntityManager::i().inicializar();

	EntityManager::i().cargarContenido();


	// Add camera
	//camara tipo fps
	GraphicEngine::i().createCamera(Vec3<float>(0,300,0), Vec3<float>(10,0,10));
	GraphicEngine::i().setCameraEntity(player);

}

void Game::processEvents()
{
	EntityManager::i().handleInput();
}

void Game::update(Time elapsedTime)
{
	
	PhysicsEngine::i().update(elapsedTime);
	EntityManager::i().update(elapsedTime);
	MessageHandler::i().update();
}

void Game::render(float interpolation, Time elapsedTime)
{
	EntityManager::i().updateRender(interpolation);


	GraphicEngine::i().updateCamera();


	GraphicEngine::i().renderAll();

}

