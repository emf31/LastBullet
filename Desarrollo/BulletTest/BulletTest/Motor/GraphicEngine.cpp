
#include "GraphicEngine.h"
#include <EntityManager.h>
#include <Player.h>
#include "PhysicsEngine.h"
#include <string>
#include <sstream>
#include <exception>
#include <StateStack.h>

#include <GUIManager.h>
#include <ParticleSystem.h>



GraphicEngine::GraphicEngine() : debug_camera(true), sm(SceneManager::i()), exit(false)
{
	
}

void GraphicEngine::updateClippingPlanes()
{
	glm::mat4 projection = sm.getProjectionMatrix();
	glm::mat4 view = sm.getViewMatrix();
	glm::mat4 viewProjection = projection*view;
	double d_projection[16] = { 0.0 };
	const float *pSource = (const float*)glm::value_ptr(viewProjection);
	//std::cout <<"--------------------"<< std::endl;
	for (int i = 0; i < 16; ++i){
		d_projection[i] = pSource[i];
		//std::cout << d_projection[i] << std::endl;
	}
	//std::cout << "--------------------" << std::endl;*/
		

	// Right clipping plane.
	planes[0][0]=  d_projection[3] - d_projection[0];
	planes[0][1] = d_projection[7] - d_projection[4];
	planes[0][2] = d_projection[11] - d_projection[8];
	planes[0][3] = d_projection[15] - d_projection[12];
	//std::cout << "RIGHT: " << planes[0][0]<<"x+" << planes[0][1] << "y+" << planes[0][2] << "z+"<< planes[0][3]<<std::endl;
	//mPlanes[0].set(mvp[3] - mvp[0], mvp[7] - mvp[4], mvp[11] - mvp[8], mvp[15] - mvp[12]);

	// Left clipping plane.
	planes[1][0] = d_projection[3] + d_projection[0];
	planes[1][1] = d_projection[7] + d_projection[4];
	planes[1][2] = d_projection[11] + d_projection[8];
	planes[1][3] = d_projection[15] + d_projection[12];
	//planes[1].set(mvp[3] + mvp[0], mvp[7] + mvp[4], mvp[11] + mvp[8], mvp[15] + mvp[12]);

	// Bottom clipping plane.
	planes[2][0] = d_projection[3] + d_projection[1];
	planes[2][1] = d_projection[7] + d_projection[5];
	planes[2][2] = d_projection[11] + d_projection[9];
	planes[2][3] = d_projection[15] + d_projection[13];
	//planes[2].set(mvp[3] + mvp[1], mvp[7] + mvp[5], mvp[11] + mvp[9], mvp[15] + mvp[13]);

	// Top clipping plane.
	planes[3][0] = d_projection[3] - d_projection[1];
	planes[3][1] = d_projection[7] - d_projection[5];
	planes[3][2] = d_projection[11] - d_projection[9];
	planes[3][3] = d_projection[15] - d_projection[13];
	//planes[3].set(mvp[3] - mvp[1], mvp[7] - mvp[5], mvp[11] - mvp[9], mvp[15] - mvp[13]);

	// Far clipping plane.
	planes[4][0] = d_projection[3] - d_projection[2];
	planes[4][1] = d_projection[7] - d_projection[6];
	planes[4][2] = d_projection[11] - d_projection[10];
	planes[4][3] = d_projection[15] - d_projection[14];
	//planes[4].set(mvp[3] - mvp[2], mvp[7] - mvp[6], mvp[11] - mvp[10], mvp[15] - mvp[14]);

	// Near clipping plane.
	planes[5][0] = d_projection[3] + d_projection[2];
	planes[5][1] = d_projection[7] + d_projection[6];
	planes[5][2] = d_projection[11] + d_projection[10];
	planes[5][3] = d_projection[15] + d_projection[14];
	//planes[5].set(mvp[3] + mvp[2], mvp[7] + mvp[6], mvp[11] + mvp[10], mvp[15] + mvp[14]);

	/*for (unsigned int i = 0; i < 6; i++)
	{
		planes[i].normalize();
	}*/
}

void GraphicEngine::updateDeathCamera()
{
	auto found = cameras.find("CameraDeath");
	if (found != cameras.end()) {
		Vec3<float> playerPos = getActiveCamera()->getPosition();
		Vec3<float> cameraDir = (*found).second->getVectorDirection()*-1;
		Vec3<float> cameraPos = Vec3<float>(playerPos.getX(), playerPos.getY(), playerPos.getZ()+10);
		Vec3<float> vector = playerPos - cameraPos;
		(*found).second->setPosition(cameraPos);
		//(*found).second->setTarget(playerPos-vector);
	}

}

void GraphicEngine::cleanScreen() {
	TNode* root = sm.getRootNode();
	for (auto it = root->getChildNodes().begin(); it != root->getChildNodes().end(); it++) {
		delete *it;
	}
	root->getChildNodes().clear();
	sm.setActiveCamera(nullptr);

	sm.cleanScreen();

	sm.vecPointLight.clear();
	sm.vecFlashLight.clear();
	sm.vectorCamaras.clear();

	TSunLight* dsa = SceneManager::i().crearNodoSunLight(Vec3<float>(0.0f, 0.0f, -1.0f));
	dsa->setIntensidadAmbiente(0.45f);
	dsa->setIntensidadEspecular(0.6f);

	dsa->setVectorDireccion(Vec3<float>(71.f, -47.f, -31.f));
	dsa->setPosition(Vec3<float>(-10.f, 61.f, -70.f));

	SceneManager::i().setSunLight(dsa); //importante sin esta linea no se dibujan sombras

	createCamera("CamaraPlayer", Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	createCamera("CameraDeath", Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	setActiveCamera("CamaraPlayer");
	sm.camaraActiva->setFarPlane(1000.f);

	
}

std::shared_ptr<BasicSceneNode> GraphicEngine::createNode(const Vec3<float>& TPosition, const Vec3<float>& TScale, const std::string & texture, const std::string & mesh)
{


	TModel* node;
	node = SceneManager::i().crearNodoMalla(sm.getMesh(mesh));

	if (!node) {
		throw std::runtime_error("No se ha encontrado la malla: " + std::string(mesh.c_str()));
	}

	
	node->setScale(Vec3<float>(TScale.getX(), TScale.getY(), TScale.getZ()));
	node->setPosition(Vec3<float>(TPosition.getX(), TPosition.getY(), TPosition.getZ()));
	

	std::shared_ptr<BasicSceneNode> sharedptr(new BasicSceneNode(node));
	//Node->getMaterial(0).getTextureMatrix(0).setScale(500*0.75);

	//Le pasamos irrDriver para que se encargue el de asignar la textura
	return sharedptr;
}

std::shared_ptr<AnimatedSceneNode> GraphicEngine::createAnimatedNode(const std::string & directory, int numFrames)
{
	TAnimation* node;
	node = SceneManager::i().crearNodoAnimacion(ResourceManager::i().getAnimationMesh(directory, numFrames));

	if (!node) {
		throw std::runtime_error("No se ha encontrado la animacion: " + std::string(directory.c_str()));
	}


	//node->setScale(Vec3<float>(TScale.getX(), TScale.getY(), TScale.getZ()));
	//node->setPosition(Vec3<float>(TPosition.getX(), TPosition.getY(), TPosition.getZ()));


	std::shared_ptr<AnimatedSceneNode> sharedptr(new AnimatedSceneNode(node));
	//Node->getMaterial(0).getTextureMatrix(0).setScale(500*0.75);

	//Le pasamos irrDriver para que se encargue el de asignar la textura
	return sharedptr;
}

std::shared_ptr<StaticSceneNode> GraphicEngine::createStaticNode(const Vec3<float>& TPosition, const Vec3<float>& TRotation, const Vec3<float>& TScale, const std::string & mesh)
{
	TModelEstatico* node;
	node = SceneManager::i().crearNodoMallaEstatica(sm.getMesh(mesh), TPosition);

	if (!node) {
		throw std::runtime_error("No se ha encontrado la malla: " + std::string(mesh.c_str()));
	}

	node->setTransformMatrix(TPosition, TScale, TRotation);

	std::shared_ptr<StaticSceneNode> sharedptr(new StaticSceneNode(node));
	//Node->getMaterial(0).getTextureMatrix(0).setScale(500*0.75);

	//Le pasamos irrDriver para que se encargue el de asignar la textura
	return sharedptr;
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

	//setActiveCamera(name);

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


bool GraphicEngine::createPointLight(Vec3<float> pos, Vec3<float> color)
{
	TPointLight* light = SceneManager::i().crearNodoPointLight(pos);
	light->setColor(color.getX(), color.getY(), color.getZ());
	return true;
}

bool GraphicEngine::createDirectionalLight(Vec3<float> pos, Vec3<float> direccion, Vec3<float> color)
{
	TFlashLight* light =SceneManager::i().crearNodoFlashLight(pos,direccion);
	light->setColor(color.getX(), color.getY(), color.getZ());
	light->setIntensidadDifusa(0.8f);
	light->setIntensidadAmbiente(0.4f);
	return true;
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
	
	
	//mandas que se dibuje el debug a las fisicas
	if (debug_draw_bullet)
	{

		PhysicsEngine::i().m_world->debugDrawWorld();

	}

	if (StateStack::i().currentState == States::ID::InGame) {
		SceneManager::i().draw();

		
	}
	

	// FPS
	int fps = GraphicEngine::i().getDevice().getFPS();
	std::ostringstream title;
	title << u8"Last Bullet - Final Release FPS: " << fps;
	GraphicEngine::i().getDevice().setWindowTitle(title.str());
	//}

	
	GUIManager::i().drawAllGuis();
	
	sm.renderFrame(engine.getWindow());

}

void GraphicEngine::inicializar()
{
	screenWidth = 1280;
	screenHeight = 720;
	engine.createEngineDevice(screenWidth, screenHeight, u8"Last Bullet - Final Release");
	
	if (std::stoi(Settings::i().GetValue("fullscreen")) == 1) {
		engine.toggleWindowMode();
	}

	sm = SceneManager::i();

	engine.vSync(0);

	TSunLight* dsa = SceneManager::i().crearNodoSunLight(Vec3<float>(0.0f, 0.0f, -1.0f));
	dsa->setIntensidadAmbiente(0.45f); 
	dsa->setIntensidadEspecular(0.6f);

	dsa->setVectorDireccion(Vec3<float>(71.f, -47.f, -31.f));
	dsa->setPosition(Vec3<float>(-10.f, 61.f, -70.f));
	
	SceneManager::i().setSunLight(dsa); //importante sin esta linea no se dibujan sombras

	createCamera("CamaraPlayer", Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	createCamera("CameraDeath", Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	setActiveCamera("CamaraPlayer");
	sm.camaraActiva->setFarPlane(1000.f);
	
}


bool GraphicEngine::isWindowActive()
{
	return !engine.shouldCloseWindw();
}

bool GraphicEngine::apagar()
{
	delete debugDraw;

	engine.end();
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

void GraphicEngine::removeNode(std::shared_ptr<SceneNode> nodo) {
	nodo->getEntityNode()->removeEntity();
}


void GraphicEngine::setDebugDraw()
{
	debugDraw = new DebugDraw();
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



	debug_draw_bullet = false;
}

void GraphicEngine::apuntar()
{
	SceneManager::i().ziZoom(38.0f);
}

void GraphicEngine::restablecerMirilla()
{
	SceneManager::i().zoomZout();
}


