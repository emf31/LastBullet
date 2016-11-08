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
#include "Handlers\MessageHandler.h"


#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <thread> 
#include "Motor de Red\Cliente.h"

#define SERVER_PORT 65535

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
		//if (GraphicEngine::i().isWindowActive()) {
		if (GraphicEngine::i().iniciado) {
			Time elapsedTime = clock.restart();
			timeSinceLastUpdate += elapsedTime;
			MastEventReceiver::i().endEventProcess();
			
			if (processEvents()) {
				//Cliente::i().cerrar();
				break;
			}
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
	
	//Espera a que termine el otro hilo para finalizar el programa
	//Cliente::i().esperar();
	Cliente::i().cerrar();
	GraphicEngine::i().apagar();
}


//Tenemos que hacer patron fachada
void Game::inicializar()
{

	//inicializamos bullet
	PhysicsEngine::inicializar();
	GraphicEngine::i().inicializar();


	//Antes se hacia aqui pero ahora se hace en Cliente.cpp una vez la conexion ha sido aceptada
	//player = new Player();


	SceneNode* suelo = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(2000.f, 100.f, 2000.f), "../media/wall.jpg");

	PhysicsEntity *sueloEnt = new PhysicsEntity(suelo,"");
	sueloEnt->setRigidBody(PhysicsEngine::createBoxRigidBody(sueloEnt, Vec3<float>(2000.f, 100.f, 2000.f),0));

	EntityManager::i().cargarContenido();


	//raknet
	Cliente::i().inicializar();

	//
}

bool Game::processEvents()
{
	EntityManager::i().handleInput();
	if (MastEventReceiver::i().keyPressed(KEY_KEY_Z)) {
		Cliente::i().enviarDesconexion();
		return true;
	}
}

void Game::update(Time elapsedTime)
{
	EntityManager::i().updatePosEnemigos(elapsedTime);
	PhysicsEngine::update(elapsedTime);
	EntityManager::i().update(elapsedTime);
	//esto estaba antes
	//MessageHandler::i().update();
	//antes era global, ahora cada entity tiene la suya, entonces aqui habria que hacer un for para que cada entity recorra su pila de posiciones no?

}

void Game::render(float interpolation, Time elapsedTime)
{


	EntityManager::i().updateRender(interpolation);

	GraphicEngine::i().updateCamera();

	GraphicEngine::i().renderAll();
}

