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

	CEGUI::PushButton *DebugShapesButton;
	CEGUI::PushButton *closePushButton;
	CEGUI::PushButton *DebugIA;
	CEGUI::PushButton *DebugNetwork;
	CEGUI::DefaultWindow *NetworkWindow;
	CEGUI::DefaultWindow *mapa;
	Enemy_Bot* botJuliyo;
	//Enemy_Bot* botTonire;
	//Enemy_Bot* botRucri;

	
};