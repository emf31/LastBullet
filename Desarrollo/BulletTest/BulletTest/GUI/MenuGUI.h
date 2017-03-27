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
	bool onOpcionesAudioClicked(const CEGUI::EventArgs & e);
	bool onOpcionesVideoClicked(const CEGUI::EventArgs & e);
	bool onOpcionesGameClicked(const CEGUI::EventArgs & e);
	bool onSalirClicked(const CEGUI::EventArgs & e);
	bool onConexion1Clicked(const CEGUI::EventArgs & e);
	bool onConexion2Clicked(const CEGUI::EventArgs & e);
private:
	int imagen1_ini;
	int imagen2_ini;

	int imagen1_x;
	int imagen2_x;

	CEGUI::Image* Planeta;

	CEGUI::DefaultWindow* LastBullet;
	CEGUI::DefaultWindow* UnirWindow;
	CEGUI::DefaultWindow* UnirLabel;
	CEGUI::DefaultWindow* Conexiones;
	CEGUI::DefaultWindow* Titulo;

	CEGUI::PushButton *CrearPartida;
	CEGUI::PushButton *UnirPartida;
	CEGUI::PushButton *OpcionesVideo;
	CEGUI::PushButton *OpcionesAudio;
	CEGUI::PushButton *OpcionesGame;
	CEGUI::PushButton *Salir;


	CEGUI::PushButton *Conexion1;
	CEGUI::PushButton *Conexion2;
	CEGUI::PushButton *Actualizar;

	CEGUI::DefaultWindow *imagen;
	CEGUI::DefaultWindow *imagen2;

	//std::thread t;

	Player* p;

	void updateFondo(int velocidad);
};