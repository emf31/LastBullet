#include "stdafx.h"
#include "Grafic3dEngine.h"
#include "../MastEventReceiver.hpp"


Grafic3dEngine::Grafic3dEngine()
{
	// Initialize irrlicht
	irrDevice = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, &MastEventReceiver::i());
	irrDevice->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	irrGUI = irrDevice->getGUIEnvironment();
	irrScene = irrDevice->getSceneManager();
	irrDriver = irrDevice->getVideoDriver();

	irrDevice->getCursorControl()->setVisible(0);
}


Grafic3dEngine::~Grafic3dEngine()
{
}

int Grafic3dEngine::createNode(const Vec3<float>& TPosition, const Vec3<float>& TScale)
{
	ISceneNode *Node = irrScene->addCubeSceneNode(1.0f);
	Node->setScale(vector3df(TScale.getX(), TScale.getY(), TScale.getZ()));
	Node->setPosition(vector3df(TPosition.getX(), TPosition.getY(), TPosition.getZ()));
	//Asi no le afectan las luces
	Node->setMaterialFlag(EMF_LIGHTING, false);

	nodes.push_back(Node);
	return nodes.size()-1;
}

void Grafic3dEngine::setTexture(int ID,int num, const io::path& texture)
{
	nodes.at(ID)->setMaterialTexture(num, irrDriver->getTexture(texture));

}

void Grafic3dEngine::createCamera(Vec3<float> position, Vec3<float> target)
{
	// Add camera
	//camara tipo fps
	Camera = irrScene->addCameraSceneNodeFPS();
	Camera->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
	Camera->setTarget(vector3df(target.getX(), target.getY(), target.getZ()));
	Camera->setInputReceiverEnabled(true);
}

void Grafic3dEngine::setCameraTarget(Vec3<float> target)
{
	Camera->setTarget(vector3df(target.getX(), target.getY(), target.getZ()));
}

void Grafic3dEngine::setCameraPosition(Vec3<float> position)
{
	Camera->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
}

void Grafic3dEngine::setNodePosition(int ID,Vec3<float> position)
{
	nodes.at(ID)->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
}

void Grafic3dEngine::renderAll()
{
	irrDriver->beginScene(true, true, SColor(255, 100, 101, 140));
	irrScene->drawAll();
	irrDriver->endScene();
}