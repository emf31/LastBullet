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
		//if (irrDevice->isWindowActive()) {
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


			

			
		//}
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

	// Add camera
	//camara tipo fps
	Camera = irrScene->addCameraSceneNodeFPS();
	Camera->setInputReceiverEnabled(true);

	//Creamos el suelo
	ISceneNode *suelo = CreateBox(Vec3<double>(0, 0, 0), Vec3<float>(1000.0f, 0.5f, 1000.0f), 0.0f);

	suelo->setMaterialTexture(0, irrDriver->getTexture("../media/wall.jpg"));


	ISceneNode *player1 = CreateBox(Vec3<double>(0, 50.5, 0), Vec3<float>(100.f, 100.f, 100.0f), 0.0f);
	player1->setMaterialTexture(0, irrDriver->getTexture("../media/rockwall.jpg"));

	ISceneNode *player2 = CreateBox(Vec3<double>(150, 50.5, 0), Vec3<float>(100.f, 100.f, 100.0f), 0.0f);
	player2->setMaterialTexture(0, irrDriver->getTexture("../media/rockwall.jpg"));

	Entity *ent = new Entity(player1);
	Entity *ent2 = new Entity(player2);
	
	entities.push_back(ent);
	entities.push_back(ent2);

}

ISceneNode* Game::CreateBox(const Vec3<double> &TPosition, const Vec3<float> &TScale, float TMass)
{
	ISceneNode *Node = irrScene->addCubeSceneNode(1.0f);
	Node->setScale(vector3df(TScale.getX(), TScale.getY(), TScale.getZ()));
	Node->setPosition(vector3df(TPosition.getX(), TPosition.getY(), TPosition.getZ()));
	//Asi no le afectan las luces
	Node->setMaterialFlag(EMF_LIGHTING, false);

	return Node;
}


void Game::processEvents()
{
	
	if (MastEventReceiver::i().keyReleased(KEY_KEY_W)) {
		entities.at(0)->isMovingForward = false;
	}
	else if(MastEventReceiver::i().keyReleased(KEY_KEY_S)){
		entities.at(0)->isMovingBackward = false;
	}
	else if (MastEventReceiver::i().keyReleased(KEY_KEY_A)) {
		entities.at(0)->isMovingLeft = false;
	}
	else if(MastEventReceiver::i().keyReleased(KEY_KEY_D)){
		entities.at(0)->isMovingRight = false;
	}
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_W)) {
		entities.at(0)->isMovingForward = true;
	}
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_S)) {
		entities.at(0)->isMovingBackward = true;
	}
	else if (MastEventReceiver::i().keyPressed(KEY_KEY_A)) {
		entities.at(0)->isMovingLeft = true;
	} else if (MastEventReceiver::i().keyPressed(KEY_KEY_D)) {
		entities.at(0)->isMovingRight = true;
	}

}

void Game::update(Time elapsedTime)
{
	for (int i = 0; i < entities.size(); i++) {
		entities.at(i)->update(elapsedTime);
	}
}

void Game::render(float interpolation, Time elapsedTime)
{
	irrDriver->beginScene(true, true, SColor(255, 100, 101, 140));
	irrScene->drawAll();
	irrDriver->endScene();
}

