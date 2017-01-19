#pragma once

#include <GraphicEngine.h>
#include <GUI.h>
#include <Enemy_Bot.h>
class DebugMenuGUI : public Motor::GUI {
public:
	virtual void update() override;
	void inicializar();
	CEGUI::DefaultWindow *mapa;
private:
	bool onDebugShapesClicked(const CEGUI::EventArgs& e);
	bool onCloseMenuButtonClicked(const CEGUI::EventArgs & e);
	bool onMapClicked(const CEGUI::EventArgs & e);

	CEGUI::PushButton *DebugShapesButton;
	CEGUI::PushButton *closePushButton;
	Enemy_Bot* botJuliyo;
	//Enemy_Bot* botTonire;
	//Enemy_Bot* botRucri;

	
};