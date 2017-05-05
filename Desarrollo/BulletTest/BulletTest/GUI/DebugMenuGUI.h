#pragma once

#include <GraphicEngine.h>
#include <GUI.h>
#include <Enemy_Bot.h>
#include <EntityManager.h>
#include <events\Event.h>
#include <NetworkDebugger.h>
#include <NetworkLog.h>

class DebugMenuGUI : public Motor::GUI {
public:
	DebugMenuGUI();
	~DebugMenuGUI();

	virtual void update() override;
	virtual void handleEvent(Event * ev) override;

	//Imprime un texto por pantalla
	void addPrintText(const std::string& str) {
		if () {

		}
		PrintText.push_back(str);
	}

	void inicializar();
	
private:
	
	bool onDebugBotAClicked(const CEGUI::EventArgs & e);
	bool onDebugBotBClicked(const CEGUI::EventArgs & e);
	bool onDebugBotCClicked(const CEGUI::EventArgs & e);
	bool onDebugBotDClicked(const CEGUI::EventArgs & e);

	bool onDebugShapesClicked(const CEGUI::EventArgs& e);
	bool onCloseMenuButtonClicked(const CEGUI::EventArgs & e);
	bool onMapClicked(const CEGUI::EventArgs & e);
	bool onDebugNetworkClicked(const CEGUI::EventArgs & e);
	bool onDebugIAClicked(const CEGUI::EventArgs & e);
	bool onDebugIAMapaClicked(const CEGUI::EventArgs & e);
	bool onDebugIAVIDAClicked(const CEGUI::EventArgs & e);
	bool onDebugIAROCKETClicked(const CEGUI::EventArgs & e);
	bool onDebugIAASALTOClicked(const CEGUI::EventArgs & e);
	bool onDebugIAPISTOLAClicked(const CEGUI::EventArgs & e);
	bool onCloseMenuButtonIAClicked(const CEGUI::EventArgs & e);
	bool onCloseMenuButtonNetSyncClicked(const CEGUI::EventArgs & e);
	bool onCloseMenuButtonNetDebugClicked(const CEGUI::EventArgs & e);

	bool onVaciarAsalto(const CEGUI::EventArgs & e);
	bool onVaciarRocket(const CEGUI::EventArgs & e);
	bool onVaciarSniper(const CEGUI::EventArgs & e);
	bool onVaciarPistola(const CEGUI::EventArgs & e);

	bool onCamaraAerea(const CEGUI::EventArgs & e);
	bool onCamaraBot(const CEGUI::EventArgs & e);

	bool onInsAsalto(const CEGUI::EventArgs & e);
	bool onInsRocket(const CEGUI::EventArgs & e);
	bool onInsSniper(const CEGUI::EventArgs & e);
	bool onInsPistola(const CEGUI::EventArgs & e);

	bool onLogNetworkClicked(const CEGUI::EventArgs & e);
	bool onUpdateLogButtonClicked(const CEGUI::EventArgs & e);

	bool onEstadosIA(const CEGUI::EventArgs & e);

	bool onUpdateSlider(const CEGUI::EventArgs & e);

	bool onGodMode(const CEGUI::EventArgs & e);

	Vec3<float> elegirColor(std::string estadoActual);

	void updateProgressBars(NetworkDebugger* deb);
	void updateFuzzyProgressBars();

	void updateNetworkWindowInfo(NetworkDebugger* deb);
	void crearNodosState();

	void crearNodoBot(Entity* myentity);

	CEGUI::PushButton *DebugShapesButton;
	CEGUI::PushButton *closePushButton;
	

	//NetworkLog
	CEGUI::PushButton *NetworkLogButton;
	CEGUI::DefaultWindow *NetworkLogWindow;
	CEGUI::MultiLineEditbox *serverLog;
	CEGUI::MultiLineEditbox *clientLog;
	CEGUI::PushButton *UpdateLogButton;

	//Network
	CEGUI::PushButton *DebugNetwork;
	CEGUI::DefaultWindow *NetworkWindow;
	CEGUI::DefaultWindow *NetworSyncWindow;
	CEGUI::ProgressBar *movimientoPB;
	CEGUI::ProgressBar *disparosPB;
	CEGUI::ProgressBar *impactoPB;
	CEGUI::ProgressBar *dropArmaPB;
	CEGUI::ProgressBar *dropVidaPB;
	CEGUI::ProgressBar *muertePB;
	CEGUI::ProgressBar *granadaPB;
	CEGUI::ProgressBar *aumentaKillPB;
	CEGUI::ProgressBar *aumentaMuertePB;
	CEGUI::PushButton *closePushButtonNetSync;
	CEGUI::PushButton *closePushButtonNetDebug;

	CEGUI::ToggleButton *toggleCountMovement;

	CEGUI::DefaultWindow *labelStatus;
	CEGUI::DefaultWindow *labelPing;
	CEGUI::DefaultWindow *labelTotalPackets;
	CEGUI::DefaultWindow *labelPacketsIn;
	CEGUI::DefaultWindow *labelPacketsOut;
	CEGUI::DefaultWindow *labelServerIp;
	CEGUI::DefaultWindow *labelNumPlayers;

	bool networkOpen = false;
	

	//IA
	CEGUI::PushButton *DebugIA;
	CEGUI::DefaultWindow *mapa;
	CEGUI::DefaultWindow *IAWindow;
	CEGUI::DefaultWindow *DesirabilityWeapons;
	CEGUI::DefaultWindow *OpcionesIA;
	CEGUI::PushButton *BuscarVida;
	CEGUI::PushButton *BuscarPistola;
	CEGUI::PushButton *BuscarRocket;
	CEGUI::PushButton *BuscarAsalto;
	CEGUI::PushButton *BotonMapa;

	CEGUI::PushButton *VaciarAsalto;
	CEGUI::PushButton *VaciarRocket;
	CEGUI::PushButton *VaciarSniper;
	CEGUI::PushButton *VaciarPistola;

	CEGUI::PushButton *InsAsalto;
	CEGUI::PushButton *InsRocket;
	CEGUI::PushButton *InsSniper;
	CEGUI::PushButton *InsPistola;

	CEGUI::PushButton *CamaraAerea;

	CEGUI::PushButton *CamaraBot;

	CEGUI::ProgressBar *DesiAsalto;
	CEGUI::ProgressBar *DesiRocketLauncher;
	CEGUI::ProgressBar *DesiSniper;

	CEGUI::PushButton *BotA;
	CEGUI::PushButton *BotB;
	CEGUI::PushButton *BotC;
	CEGUI::PushButton *BotD;

	CEGUI::PushButton *estadosIA;

	CEGUI::PushButton *closePushButtonIA;

	CEGUI::Slider *sliderUpdate;

	float progresoAsalto = 0;
	float progresoRocketLauncher = 0;
	float progresoSniper = 0;
	bool VerEstadosIA=false;

	Character* entActual;

	std::shared_ptr<BasicSceneNode> nodos[4];

	NetworkLog netWorkLog;

	//String para imprimir por pantalla cualquier info de debug
	std::vector<std::string> PrintText;
	//Controla el maximo de mensajes que se imprimen al mismo tiempo
	int maxPrintableTexts;
};