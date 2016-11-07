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
	sueloEnt2->rotate(Vec3<float>(90 * PI / 180.0,0, 0));
	sueloEnt2->setPosition(Vec3<float>(-50, 0, 0));
	///////////////////////////////////////////////////////////////

	SceneNode* suelo3 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt3 = new PhysicsEntity(suelo3, "");
	sueloEnt3->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt3, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt3->rotate(Vec3<float>(0, 0, 90 * PI / 180.0));
	sueloEnt3->setPosition(Vec3<float>(0, 0, -50));

	//////////////////////////////////////////////////////////////////////

	SceneNode* suelo4 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(25, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt4 = new PhysicsEntity(suelo4, "");
	sueloEnt4->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt4, Vec3<float>(25, 5.f, 100), 0));
	sueloEnt4->rotate(Vec3<float>(0, 0, 30 * PI / 180.0));
	sueloEnt4->setPosition(Vec3<float>(60, -25, 40));

	///////////////////////////////////////////////////////////////////////

	SceneNode* suelo5 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(25, 5.f, 50), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt5 = new PhysicsEntity(suelo5, "");
	sueloEnt5->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt5, Vec3<float>(25, 5.f, 50), 0));
	sueloEnt5->rotate(Vec3<float>(0, 0, 0));
	sueloEnt5->setPosition(Vec3<float>(60, 0, -25));


	///////////////////////////////////////////////////////////////

	SceneNode* suelo6 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt6 = new PhysicsEntity(suelo6, "");
	sueloEnt6->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt6, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt6->rotate(Vec3<float>(90 * PI / 180.0, 0, 0));
	sueloEnt6->setPosition(Vec3<float>(75, 0, 0));
	///////////////////////////////////////////////////////////////

	SceneNode* suelo7 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt7 = new PhysicsEntity(suelo7, "");
	sueloEnt7->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt7, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt7->rotate(Vec3<float>(0, 0, 90 * PI / 180.0));
	sueloEnt7->setPosition(Vec3<float>(0, 0, 50));

	//////////////////////////////////////////////////////////////////////

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

	//Teclas debug
	if (MastEventReceiver::i().keyPressed(KEY_KEY_1)) {
		GraphicEngine::i().toggleDebug();
	}
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_2)) {
		GraphicEngine::i().toggleCamera();
	}
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

