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
		//if (GraphicEngine::i().isWindowActive()) {
		//if (Cliente::i().isConected() ) {
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
			
		//}
			MastEventReceiver::i().startEventProcess();
	}
	
	//Espera a que termine el otro hilo para finalizar el programa
	Cliente::i().apagar();
	GraphicEngine::i().apagar();
}


//Tenemos que hacer patron fachada
void Game::inicializar()
{
	

	//inicializamos bullet
	PhysicsEngine::i().inicializar();
	GraphicEngine::i().inicializar();


	//Antes se hacia aqui pero ahora se hace en Cliente.cpp una vez la conexion ha sido aceptada
	//player = new Player();


	//player = new Player();

	//enemy = new Enemy();

	///////////////////////////////////////////////////////////////
	SceneNode* suelo = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt = new PhysicsEntity(suelo, "suelo");
	sueloEnt->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt, Vec3<float>(100, 5.f, 100), 0));
	//sueloEnt->rotate(Vec3<float>(0.1, 0, 0));
	///////////////////////////////////////////////////////////////

	SceneNode* suelo2 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt2 = new PhysicsEntity(suelo2, "suelo");
	sueloEnt2->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt2, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt2->rotate(Vec3<float>(90 * PI / 180.0,0, 0));
	sueloEnt2->setPosition(Vec3<float>(-50, 0, 0));
	///////////////////////////////////////////////////////////////

	SceneNode* suelo3 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt3 = new PhysicsEntity(suelo3, "suelo1");
	sueloEnt3->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt3, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt3->rotate(Vec3<float>(0, 0, 90 * PI / 180.0));
	sueloEnt3->setPosition(Vec3<float>(0, 0, -50));


	//////////////////////////////////////////////////////////////////////

	SceneNode* suelo4 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(25, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt4 = new PhysicsEntity(suelo4, "suelo1");
	sueloEnt4->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt4, Vec3<float>(25, 5.f, 100), 0));
	sueloEnt4->rotate(Vec3<float>(0, 0, 30 * PI / 180.0));
	sueloEnt4->setPosition(Vec3<float>(60, -25, 40));

	///////////////////////////////////////////////////////////////////////

	SceneNode* suelo5 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(25, 5.f, 50), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt5 = new PhysicsEntity(suelo5, "suelo1");
	sueloEnt5->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt5, Vec3<float>(25, 5.f, 50), 0));
	sueloEnt5->rotate(Vec3<float>(0, 0, 0));
	sueloEnt5->setPosition(Vec3<float>(60, 0, -25));


	///////////////////////////////////////////////////////////////

	SceneNode* suelo6 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt6 = new PhysicsEntity(suelo6, "suelo1");
	sueloEnt6->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt6, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt6->rotate(Vec3<float>(90 * PI / 180.0, 0, 0));
	sueloEnt6->setPosition(Vec3<float>(75, 0, 0));
	///////////////////////////////////////////////////////////////

	SceneNode* suelo7 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt7 = new PhysicsEntity(suelo7, "suelo1");
	sueloEnt7->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt7, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt7->rotate(Vec3<float>(0, 0, 90 * PI / 180.0));
	sueloEnt7->setPosition(Vec3<float>(0, 0, 50));

	//////////////////////////////////////////////////////////////////////
	////////         Creamos un paquete de vida        //////////////////

	SceneNode* vida = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(1.f, 1.f, 1.f), "../media/life.png", "");
	LifeObject *vidaEnt = new LifeObject(vida, "vida");
	vidaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(vidaEnt, Vec3<float>(1.f, 1.f, 1.f)));
	//vidaEnt->setPosition(Vec3<float>(0, 0, 80));
	vidaEnt->setPosition(Vec3<float>(10, 3, 0));

	/////////////////////////////////////////////////////////////////////

	SceneNode* lanzacohete = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(5.f, 5.f, 5.f), "../media/lanzacohetes.jpg", "");
	RocketLauncherDrop *RocketLauncherDropEnt = new RocketLauncherDrop(lanzacohete, "lanzacohetes");
	RocketLauncherDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(RocketLauncherDropEnt, Vec3<float>(5.f, 5.f, 5.f)));
	//vidaEnt->setPosition(Vec3<float>(0, 0, 80));
	RocketLauncherDropEnt->setPosition(Vec3<float>(20, 7, 0));

	/////////////////////////////////////////////////////////////////////

	SceneNode* asaltodrop = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(5.f, 5.f, 5.f), "../media/Asalto.jpg", "");
	AsaltoDrop *AsaltoDropEnt = new AsaltoDrop(asaltodrop, "asalto");
	AsaltoDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(AsaltoDropEnt, Vec3<float>(5.f, 5.f, 5.f)));
	//vidaEnt->setPosition(Vec3<float>(0, 0, 80));
	AsaltoDropEnt->setPosition(Vec3<float>(20, 7, 15));

	/////////////////////////////////////////////////////////////////////

	SceneNode* pistoladrop = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(5.f, 5.f, 5.f), "../media/pistola.jpg", "");
	PistolaDrop *pistolaEnt = new PistolaDrop(pistoladrop, "pistola");
	pistolaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(pistolaEnt, Vec3<float>(5.f, 5.f, 5.f)));
	//vidaEnt->setPosition(Vec3<float>(0, 0, 80));
	pistolaEnt->setPosition(Vec3<float>(20, 7, -15));

	/////////////////////////////////////////////////////////////////////

	int a;
	do {
		std::cout << "Elige un modo:" << std::endl;
		std::cout << "1 - Un jugador" << std::endl;
		std::cout << "2 - Multijugador" << std::endl;

		std::cin >> a;
	} while (a != 1 && a != 2);
	

	if (a == 1) {
		//Si no le pasas GUID es que es un jugador
		player = new Player("Batman");

		EntityManager::i().inicializar();

		EntityManager::i().cargarContenido();
	}
	else {
		EntityManager::i().inicializar();

		EntityManager::i().cargarContenido();
		

		//raknet
		Cliente::i().inicializar();

		
		//Bucle infinito hasta que se conecte
		while (Cliente::i().isConected() == false);

		


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

	return true;
}

void Game::update(Time elapsedTime)
{
	EntityManager::i().updatePosEnemigos(elapsedTime);
	EntityManager::i().updateRotEnemigos(elapsedTime);
	PhysicsEngine::i().update(elapsedTime);
	
	EntityManager::i().update(elapsedTime);
	MessageHandler::i().update();
	//antes era global, ahora cada entity tiene la suya, entonces aqui habria que hacer un for para que cada
	//entity recorra su pila de posiciones no?
}

void Game::render(float interpolation, Time elapsedTime)
{

	EntityManager::i().updateRender(interpolation);

	GraphicEngine::i().updateCamera();

	GraphicEngine::i().renderAll();

}

