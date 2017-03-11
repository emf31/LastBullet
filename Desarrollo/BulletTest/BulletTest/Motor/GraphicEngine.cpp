
#include "GraphicEngine.h"
#include "../MastEventReceiver.hpp"
#include <EntityManager.h>
#include <Player.h>
#include "PhysicsEngine.h"
#include <string>
#include <sstream>
#include <exception>

#include <GUIManager.h>

GraphicEngine::GraphicEngine() : debug_camera(true), sm(SceneManager::i())
{
	
}

std::shared_ptr<BasicSceneNode> GraphicEngine::createNode(const Vec3<float>& TPosition, const Vec3<float>& TScale, const std::string & texture, const std::string & mesh)
{

	TModel* node;
	node = sm.crearNodoMalla(sm.getMesh(mesh));
	

	
	node->setScale(Vec3<float>(TScale.getX(), TScale.getY(), TScale.getZ()));
	node->setPosition(Vec3<float>(TPosition.getX(), TPosition.getY(), TPosition.getZ()));


	//Node->getMaterial(0).getTextureMatrix(0).setScale(500*0.75);

	//Le pasamos irrDriver para que se encargue el de asignar la textura
	return std::shared_ptr<BasicSceneNode>(new BasicSceneNode(node));
}

/*std::shared_ptr<AnimatedSceneNode> GraphicEngine::createAnimatedNode(const Vec3<float>& TPosition, const Vec3<float>& TScale, const io::path & texture, const io::path & mesh)
{
	IAnimatedMeshSceneNode *Node;

	Node = irrScene->addAnimatedMeshSceneNode(irrScene->getMesh(mesh));
	
	Node->setScale(vector3df(TScale.getX(), TScale.getY(), TScale.getZ()));
	Node->setPosition(vector3df(TPosition.getX(), TPosition.getY(), TPosition.getZ()));
	//Asi no le afectan las luces
	Node->setMaterialFlag(EMF_LIGHTING, false);

	

	//Si es diferente de "" asignamos una textura al nodo
	if (texture != "") {
		Node->setMaterialTexture(0, irrDriver->getTexture(texture));
	}

	

	//Le pasamos irrDriver para que se encargue el de asignar la textura
	return std::shared_ptr<AnimatedSceneNode>(new AnimatedSceneNode(Node, irrDevice));
}*/

/*std::shared_ptr<SceneNode> GraphicEngine::createBillboard(std::shared_ptr<SceneNode> nodo, const Vec2f& vector2d, const Vec3<float>& relPosition, const Color4f& color) {

	IBillboardSceneNode *billboard = irrScene->addBillboardSceneNode(nodo->getNodo(), vector2df(1, 1), vector3df(1, 1, 1));
	billboard->setSize(core::dimension2df(vector2d.x, vector2d.y));
	billboard->setPosition(core::vector3df(relPosition.getX(), relPosition.getY(), relPosition.getZ()));
	billboard->setColor(video::SColor(color.a, color.r, color.g, color.b));

	return std::shared_ptr<BillboardSceneNode>(new BillboardSceneNode(billboard, irrDevice));
}*/

/*std::shared_ptr<SceneNode> GraphicEngine::createBillboardText(std::shared_ptr<SceneNode> nodo, const std::string& text, const Vec2f& vector2d, const Vec3<float>& relPosition, const Color4f& color) {

	gui::IGUIFont* fnt = irrGUI->getFont("../media/lucida.xml");

	const wchar_t* aux1 = GetWC(text.c_str());

	IBillboardSceneNode *billboard = irrScene->addBillboardTextSceneNode(0, aux1, nodo->getNodo(), vector2df(1, 1), vector3df(1, 1, 1));

	billboard->setSize(core::dimension2df(6, 1));
	billboard->setPosition(core::vector3df(0, 200, 0));
	billboard->setColor(video::SColor(255, 255, 128, 128), video::SColor(255, 255, 128, 128));

	delete[] aux1;

	
	
	return std::shared_ptr<BillboardSceneNode>(new BillboardSceneNode(billboard, irrDevice));
}*/

const wchar_t * GraphicEngine::GetWC(const char *c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

Camera* GraphicEngine::createCamera(const std::string &name, Vec3<float> position, Vec3<float> target)
{
	//camara tipo fps

	TCamera* cam = sm.crearNodoCamara();
	cam->setPosition(position);
	cam->setTarget(target);
	cam->setInputEnable(false);

	

	//Creamos el objeto camara y la metemos en unordermap de cameras y si es la primera se setea como activa
	Camera* myCamera = new Camera(cam, name);
	cameras[name] = myCamera;
	setActiveCamera(name);
	return myCamera;
}

void GraphicEngine::updateCamera()
{
	if(debug_camera && active_camera != NULL)
		active_camera->update();
	
}

void GraphicEngine::setTargetActiveCamera(const Vec3<float> target) {
	active_camera->setTarget(target);
}


Camera * GraphicEngine::getActiveCamera()
{
	return active_camera;
}


void GraphicEngine::setActiveCamera(const std::string &nameCamera)
{
	
	auto found = cameras.find(nameCamera);
	if (found != cameras.end()) {
		active_camera = found->second;
		SceneManager::i().setActiveCamera(active_camera->getCameraNode());
	}
	else {
		throw std::runtime_error("Camara no encontrada");
	}

}

void GraphicEngine::renderAll()
{
	
	
	SceneManager::i().draw();

	//debug_draw_bullet se setea al inicializar graphicEngine asi que se pone a falso en vez de comentar codigo
	/*if (debug_draw_bullet)
	{

		//material de irrlicht al que no le afectan las luces
		irrDriver->setMaterial(debugMat);
		irrDriver->setTransform(irr::video::ETS_WORLD, irr::core::IdentityMatrix);
		//mandas que se dibuje el debug a las fisicas
		PhysicsEngine::i().m_world->debugDrawWorld();

	}
	*/
	//gui.draw();
	

	int fps = engine.getFPS();

	std::ostringstream str;
	str << u8"LAST BULLET - [FPS:" << fps<<"]";
	GUIManager::i().drawAllGuis();
	SceneManager::i().renderFrame(engine.getWindow());
}

void GraphicEngine::inicializar()
{
	screenWidth = 1280;
	screenHeight = 720;
	engine.createEngineDevice(screenWidth, screenHeight, u8"Motor gráfico / Visor OpenGL - Last Bullet");


	sm = SceneManager::i();

	sm.inicializarBuffers();

	TSunLight* dsa = SceneManager::i().crearNodoSunLight(Vec3<float>(0.0f, 0.0f, -1.0f));
	dsa->setIntensidadAmbiente(0.8f); 



}


bool GraphicEngine::isWindowActive()
{
	return !engine.shouldCloseWindw();
}

bool GraphicEngine::apagar()
{
	delete debugDraw;

	engine.shutdown();
	
	return true;
}

void GraphicEngine::cargarTexturas() {

	//CARGAR TEXTURAS
	/*irrDriver->getTexture("../media/wall.jpg");
	irrDriver->getTexture("../media/ice0.jpg");
	irrDriver->getTexture("../media/texture.jpg");
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
	
	

	irrGUI->getFont("../media/lucida.xml");-*/
	
	
}

/*void GraphicEngine::removeNode(std::shared_ptr<SceneNode> nodo) {
	irrScene->addToDeletionQueue(nodo->getNodo());
}*/


void GraphicEngine::setDebugDraw()
{
	/*debugDraw = new DebugDraw(irrDevice);
	//DebugDraw viene a ser una clase fachada que hereda de btIDebugDraw,
	//esto es necesario para que despues puedas setear al mundo fisico con setDebugDraw
	//setDebugMode pone varios parametros pero cuidado que al final solo devuelve un entero
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

	debug_draw_bullet = true;*/
}

void GraphicEngine::apuntar()
{
	active_camera->apuntar();
}

void GraphicEngine::restablecerMirilla()
{
	active_camera->restablecerMira();
}

