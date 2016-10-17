#include "stdafx.h"
#include "GraphicEngine.h"
#include "../MastEventReceiver.hpp"


GraphicEngine::GraphicEngine()
{
}


GraphicEngine::~GraphicEngine()
{
}

SceneNode* GraphicEngine::createNode(const Vec3<float>& TPosition, const Vec3<float>& TScale, const io::path & texture)
{
	ISceneNode *Node = irrScene->addCubeSceneNode(1.0f);
	Node->setScale(vector3df(TScale.getX(), TScale.getY(), TScale.getZ()));
	Node->setPosition(vector3df(TPosition.getX(), TPosition.getY(), TPosition.getZ()));
	//Asi no le afectan las luces
	Node->setMaterialFlag(EMF_LIGHTING, false);
	//Si es diferente de "" asignamos una textura al nodo
	if (texture != "") {
		Node->setMaterialTexture(0,irrDriver->getTexture(texture));
	}
	//Le pasamos irrDriver para que se encargue el de asignar la textura
	return new SceneNode(Node, irrDriver);
}


void GraphicEngine::createCamera(Vec3<float> position, Vec3<float> target)
{
	// Add camera
	//camara tipo fps
	Camera = irrScene->addCameraSceneNodeFPS();
	Camera->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
	Camera->setTarget(vector3df(target.getX(), target.getY(), target.getZ()));
	Camera->setInputReceiverEnabled(true);
}

void GraphicEngine::setCameraTarget(Vec3<float> target)
{
	Camera->setTarget(vector3df(target.getX(), target.getY(), target.getZ()));
}

void GraphicEngine::setCameraPosition(Vec3<float> position)
{
	Camera->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
}

void GraphicEngine::renderAll()
{
	irrDriver->beginScene(true, true, SColor(255, 100, 101, 140));
	irrScene->drawAll();
	irrDriver->endScene();
}

void GraphicEngine::inicializar()
{
	// Initialize irrlicht
	irrDevice = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, &MastEventReceiver::i());
	irrDevice->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	irrGUI = irrDevice->getGUIEnvironment();
	irrScene = irrDevice->getSceneManager();
	irrDriver = irrDevice->getVideoDriver();

	irrDevice->getCursorControl()->setVisible(0);
}
