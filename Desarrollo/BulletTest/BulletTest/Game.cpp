#include "stdafx.h"
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
			
			interpolation = (float) min(1.f, timeSinceLastUpdate.asSeconds() / timePerFrame.asSeconds());
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
	PhysicsEngine::inicializar();
	GraphicEngine::i().inicializar();

	//Creamos el suelo
	//ISceneNode *suelo = CreateBox(Vec3<double>(0, 0, 0), Vec3<float>(50.f, 0.5f, 50.f), 0.0f);
	// = CreateBox(Vec3<double>(0, 100, 0), Vec3<float>(0.5f, 2.f, 0.5f), 1.0f);

	

	/*ISceneNode *player2 = CreateBox(Vec3<double>(5, 100, 0), Vec3<float>(0.5, 0.5, 0.5), 1.0f);
	player2->setMaterialTexture(0, irrDriver->getTexture("../media/rockwall.jpg"));

	ISceneNode *plataforma1 = CreateBox(Vec3<double>(3, 3, 0), Vec3<float>(10.f, 1.5f, 10.f), 0.0f);
	ISceneNode *plataforma2 = CreateBox(Vec3<double>(8, 8, 0), Vec3<float>(10.f, 1.5f, 10.f), 0.0f);
	ISceneNode *plataforma3 = CreateBox(Vec3<double>(13, 12, 0), Vec3<float>(10.f, 1.5f, 10.f), 0.0f);

	suelo->setMaterialTexture(0, irrDriver->getTexture("../media/wall.jpg"));
	plataforma1->setMaterialTexture(0, irrDriver->getTexture("../media/wall.jpg"));
	plataforma2->setMaterialTexture(0, irrDriver->getTexture("../media/wall.jpg"));
	plataforma3->setMaterialTexture(0, irrDriver->getTexture("../media/wall.jpg"));*/

	player = new Player();

	SceneNode* suelo = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(2000.f, 100.f, 2000.f), "../media/wall.jpg");

	PhysicsEntity *sueloEnt = new PhysicsEntity(suelo,"");
	sueloEnt->setRigidBody(PhysicsEngine::createBoxRigidBody(sueloEnt, Vec3<float>(2000.f, 100.f, 2000.f),0));

	EntityManager::i().cargarContenido();

	/*Entity *entsuelo = new Entity(suelo);
	Entity *ent = new Entity(player1);
	Entity *ent2 = new Entity(player2);
	Entity *p1 = new Entity(plataforma1);
	Entity *p2 = new Entity(plataforma2);
	Entity *p3 = new Entity(plataforma3);
	
	entities.push_back(entsuelo);
	entities.push_back(ent);
	entities.push_back(ent2);

	entities.push_back(p1);
	entities.push_back(p2);
	entities.push_back(p3);*/

	// Add camera
	//camara tipo fps
	GraphicEngine::i().createCamera(Vec3<float>(10,10,10), Vec3<float>(0,0,0));
	GraphicEngine::i().setCameraEntity(player);
}

void Game::processEvents()
{
	EntityManager::i().handleInput();
}

void Game::update(Time elapsedTime)
{
	PhysicsEngine::update(elapsedTime);
	EntityManager::i().update(elapsedTime);
}

void Game::render(float interpolation, Time elapsedTime)
{
	GraphicEngine::i().updateCamera();

	EntityManager::i().updateRender(interpolation);

	GraphicEngine::i().renderAll();
}

