#pragma once

//#include <GraphicEngine.h>
#include <GUI.h>
class DebugMenuGUI : public Motor::GUI {
public:
	virtual void update() override;
	void inicializar();
private:
	bool onDebugShapesClicked(const CEGUI::EventArgs& e);
	bool onCloseMenuButtonClicked(const CEGUI::EventArgs & e);


	CEGUI::PushButton *DebugShapesButton;
	CEGUI::PushButton *closePushButton;
};