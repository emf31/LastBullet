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
	CEGUI::DefaultWindow* UnirWindow;
	CEGUI::DefaultWindow* UnirLabel;
	CEGUI::DefaultWindow* Conexiones;
	CEGUI::DefaultWindow* Titulo;

	CEGUI::PushButton *CrearPartida;
	CEGUI::PushButton *UnirPartida;
	CEGUI::PushButton *Salir;
	CEGUI::PushButton *Conexion1;
	CEGUI::PushButton *Conexion2;

	Player* p;


};