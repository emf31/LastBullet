#include "InGame.h"
#include <EntityManager.h>
#include <TriggerSystem.h>
#include <EventSystem.h>
#include <PhysicsEngine.h>
#include <GraphicEngine.h>
#include <MessageHandler.h>
#include <GUIManager.h>
#include <World.h>
#include <LogIA.h>

#include <ParticleSystem.h>
InGame::InGame() : ingameGUI(), debugMenu(), salirGUI(), particleSystem(ParticleSystem::i())
{
	
}

InGame::~InGame()
{
}

void InGame::Inicializar()
{

	PhysicsEngine::i().inicializar();

	ingameGUI.inicializar();
	debugMenu.inicializar();
	salirGUI.inicializar();

	World::i().inicializar();

	const std::vector<TPlayer> enemies = NetworkManager::i().getEnemies();
	const std::vector<TPlayer> bots = NetworkManager::i().getBots();

	for (auto it = enemies.begin(); it != enemies.end(); ++it) {
		Enemy *e = new Enemy(it->name, it->guid);
		e->inicializar();
		e->cargarContenido();
		e->setPosition(it->position);

		EntityManager::i().registerRaknetEntity(e);
	}


	for (auto it = bots.begin(); it != bots.end(); ++it) {
		Enemy_Bot *bot = new Enemy_Bot(it->name, RakNet::UNASSIGNED_RAKNET_GUID);
		bot->m_network->inicializar();
		bot->inicializar();
		bot->cargarContenido();
	}

	
	
	GraphicEngine::i().getActiveCamera()->setInputReceiver(true);
	//tiempo.restart();
	//myfile.open("tiempos.txt");

	GraphicEngine::i().enableMouse(false);

	particleSystem.inicializar();
	
}

void InGame::Clear()
{
	//myfile.close();
	EntityManager::i().apagar();
	GraphicEngine::i().apagar();
	PhysicsEngine::i().apagar();
	TriggerSystem::i().apagar();

	NetworkManager::i().apagar();

	MessageHandler::i().borrarContenido();

	particleSystem.apagar();
}

void InGame::HandleEvent()
{


	if (!debugMenu.debugInput && !salirGUI.escapeInput) {
		EntityManager::i().getEntity(PLAYER)->handleInput();
	}

	//Teclas debug
	if (Input::i().keyReleased((unsigned int)GLFW_KEY_1)) {

		GraphicEngine::i().toggleDebug();

	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_2)) {

		GraphicEngine::i().toggleCamera();

	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_TAB)) {

		ingameGUI.setTablaVisible(false);

	}
	else if (Input::i().keyDown((unsigned int)GLFW_KEY_TAB)) {

		ingameGUI.setTablaVisible(true);
		World::i().getPartida()->muestraTabla();

	}
	else if (Input::i().keyPressed((unsigned int)GLFW_KEY_F1)) {
		
		debugMenu.debugInput = !debugMenu.debugInput;
		GraphicEngine::i().enableMouse(debugMenu.debugInput);
		//GraphicEngine::i().setCursorVisible(GraphicEngine::i().getGui().debugInput);
		debugMenu.showMouseCursor(debugMenu.debugInput);
		GraphicEngine::i().getActiveCamera()->setInputReceiver(!debugMenu.debugInput);
		debugMenu.getContext()->getRootWindow()->getChild(0)->getChild(10)->setVisible(debugMenu.debugInput);
		
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_ESCAPE)) {
		salirGUI.escapeInput = !salirGUI.escapeInput;
		GraphicEngine::i().enableMouse(salirGUI.escapeInput);
		//GraphicEngine::i().setCursorVisible(GraphicEngine::i().getGui().debugInput);
		salirGUI.showMouseCursor(salirGUI.escapeInput);
		GraphicEngine::i().getActiveCamera()->setInputReceiver(!salirGUI.escapeInput);
		salirGUI.Window->setVisible(salirGUI.escapeInput);
		ingameGUI.getContext()->getRootWindow()->getChild(0)->setVisible(!salirGUI.escapeInput);
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F2)) {
		SceneManager::i().draw_mode = 1;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F3)) {
		SceneManager::i().draw_mode = 2;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F4)) {
		SceneManager::i().draw_mode = 3;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F5)) {
		SceneManager::i().draw_mode = 4;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F6)) {
		SceneManager::i().draw_mode = 5;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F7)) {
		
		SceneManager::i().draw_mode = 6;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F8)) {

		SceneManager::i().draw_mode = 7;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F9)) {

		SceneManager::i().draw_mode = 9;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F10)) {

		LogIA::writeLog();
	} else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F11)) {
		particleSystem.createExplosion(EntityManager::i().getEntity(PLAYER)->getPosition());
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_R)) {
		std::cout << "Posicion 1: " << std::endl;
		SceneManager::i().getSunLight()->setPosition(Vec3<float>(110, 66 , -121));
		SceneManager::i().getSunLight()->setVectorDireccion(Vec3<float>(49, -6, -25));
		
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_T)) {
		std::cout << "Posicion 2: " << std::endl;
		SceneManager::i().getSunLight()->setPosition(Vec3<float>(50, 106, -124));
		SceneManager::i().getSunLight()->setVectorDireccion(Vec3<float>(49, -43, 17));
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_Y)) {
		std::cout << "Posicion 3: " << std::endl;
		SceneManager::i().getSunLight()->setPosition(Vec3<float>(0, 61, -106));
		SceneManager::i().getSunLight()->setVectorDireccion(Vec3<float>(51, -43, 18));
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_U)) {
		std::cout << "Posicion 4: " << std::endl;
		SceneManager::i().getSunLight()->setPosition(Vec3<float>(10, 71, 15));
		SceneManager::i().getSunLight()->setVectorDireccion(Vec3<float>(46, 136, -31));
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_I)) {
		std::cout << "Posicion 5: " << std::endl;
		SceneManager::i().getSunLight()->setPosition(Vec3<float>(-20, 46, -75));
		SceneManager::i().getSunLight()->setVectorDireccion(Vec3<float>(46, -4, -31));
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_O)) {
		std::cout << "Posicion 6: " << std::endl;
		SceneManager::i().getSunLight()->setPosition(Vec3<float>(-10, 53, -65));
		SceneManager::i().getSunLight()->setVectorDireccion(Vec3<float>(71, -22, -31));
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_P)) {
		std::cout << "Posicion 7: " << std::endl;
		SceneManager::i().getSunLight()->setPosition(Vec3<float>(-10, 61, -70));
		SceneManager::i().getSunLight()->setVectorDireccion(Vec3<float>(71, -47, -31));
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_I)) {
		Vec3<float> dir = SceneManager::i().getSunLight()->getDireccion();
		dir.setY(dir.getY() + 1);
		//SceneManager::i().getSunLight()->setVectorDireccion(dir);
		//std::cout << "Direccion sol: ";
		//dir.display();
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_L)) {
		SceneManager::i().bias += 0.0001;
		std::cout << "Aumento bias, bias = " << SceneManager::i().bias << std::endl;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_K)) {
		SceneManager::i().bias -= 0.0001;
		std::cout << "Aumento bias, bias = " << SceneManager::i().bias << std::endl;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_J)) {
		std::cout << "Activo sombras Estaticas"<< std::endl;
		SceneManager::i().activeStaticShadow(true);
		SceneManager::i().activeDynamicShadow(false);
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_H)) {
		std::cout << "Activo sombras Dinamicas" << std::endl;
		SceneManager::i().activeStaticShadow(false);
		SceneManager::i().activeDynamicShadow(true);
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_G)) {
		std::cout << "Desactivo sombras Estaticas" << std::endl;
		SceneManager::i().activeStaticShadow(false);
		SceneManager::i().activeDynamicShadow(false);
	}
	else if (Input::i().leftMouseDown()) {

		debugMenu.injectLeftMouseButton();
		salirGUI.injectLeftMouseButton();

	}
	else if (Input::i().leftMouseUp()) {

		debugMenu.injectLeftMouseButtonUp();
		salirGUI.injectLeftMouseButtonUp();

	}

	Input::i().endEventProcess();

}

void InGame::Update(Time timeElapsed)
{


	PhysicsEngine::i().cleanDeleteObjects();
	EntityManager::i().cleanDeleteQueue();


	EntityManager::i().update(timeElapsed);

	TriggerSystem::i().Update();

	PhysicsEngine::i().notifyCollisions();

	World::i().getPartida()->muestraMarcador();

	MessageHandler::i().update();

	EventSystem::i().update();

	particleSystem.update(timeElapsed);

	GUIManager::i().updateAllGuis();
}

void InGame::Render(float interpolation, Time elapsedTime)
{
	EntityManager::i().updateRender(interpolation);

	

	GraphicEngine::i().updateCamera();

	Player* player = static_cast<Player*>(EntityManager::i().getEntity(PLAYER));
	player->updateCurrentWeaponPosition();

	//GUI
	if(debugMenu.debugInput)
	debugMenu.injectMousePosition((float)Input::i().mouse.X, (float)Input::i().mouse.Y);


	if(salirGUI.escapeInput)
	salirGUI.injectMousePosition((float)Input::i().mouse.X, (float)Input::i().mouse.Y);

	//tiempo1 = tiempo.getElapsedTime().asMilliseconds();
	
	GraphicEngine::i().renderAll();
	//tiempo2 = tiempo.getElapsedTime().asMilliseconds();
	//tiempoFinal = tiempo2 - tiempo1;
	//
	//myfile << tiempoFinal << "\n";
}






