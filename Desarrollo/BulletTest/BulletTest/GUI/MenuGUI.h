#pragma once


#include <GraphicEngine.h>
#include <GUI.h>
#include <events\Event.h>
#include <Player.h>


class MenuGUI : public Motor::GUI {
public:

	MenuGUI();

	void inicializar();

	virtual void update() override;

	virtual void handleEvent(Event * ev) override;

	bool onCrearPartidaClicked(const CEGUI::EventArgs& e);
	bool onUnirPartidaClicked(const CEGUI::EventArgs & e);
	bool onSalirClicked(const CEGUI::EventArgs & e);

private:
	CEGUI::DefaultWindow* LastBullet;

	CEGUI::PushButton *CrearPartida;
	CEGUI::PushButton *UnirPartida;
	CEGUI::PushButton *Salir;

	Player* p;


};