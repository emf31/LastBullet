#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "Game.h"
#include "MastEventReceiver.hpp"
#include "Otros\Clock.hpp"
#include "Motor\PhysicsEngine.h"
#include "Entities\EntityManager.h"
#include "Entities\PhysicsEntity.h"

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
			
			interpolation = (float)std::min(1.f, timeSinceLastUpdate.asSeconds() / timePerFrame.asSeconds());
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

	//inicializamos bullet
	PhysicsEngine::inicializar();

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

	player = new Player(irrScene);

	ISceneNode *suelo = irrScene->addCubeSceneNode(1.0f);
	suelo->setMaterialTexture(0, irrDriver->getTexture("../media/wall.jpg"));
	suelo->setScale(vector3df(50.f, 0.5f, 50.f));
	suelo->setPosition(vector3df(0, 0, 0));
	//Asi no le afectan las luces
	suelo->setMaterialFlag(EMF_LIGHTING, false);
	PhysicsEntity *sueloEnt = new PhysicsEntity(suelo,"");
	sueloEnt->setRigidBody(PhysicsEngine::createBoxRigidBody(sueloEnt, Vec3<float>(50.f, 0.5f, 50.f),0));

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
	Camera = irrScene->addCameraSceneNodeFPS();
	Camera->setPosition(vector3df(10,10,10));
	Camera->setTarget(vector3df(0, 0, 0));
	Camera->setInputReceiverEnabled(true);

}

ISceneNode* Game::CreateBox(const Vec3<double> &TPosition, const Vec3<float> &TScale, float TMass)
{
	
	/*
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
	//Shape->calculateLocalInertia(TMass, LocalInertia);

	// Create the rigid body object
	btRigidBody *RigidBody = new btRigidBody(TMass, MotionState, Shape, LocalInertia);
	//RigidBody->setFriction(0);
	RigidBody->setActivationState(DISABLE_DEACTIVATION);
	// Store a pointer to the irrlicht node so we can update it later
	RigidBody->setUserPointer((void *)(Node));

	// Add it to the world
//	World->addRigidBody(RigidBody);
	//Objects.push_back(RigidBody);

	return Node;*/
	return NULL;
}


void Game::processEvents()
{
	
	EntityManager::i().handleInput();

	/*if (MastEventReceiver::i().keyPressed(KEY_SPACE))
		entities.at(1)->isJumping = true;
	else if (MastEventReceiver::i().keyReleased(KEY_SPACE))
		entities.at(1)->isJumping = false;*/

}

void Game::update(Time elapsedTime)
{
	PhysicsEngine::update(elapsedTime);
	EntityManager::i().update(elapsedTime);

}

void Game::render(float interpolation, Time elapsedTime)
{
	/*for (int i = 0; i < entities.size(); i++) {
		//entities.at(i)->updateRender(interpolation);
	}*/
	/*irrScene->getActiveCamera()->setPosition(
		vector3df(
			EntityManager::i().getEntity(0)->getRenderPosition().getX(),
			EntityManager::i().getEntity(0)->getRenderPosition().getY(),
			EntityManager::i().getEntity(0)->getRenderPosition().getZ())
		);*/

	EntityManager::i().updateRender(interpolation);

	irrDriver->beginScene(true, true, SColor(255, 100, 101, 140));
	irrScene->drawAll();
	irrDriver->endScene();
}

