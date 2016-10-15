#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <Windows.h>
#include "Game.h"
#include "MastEventReceiver.hpp"
#include "Otros\Clock.hpp"


const Time Game::timePerFrame = seconds(1.f / 15.f);

Game::Game()
{
	AllocConsole();
}


Game::~Game()
{
}

void Game::run()
{
	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;

	inicializarIrrlitch();
	
	while (irrDevice->run()) {
		if (irrDevice->isWindowActive()) {
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
	irrDevice->drop();
	std::getchar();
}


//Tenemos que hacer patron fachada
void Game::inicializarIrrlitch()
{
	// Initialize irrlicht
	irrDevice = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, &MastEventReceiver::i());
	irrDevice->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	irrGUI = irrDevice->getGUIEnvironment();
	irrScene = irrDevice->getSceneManager();
	irrDriver = irrDevice->getVideoDriver();

	irrDevice->getCursorControl()->setVisible(0);


	// Initialize bullet
	//Configura los algoritmos que utiliza para la colision de los objetos
	btDefaultCollisionConfiguration *CollisionConfiguration = new btDefaultCollisionConfiguration();
	//Algoritmo que usa bullet para guardarse las parejas que colisionan(sirve tambien para controlar parejas que NO colisionan)
	btBroadphaseInterface *BroadPhase = new btAxisSweep3(btVector3(-1000, -1000, -1000), btVector3(1000, 1000, 1000));
	btCollisionDispatcher *Dispatcher = new btCollisionDispatcher(CollisionConfiguration);
	//Es lo que causa las iteraciones de los objetos(gravedad, fuerzas, colisiones), segun julio es lo que tiene mas tiempo de calculo
	btSequentialImpulseConstraintSolver *Solver = new btSequentialImpulseConstraintSolver();
	//Crea el mundo con los parametros anteriores
	World = new btDiscreteDynamicsWorld(Dispatcher, BroadPhase, Solver, CollisionConfiguration);
	World->setGravity(btVector3(0,-80,0));




	//Creamos el suelo
	ISceneNode *suelo = CreateBox(Vec3<double>(0, 0, 0), Vec3<float>(1000.0f, 0.5f, 1000.0f), 0.0f);

	suelo->setMaterialTexture(0, irrDriver->getTexture("../media/wall.jpg"));


	ISceneNode *player1 = CreateBox(Vec3<double>(0, 450.5, 0), Vec3<float>(100.f, 100.f, 100.0f), 1.0f);
	player1->setMaterialTexture(0, irrDriver->getTexture("../media/rockwall.jpg"));

	ISceneNode *player2 = CreateBox(Vec3<double>(150, 450.5, 0), Vec3<float>(100.f, 100.f, 100.0f), 1.0f);
	player2->setMaterialTexture(0, irrDriver->getTexture("../media/rockwall.jpg"));

	Entity *entsuelo = new Entity(suelo);
	Entity *ent = new Entity(player1);
	Entity *ent2 = new Entity(player2);
	
	entities.push_back(entsuelo);
	entities.push_back(ent);
	entities.push_back(ent2);

	// Add camera
	//camara tipo fps
	Camera = irrScene->addCameraSceneNodeFPS();
	Camera->setPosition(vector3df(player1->getPosition().X, player1->getPosition().Y, player1->getPosition().Z));
	Camera->setTarget(vector3df(0, 0, 0));
	Camera->setInputReceiverEnabled(true);

}

ISceneNode* Game::CreateBox(const Vec3<double> &TPosition, const Vec3<float> &TScale, float TMass)
{
	ISceneNode *Node = irrScene->addCubeSceneNode(1.0f);
	Node->setScale(vector3df(TScale.getX(), TScale.getY(), TScale.getZ()));
	Node->setPosition(vector3df(TPosition.getX(), TPosition.getY(), TPosition.getZ()));
	//Asi no le afectan las luces
	Node->setMaterialFlag(EMF_LIGHTING, false);

	// Set the initial position of the object
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(btVector3(TPosition.getX(), TPosition.getY(), TPosition.getZ()));

	btDefaultMotionState *MotionState = new btDefaultMotionState(Transform);

	// Create the shape
	btVector3 HalfExtents(TScale.getX() * 0.5f, TScale.getY() * 0.5f, TScale.getZ() * 0.5f);
	btCollisionShape *Shape = new btBoxShape(HalfExtents);
	

	// Add mass
	btVector3 LocalInertia;
	Shape->calculateLocalInertia(TMass, LocalInertia);

	// Create the rigid body object
	btRigidBody *RigidBody = new btRigidBody(TMass, MotionState, Shape, LocalInertia);
	//RigidBody->setFriction(0);
	RigidBody->setActivationState(DISABLE_DEACTIVATION);
	// Store a pointer to the irrlicht node so we can update it later
	RigidBody->setUserPointer((void *)(Node));

	// Add it to the world
	World->addRigidBody(RigidBody);
	Objects.push_back(RigidBody);

	return Node;
}


void Game::processEvents()
{
	
	entities.at(1)->isMovingForward = MastEventReceiver::i().keyDown(KEY_KEY_W);
	entities.at(1)->isMovingBackward = MastEventReceiver::i().keyDown(KEY_KEY_S);
	entities.at(1)->isMovingLeft = MastEventReceiver::i().keyDown(KEY_KEY_A);
	entities.at(1)->isMovingRight = MastEventReceiver::i().keyDown(KEY_KEY_D);

}

void Game::update(Time elapsedTime)
{
	World->stepSimulation(elapsedTime.asMilliseconds(), 60);

	int i = 0;
	// Relay the object's orientation to irrlicht
	for (list<btRigidBody *>::Iterator Iterator = Objects.begin(); Iterator != Objects.end(); ++Iterator) {
		if(i==1)	//Si es igual a 1 es el jugador que controlamos por lo que hacemos el update diferente
			entities.at(i)->update(elapsedTime, *Iterator, irrScene,1);
		else
			entities.at(i)->update(elapsedTime, *Iterator, irrScene,0);

		
		i++;
	}
}

void Game::render(float interpolation, Time elapsedTime)
{
	for (int i = 0; i < entities.size(); i++) {
		entities.at(i)->updateRender(interpolation);
	}
	irrScene->getActiveCamera()->setPosition(vector3df(entities.at(1)->getRenderPosition().getX(), entities.at(1)->getRenderPosition().getY(), entities.at(1)->getRenderPosition().getZ()));
	
	irrDriver->beginScene(true, true, SColor(255, 100, 101, 140));
	irrScene->drawAll();
	irrDriver->endScene();
}

