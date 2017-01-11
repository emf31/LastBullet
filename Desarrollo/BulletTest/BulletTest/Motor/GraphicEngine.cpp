
#include "GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include <EntityManager.h>
#include <Player.h>
#include "PhysicsEngine.h"
#include <string>
#include <sstream>
#include <exception>

#include <GUIManager.h>

GraphicEngine::GraphicEngine() : debug_camera(true)
{
	
}

std::shared_ptr<BasicSceneNode> GraphicEngine::createNode(const Vec3<float>& TPosition, const Vec3<float>& TScale, const io::path & texture, const io::path & mesh)
{
	ISceneNode *Node;
	if(mesh!="")
		Node = irrScene->addMeshSceneNode(irrScene->getMesh(mesh));
	else
		Node = irrScene->addCubeSceneNode(2.0f);

	Node->setScale(vector3df(TScale.getX(), TScale.getY(), TScale.getZ()));
	Node->setPosition(vector3df(TPosition.getX(), TPosition.getY(), TPosition.getZ()));
	//Asi no le afectan las luces
	Node->setMaterialFlag(EMF_LIGHTING, false);

	m_camera = 0;

	//Si es diferente de "" asignamos una textura al nodo
	if (texture != "") {
		Node->setMaterialTexture(0,irrDriver->getTexture(texture));
	}
	//Node->getMaterial(0).getTextureMatrix(0).setScale(500*0.75);

	//Le pasamos irrDriver para que se encargue el de asignar la textura
	return std::shared_ptr<BasicSceneNode>(new BasicSceneNode(Node, irrDriver));
}

std::shared_ptr<AnimatedSceneNode> GraphicEngine::createAnimatedNode(const Vec3<float>& TPosition, const Vec3<float>& TScale, const io::path & texture, const io::path & mesh)
{
	IAnimatedMeshSceneNode *Node;

	Node = irrScene->addAnimatedMeshSceneNode(irrScene->getMesh(mesh));
	
	Node->setScale(vector3df(TScale.getX(), TScale.getY(), TScale.getZ()));
	Node->setPosition(vector3df(TPosition.getX(), TPosition.getY(), TPosition.getZ()));
	//Asi no le afectan las luces
	Node->setMaterialFlag(EMF_LIGHTING, false);

	m_camera = 0;

	//Si es diferente de "" asignamos una textura al nodo
	if (texture != "") {
		Node->setMaterialTexture(0, irrDriver->getTexture(texture));
	}

	

	//Le pasamos irrDriver para que se encargue el de asignar la textura
	return std::shared_ptr<AnimatedSceneNode>(new AnimatedSceneNode(Node, irrDriver));
}


void GraphicEngine::createCamera(Vec3<float> position, Vec3<float> target)
{
	//camara tipo fps
	ICameraSceneNode* cam = irrScene->addCameraSceneNodeFPS(NULL,irr::f32(100), irr::f32(0.05));
	cam->setPosition(vector3df(position.getX(), position.getY(), position.getZ()));
	cam->setTarget(vector3df(target.getX(), target.getY(), target.getZ()));
	cam->setInputReceiverEnabled(true);

	//Creamos el objeto camara y la metemos en unordermap de cameras y si es la primera se setea como activa
	Camera* myCamera=new Camera(cam);
	cameras[m_camera] = myCamera;

	if (m_camera == 0)
		active_camera = myCamera;

	m_camera++;
}

void GraphicEngine::setCameraEntity(Entity * entity)
{
	active_camera->asignarEntity(entity);
}

void GraphicEngine::updateCamera()
{
	if(debug_camera && active_camera != NULL)
		active_camera->update();
	
}


Camera * GraphicEngine::getActiveCamera()
{
	return active_camera;
}


void GraphicEngine::setActiveCamera(int ID)
{
	active_camera = cameras[ID];
}

void GraphicEngine::renderAll()
{
	irrDriver->beginScene(true, true, SColor(255, 100, 101, 140));


	irrScene->drawAll();
	irrGUI->drawAll();


	//debug_draw_bullet se setea al inicializar graphicEngine asi que se pone a falso en vez de comentar codigo
	if (debug_draw_bullet)
	{

		//material de irrlicht al que no le afectan las luces
		irrDriver->setMaterial(debugMat);
		irrDriver->setTransform(irr::video::ETS_WORLD, irr::core::IdentityMatrix);
		//mandas que se dibuje el debug a las fisicas
		PhysicsEngine::i().m_world->debugDrawWorld();

	}

	//gui.draw();
	GUIManager::i().drawAllGuis();

	irrDriver->endScene();
	int fps = irrDriver->getFPS();

	if (lastFPS != fps)
	{
		core::stringw str = L"LAST BULLET PRE ALPHA MECHANICS [";
		str += irrDriver->getName();
		str += "] FPS:";
		str += fps;

		irrDevice->setWindowCaption(str.c_str());
		lastFPS = fps;
	}

}

void GraphicEngine::inicializar()
{
	//if(!irrDevice){
		// Initialize irrlicht
		irrDevice = createDevice(video::EDT_OPENGL, dimension2d<u32>(1280, 720), 32, true, false, false, &MastEventReceiver::i());
		irrDevice->setWindowCaption(L"Test");

		irrGUI = irrDevice->getGUIEnvironment();
		irrScene = irrDevice->getSceneManager();
		irrDriver = irrDevice->getVideoDriver();

		//irrGUI->addImage(irrDriver->getTexture("../media/mirilla.png"), position2d<int>(1280 / 2 - 220 / 2, 720 / 2 - 165 / 2));


		irrDevice->getCursorControl()->setVisible(0);
		cargarTexturas();



		//DebugDraw viene a ser una clase fachada que hereda de btIDebugDraw,
		//esto es necesario para que despues puedas setear al mundo fisico con setDebugDraw
		//setDebugMode pone varios parametros pero cuidado que al final solo devuelve un entero

		debugDraw = new DebugDraw(irrDevice);
		debugDraw->setDebugMode(
			btIDebugDraw::DBG_DrawWireframe |
			btIDebugDraw::DBG_DrawAabb |
			btIDebugDraw::DBG_DrawContactPoints |
			//btIDebugDraw::DBG_DrawText |
			//btIDebugDraw::DBG_DrawConstraintLimits |
			btIDebugDraw::DBG_DrawConstraints //|
		);
		PhysicsEngine::i().m_world->setDebugDrawer(debugDraw);


		debugMat.Lighting = false;

		debug_draw_bullet = true;
	//}


}

bool GraphicEngine::isRuning()
{
	return irrDevice->run();
}

bool GraphicEngine::isWindowActive()
{
	return irrDevice->isWindowActive();
}

bool GraphicEngine::apagar()
{
	delete debugDraw;

	irrDevice->setEventReceiver(NULL);
	irrDevice->closeDevice();
	irrDevice->run();
	irrDevice->drop();



	irrDevice = NULL;
	
	return true;
}

void GraphicEngine::cargarTexturas() {

	//CARGAR TEXTURAS
	irrDriver->getTexture("../media/wall.jpg");
	irrDriver->getTexture("../media/ice0.jpg");
	irrDriver->getTexture("../media/juliyotexture.jpg");
	irrDriver->getTexture("../media/earth.jpg");
	irrDriver->getTexture("../media/Dif_2.tga");
	irrDriver->getTexture("../media/body01.png");
	irrDriver->getTexture("../media/head01.png");
	irrDriver->getTexture("../media/m4tex.png");
	irrDriver->getTexture("../media/WPNT_MK2Grenade_Base_Color.tga");
	irrDriver->getTexture("../media/arma/weapon.png");
	irrDriver->getTexture("../media/mirilla.png");
	irrDriver->getTexture("../media/lanzacohetes.jpg");
	irrDriver->getTexture("../media/Asalto.jpg");
	irrDriver->getTexture("../media/pistola.jpg");
	irrDriver->getTexture("../media/life.jpg");

	irrScene->getMesh("../media/ArmyPilot.b3d");
	irrScene->getMesh("../media/CapitanAmerica.obj"); 
	irrScene->getMesh("../media/edf_soldier_a.b3d");
	irrScene->getMesh("../media/sf2arms.obj");
	
	irrScene->getMesh("../media/bullet.obj");
	irrScene->getMesh("../media/WPN_MK2Grenade.obj");
	irrScene->getMesh("../media/arma/asalto.obj");
	irrScene->getMesh("../media/arma/pistola.obj");
	irrScene->getMesh("../media/arma/rocket.obj");
	
	

	irrGUI->getFont("../media/lucida.xml");
	
	
}

void GraphicEngine::removeNode(std::shared_ptr<SceneNode> nodo) {
	irrScene->addToDeletionQueue(nodo->getNodo());
}

