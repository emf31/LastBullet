#pragma once

#include <Player.h>
#include <GUI.h>
//#include <Player.h>


class InGameHUD: public Motor::GUI {
public:

	InGameHUD();

	void inicializar();

	virtual void update() override;

	void updateLabelVida();

	void updateLabelArma();

	void updateLabelMunicion();

	void updateLabelMunicionTotal();
private:
	CEGUI::DefaultWindow* LabelVida;
	CEGUI::DefaultWindow* LabelArma;
	CEGUI::DefaultWindow* LabelMunicion;
	CEGUI::DefaultWindow* LabelMunicionTotal;

	Player *p;

};