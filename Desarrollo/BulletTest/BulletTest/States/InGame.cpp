#include "InGame.h"
#include <../global.h>
#include <EntityManager.h>
#include <TriggerSystem.h>
#include <EventSystem.h>
#include <PhysicsEngine.h>
#include <GraphicEngine.h>
#include <MessageHandler.h>
#include <GUIManager.h>
#include <World.h>
#include <LogIA.h>
#include <ClippingManager.h>
#include <SoundManager.h>
#include <ParticleSystem.h>

#include <Map.h>
#include <Death.h>
#include <Run.h>
#include <Salto.h>
#include <StateStack.h>

InGame::InGame() : ingameGUI(), debugMenu(), salirGUI(), wantToExit(false)
{
	
}

InGame::~InGame()
{
}



void InGame::Inicializar()
{
	wantToExit = false;

	SoundManager::i().stopAllSounds();
	PhysicsEngine::i().inicializar();

	if (USING_STEAM) {
		m_player = new Player(SteamFriends()->GetPersonaName(), NetworkManager::i().getNetPlayer(), RakNet::UNASSIGNED_RAKNET_GUID);
	}
	else {
		m_player = new Player(Settings::i().GetValue("name"), NetworkManager::i().getNetPlayer(), RakNet::UNASSIGNED_RAKNET_GUID);
	}
	

	const std::vector<TPlayer> bots = NetworkManager::i().getBots();

	
	ingameGUI.inicializar();
	debugMenu.inicializar();
	salirGUI.inicializar();

	World::i().inicializar();

	std::list<std::shared_ptr<NetBot>>::iterator netbotit = NetworkManager::i().getNetBots().begin();
	for (auto it = bots.begin(); it != bots.end(); ++it) {
		Enemy_Bot *bot = new Enemy_Bot(it->name, RakNet::UNASSIGNED_RAKNET_GUID);
		Enemy_Bot::eDifficulty dificultad;
		switch (std::stoi(Settings::i().GetValue("difficulty"))) {
		case 0:
			dificultad = Enemy_Bot::eDifficulty::Easy;
			break;

		case 1:
			dificultad = Enemy_Bot::eDifficulty::Medium;
			break;

		case 2:
			dificultad = Enemy_Bot::eDifficulty::Hard;
			break;

		case 3:
			dificultad = Enemy_Bot::eDifficulty::Nightmare;
			break;

		default:
			dificultad = Enemy_Bot::eDifficulty::Medium;
		}
		bot->SetDifficulty(dificultad);
		bot->inicializar();
		bot->cargarContenido();

		(*netbotit)->SetBot(bot);
		bot->SetNetBot(*netbotit);

		++netbotit;
	}

	
	
	GraphicEngine::i().getActiveCamera()->setInputReceiver(true);

	GraphicEngine::i().enableMouse(false);
	
	NetworkManager::i().getNetPlayer()->getEnemyFactory().createEnemiesIfAvailable();


	SoundManager::i().playSound(Settings::i().GetResourceProvider().getFinalFilename("sonidoAmbiente.mp3", "sounds"), Sound::type::music);


}

void InGame::Clear()
{
	World::i().apagar();
	EntityManager::i().apagar();
	PhysicsEngine::i().apagar();
	TriggerSystem::i().apagar();

	NetworkManager::i().apagar();

	MessageHandler::i().borrarContenido();

	GraphicEngine::i().cleanScreen();

	//NetworkManager::i().getNetPlayer()->leaveLobby();
	NetworkManager::i().apagar();


}

void InGame::HandleEvent()
{
	if (!debugMenu.debugInput && !salirGUI.escapeInput && World::i().getPartida()->isAllReady()) {
		EntityManager::i().getEntity(PLAYER)->handleInput();
	}

	//Teclas debug
	if (Input::i().keyReleased((unsigned int)GLFW_KEY_1)) {

		GraphicEngine::i().toggleDebug();

	}
	/*else if (Input::i().keyReleased((unsigned int)GLFW_KEY_M)) {
		static_cast<Enemy*>(EntityManager::i().getEntity(1001))->animFrameTime++;
		static_cast<Enemy*>(EntityManager::i().getEntity(1001))->getNode()->setFrameTime(milliseconds(static_cast<Enemy*>(EntityManager::i().getEntity(1001))->animFrameTime));

		DebugMenuGUI* menu = static_cast<DebugMenuGUI*>(GUIManager::i().getGUIbyName("DebugMenuGUI"));
		menu->addPrintText(std::to_string(static_cast<Enemy*>(EntityManager::i().getEntity(1001))->animFrameTime));
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_N)) {
		static_cast<Enemy*>(EntityManager::i().getEntity(1001))->animFrameTime--;
		static_cast<Enemy*>(EntityManager::i().getEntity(1001))->getNode()->setFrameTime(milliseconds(static_cast<Enemy*>(EntityManager::i().getEntity(1001))->animFrameTime));

		DebugMenuGUI* menu = static_cast<DebugMenuGUI*>(GUIManager::i().getGUIbyName("DebugMenuGUI"));
		menu->addPrintText(std::to_string(static_cast<Enemy*>(EntityManager::i().getEntity(1001))->animFrameTime));
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_B)) {
		static_cast<Enemy*>(EntityManager::i().getEntity(1001))->getNode()->setCurrentAnimation("correrRocket");

		
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_V)) {
		static_cast<Enemy*>(EntityManager::i().getEntity(1001))->getNode()->setCurrentAnimation("idleRocket");

	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_C)) {
		static_cast<Enemy*>(EntityManager::i().getEntity(1001))->getNode()->setCurrentAnimation("muerte");

	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_X)) {
		static_cast<Enemy*>(EntityManager::i().getEntity(1001))->getNode()->setCurrentAnimation("saltoRocket");

	}*/

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
		
		SceneManager::i().draw_mode = 7;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F8)) {

		SceneManager::i().draw_mode = 8;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F9)) {

		SceneManager::i().draw_mode = 9;
	}
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F10)) {

		LogIA::writeLog();
	}/* else if (Input::i().keyReleased((unsigned int)GLFW_KEY_F11)) {
		particleSystem.createExplosion(EntityManager::i().getEntity(PLAYER)->getPosition());
	}*/
	else if (Input::i().keyReleased((unsigned int)GLFW_KEY_M)) {
		//GraphicEngine::i().createNode(Vec3<float>(x,y,z), Vec3<float>(1, 1, 1), "", "../media/box.obj");
		ClippingManager::i().printZonesVisibility();

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

	//Solo updateamos entities si esta todo listo
	if (World::i().getPartida()->isAllReady() && !World::i().getPartida()->isFinished()) {
		EntityManager::i().update(timeElapsed);
		
	}
	
	TriggerSystem::i().Update();

	PhysicsEngine::i().notifyCollisions();


	MessageHandler::i().update();

	EventSystem::i().update();

	GUIManager::i().updateAllGuis();

	SoundManager::i().update();

	if (wantToExit) {
		SalirHUD* menu = static_cast<SalirHUD*>(GUIManager::i().getGUIbyName("SalirHUD"));
		menu->clear();

		StateStack::i().GetCurrentState()->Clear();
		StateStack::i().SetCurrentState(States::ID::Menu);
		StateStack::i().GetCurrentState()->Inicializar();
	}

	
}

void InGame::Render(float interpolation, Time elapsedTime)
{

	EntityManager::i().updateRender(interpolation);


	ClippingManager::i().update();

	GraphicEngine::i().updateCamera();

	//Hack para el player, no podemos hacer que el arma siga la camara
	//de otra forma
	Player* player = static_cast<Player*>(EntityManager::i().getEntity(PLAYER));
	player->updateCurrentWeaponPosition();

	//GUI
	if(debugMenu.debugInput)
		debugMenu.injectMousePosition((float)Input::i().mouse.X, (float)Input::i().mouse.Y);


	if(salirGUI.escapeInput)
		salirGUI.injectMousePosition((float)Input::i().mouse.X, (float)Input::i().mouse.Y);



	GraphicEngine::i().renderAll();

}






