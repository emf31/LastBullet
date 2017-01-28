#pragma once

#include <GraphicEngine.h>
#include <GUI.h>
#include <Enemy_Bot.h>
#include <EntityManager.h>
#include <Cliente.h>
class DebugMenuGUI : public Motor::GUI {
public:
	virtual void update() override;
	void inicializar();
	
private:
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

	void updateProgressBars();

	CEGUI::PushButton *DebugShapesButton;
	CEGUI::PushButton *closePushButton;
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
	bool networkOpen = false;

	//IA
	CEGUI::PushButton *DebugIA;
	CEGUI::DefaultWindow *mapa;
	CEGUI::DefaultWindow *IAWindow;
	CEGUI::PushButton *BuscarVida;
	CEGUI::PushButton *BuscarPistola;
	CEGUI::PushButton *BuscarRocket;
	CEGUI::PushButton *BuscarAsalto;
	CEGUI::PushButton *BotonMapa;
	CEGUI::PushButton *closePushButtonIA;


	Enemy_Bot* botJuliyo;
	//Enemy_Bot* botTonire;
	//Enemy_Bot* botRucri;

	
};