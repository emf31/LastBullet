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

		SceneManager::i().draw_mode = 8;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F10)) {

		LogIA::writeLog();
	}/* else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F11)) {
		particleSystem.createExplosion(EntityManager::i().getEntity(PLAYER)->getPosition());
	}*/
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_9)) {		//Prueba para borrar de clipping//En caso de que le des a f12 comprueba si el punto 0,0,0 esta en su frustrum
		GraphicEngine::i().updateClippingPlanes();
		float x = 0.f;
		float y = 0.f;
		float z = 0.f;

		float plano1[4] = { GraphicEngine::i().planes[0][0],GraphicEngine::i().planes[0][1],GraphicEngine::i().planes[0][2],GraphicEngine::i().planes[0][3] };
		float val_DER = plano1[0] * x + plano1[1] * y + plano1[2] * z + plano1[3];
		float plano2[4] = { GraphicEngine::i().planes[1][0],GraphicEngine::i().planes[1][1],GraphicEngine::i().planes[1][2],GraphicEngine::i().planes[1][3] };
		float val_IZ = plano2[0] * x + plano2[1] * y + plano2[2] * z + plano2[3];
		std::cout << "Izquierda " << val_IZ << std::endl;
		std::cout << "Derecha " << val_DER << std::endl;

		if(val_DER<0 && val_IZ>0)
			std::cout << "ESTO FUNCIONA SOY DIOS"<< std::endl;
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






