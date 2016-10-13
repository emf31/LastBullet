#include "stdafx.h"
#include <iostream>
#include <algorithm>

#include "Game.h"
#include "EventReceiver.h"

const duration<float> Game::timePerFrame = duration<float>(1.f / 15.f);

Game::Game()
{
	
}


Game::~Game()
{
}

void Game::run()
{
	Timer clock;
	milliseconds timeSinceLastUpdate = milliseconds::zero();
	inicializarIrrlitch();
	while (irrDevice->run()) {
		milliseconds elapsedTime = clock.Reset();
		timeSinceLastUpdate += elapsedTime;
		processEvents();

		//Llevamos control en las actualizaciones por frame
		while (timeSinceLastUpdate > duration_cast<milliseconds>(timePerFrame)) // 15 veces/segundo
		{
			timeSinceLastUpdate -= duration_cast<milliseconds>(timePerFrame);
			//Realizamos actualizaciones
			update(duration_cast<milliseconds>(timePerFrame));
		}
		interpolation = (float)std::min(1.f, (float)duration_cast<seconds>(timeSinceLastUpdate).count() / (float)duration_cast<seconds>(timePerFrame).count());
		render(interpolation, elapsedTime);
	}
	irrDevice->drop();
	std::getchar();
}


//Tenemos que hacer patron fachada
void Game::inicializarIrrlitch()
{
	// Initialize irrlicht
	EventReceiver Receiver;
	irrDevice = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, false);
	irrDevice->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	irrGUI = irrDevice->getGUIEnvironment();
	irrScene = irrDevice->getSceneManager();
	irrDriver = irrDevice->getVideoDriver();

	irrDevice->getCursorControl()->setVisible(0);

	// Add camera
	//camara tipo fps
	Camera = irrScene->addCameraSceneNodeFPS();

	//Creamos el suelo
	ISceneNode *suelo = CreateBox(Vec3<double>(1, 2, 3), Vec3<float>(1000.0f, 0.5f, 1000.0f), 0.0f);

	suelo->setMaterialTexture(0, irrDriver->getTexture("../media/wall.jpg"));

}

ISceneNode* Game::CreateBox(const Vec3<double> &TPosition, const Vec3<float> &TScale, float TMass)
{
	ISceneNode *Node = irrScene->addCubeSceneNode(1.0f);
	Node->setScale(vector3df(TScale.getX(), TScale.getY(), TScale.getZ()));
	Node->setPosition(vector3df(0.f,0.f,0.f));
	//Asi no le afectan las luces
	Node->setMaterialFlag(EMF_LIGHTING, false);

	return Node;
}


void Game::processEvents()
{

}

void Game::update(milliseconds elapsedTime)
{

}

void Game::render(float interpolation, milliseconds elapsedTime)
{
	irrDriver->beginScene(true, true, SColor(255, 100, 101, 140));
	irrScene->drawAll();
	irrDriver->endScene();
}

