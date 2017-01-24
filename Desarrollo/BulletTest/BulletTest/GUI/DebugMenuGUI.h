#pragma once

#include <GraphicEngine.h>
#include <GUI.h>
#include <Enemy_Bot.h>
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

	CEGUI::PushButton *DebugShapesButton;
	CEGUI::PushButton *closePushButton;
	CEGUI::PushButton *DebugIA;
	CEGUI::PushButton *DebugNetwork;
	CEGUI::DefaultWindow *NetworkWindow;
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