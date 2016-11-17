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


const Time Game::timePerFrame = seconds(1.f / 30.f);



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
	time_physics_prev = time_physics_curr = clock.restart();
	time_gameclock = clock.getElapsedTime();


	while (GraphicEngine::i().isRuning()) {
		//if (GraphicEngine::i().isWindowActive()) {
		//if (Cliente::i().isConected() ) {



		MastEventReceiver::i().endEventProcess();

		processEvents();

		///Las fisicas se ejecutan 80 veces por segundo

		time_physics_curr = clock.getElapsedTime();

		PhysicsEngine::i().update(time_physics_curr - time_physics_prev);

		time_physics_prev = time_physics_curr;


		// Game Clock part of the loop
		/*  This ticks once every TickMs milliseconds on average */
		Time dt = clock.getElapsedTime() - time_gameclock;

		//Llevamos control en las actualizaciones por frame
		while (dt >= timePerFrame) // 30 veces/segundo
		{
			dt -= timePerFrame;
			time_gameclock += timePerFrame;


			//Realizamos actualizaciones
			update(timePerFrame);
		}


		interpolation = (float)min(1.f, dt.asSeconds() / timePerFrame.asSeconds());

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
	std::shared_ptr<BasicSceneNode> suelo = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt = new PhysicsEntity(suelo, "suelo");
	sueloEnt->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt, Vec3<float>(100, 5.f, 100), 0));
	//sueloEnt->rotate(Vec3<float>(0.1, 0, 0));
	///////////////////////////////////////////////////////////////

	std::shared_ptr<BasicSceneNode> suelo2 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt2 = new PhysicsEntity(suelo2, "suelo2");
	sueloEnt2->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt2, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt2->rotate(Vec3<float>(float(90 * PI / 180.0),0, 0));
	sueloEnt2->setPosition(Vec3<float>(-50, 0, 0));
	///////////////////////////////////////////////////////////////

	std::shared_ptr<BasicSceneNode> suelo3 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt3 = new PhysicsEntity(suelo3, "suelo3");
	sueloEnt3->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt3, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt3->rotate(Vec3<float>(0, 0, float( 90 * PI / 180.0)));
	sueloEnt3->setPosition(Vec3<float>(0, 0, -50));


	//////////////////////////////////////////////////////////////////////

	std::shared_ptr<BasicSceneNode> suelo4 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(25, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt4 = new PhysicsEntity(suelo4, "suelo4");
	sueloEnt4->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt4, Vec3<float>(25, 5.f, 100), 0));
	sueloEnt4->rotate(Vec3<float>(0, 0, float(30 * PI / 180.0)));
	sueloEnt4->setPosition(Vec3<float>(60, -25, 40));

	///////////////////////////////////////////////////////////////////////

	std::shared_ptr<BasicSceneNode> suelo5 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(25, 5.f, 50), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt5 = new PhysicsEntity(suelo5, "suelo5");
	sueloEnt5->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt5, Vec3<float>(25, 5.f, 50), 0));
	sueloEnt5->rotate(Vec3<float>(0, 0, 0));
	sueloEnt5->setPosition(Vec3<float>(60, 0, -25));


	///////////////////////////////////////////////////////////////

	std::shared_ptr<BasicSceneNode> suelo6 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt6 = new PhysicsEntity(suelo6, "suelo6");
	sueloEnt6->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt6, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt6->rotate(Vec3<float>(float(90 * PI / 180.0), 0, 0));
	sueloEnt6->setPosition(Vec3<float>(75, 0, 0));
	///////////////////////////////////////////////////////////////

	std::shared_ptr<BasicSceneNode> suelo7 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(100, 5.f, 100), "../media/wall.jpg", "");

	PhysicsEntity *sueloEnt7 = new PhysicsEntity(suelo7, "suelo7");
	sueloEnt7->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt7, Vec3<float>(100, 5.f, 100), 0));
	sueloEnt7->rotate(Vec3<float>(0, 0, float( 90 * PI / 180.0)));
	sueloEnt7->setPosition(Vec3<float>(0, 0, 50));

	//////////////////////////////////////////////////////////////////////
	////////         Creamos 2 paquete de vida        //////////////////

	std::shared_ptr<BasicSceneNode> vida = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(3.f, 3.f, 3.f), "../media/life.png", "");
	LifeObject *vidaEnt = new LifeObject(vida, "vida");
	vidaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(vidaEnt, Vec3<float>(3.f, 3.f, 3.f)));
	//vidaEnt->setPosition(Vec3<float>(0, 0, 80));
	vidaEnt->setPosition(Vec3<float>(10, 9, 0));
	
	std::shared_ptr<BasicSceneNode> vida2 = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(3.f, 3.f, 3.f), "../media/life.png", "");
	LifeObject *vidaEnt2 = new LifeObject(vida2, "vida2");
	vidaEnt2->setGhostObject(PhysicsEngine::i().createBoxGhostObject(vidaEnt2, Vec3<float>(3.f, 3.f, 3.f)));
	//vidaEnt->setPosition(Vec3<float>(0, 0, 80));
	vidaEnt2->setPosition(Vec3<float>(40, 9, 0));

	/////////////////////////////////////////////////////////////////////

	std::shared_ptr<BasicSceneNode> lanzacohete = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(5.f, 5.f, 5.f), "../media/lanzacohetes.jpg", "");
	RocketLauncherDrop *RocketLauncherDropEnt = new RocketLauncherDrop(lanzacohete, "lanzacohetes");
	RocketLauncherDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(RocketLauncherDropEnt, Vec3<float>(5.f, 5.f, 5.f)));
	//vidaEnt->setPosition(Vec3<float>(0, 0, 80));
	RocketLauncherDropEnt->setPosition(Vec3<float>(20, 7, 0));

	/////////////////////////////////////////////////////////////////////

	std::shared_ptr<BasicSceneNode> asaltodrop = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(5.f, 5.f, 5.f), "../media/Asalto.jpg", "");
	AsaltoDrop *AsaltoDropEnt = new AsaltoDrop(asaltodrop, "asalto");
	AsaltoDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(AsaltoDropEnt, Vec3<float>(5.f, 5.f, 5.f)));
	//vidaEnt->setPosition(Vec3<float>(0, 0, 80));
	AsaltoDropEnt->setPosition(Vec3<float>(20, 7, 15));

	/////////////////////////////////////////////////////////////////////

	std::shared_ptr<BasicSceneNode> pistoladrop = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), Vec3<float>(5.f, 5.f, 5.f), "../media/pistola.jpg", "");
	PistolaDrop *pistolaEnt = new PistolaDrop(pistoladrop, "pistola");
	pistolaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(pistolaEnt, Vec3<float>(5.f, 5.f, 5.f)));
	//vidaEnt->setPosition(Vec3<float>(0, 0, 80));
	pistolaEnt->setPosition(Vec3<float>(20, 7, -15));

	/////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////
	std::shared_ptr<BasicSceneNode> caja = GraphicEngine::i().createNode(Vec3<float>(0, 100, 0), Vec3<float>(5.f, 5.f, 5.f), "../media/ice0.jpg", "");

	PhysicsEntity *cajaEnt = new PhysicsEntity(caja, "caja");
	cajaEnt->setRigidBody(PhysicsEngine::i().createBoxRigidBody(sueloEnt7, Vec3<float>(5.f, 5.f, 5.f), 1, DISABLE_DEACTIVATION));
	cajaEnt->setPosition(Vec3<float>(0, 100, 0));

	/////////////////////////////////////////////////////////////////////

	int a;
	do {
		std::cout << "Elige un modo:" << std::endl;
		std::cout << "1 - Un jugador" << std::endl;
		std::cout << "2 - Multijugador" << std::endl;

		std::cin >> a;
	} while (a != 1 && a != 2);
	

	if (a == 1) {
		EntityManager::i().inicializar();

		EntityManager::i().cargarContenido();

		//Si no le pasas GUID es que es un jugador
		player = new Player("Pepi");
		player->inicializar();
		player->cargarContenido();
	}
	else {
		EntityManager::i().inicializar();

		EntityManager::i().cargarContenido();

		//raknet
		Cliente::i().inicializar();

		
		//Bucle infinito hasta que se conecte
		while (Cliente::i().isConected() == false);

		//enviamos los paquetes del vida al servidor para que los cree
		Cliente::i().nuevaVida(vidaEnt->getID());
		Cliente::i().nuevaVida(vidaEnt2->getID());



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
	/*EntityManager::i().updatePosEnemigos(elapsedTime);
	EntityManager::i().updateRotEnemigos(elapsedTime);*/
	int b = EntityManager::i().numClientes();
	if (b > 1) {
		int a = 0;
	}
	PhysicsEngine::i().update(timePerFrame);

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

