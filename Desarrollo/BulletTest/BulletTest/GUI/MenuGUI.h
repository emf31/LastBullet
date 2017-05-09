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
	bool onAtrasClicked(const CEGUI::EventArgs & e);
private:

	int imagen1_x;
	int imagen2_x;

	enum stateMenu {
		enumPrincipal, enumUnir, enumOpcionesAudio, enumOpcionesVideo, enumOpcionesGame, enumLobby
	} m_stateMenu;

	

	CEGUI::DefaultWindow* Planeta;

	CEGUI::DefaultWindow* LastBullet;
	CEGUI::DefaultWindow* UnirWindow;
	CEGUI::DefaultWindow* OpcionesAudioWindow;
	CEGUI::DefaultWindow* OpcionesVideoWindow;
	CEGUI::DefaultWindow* OpcionesGameWindow;

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

	CEGUI::PushButton *Atras1;
	CEGUI::PushButton *Atras2;
	CEGUI::PushButton *Atras3;
	CEGUI::PushButton *Atras4;

	CEGUI::DefaultWindow *imagen;
	CEGUI::DefaultWindow *imagen2;

	std::vector < CEGUI::String > animacionPlaneta;

	//std::thread t;

	std::shared_ptr<NetPlayer> netPlayer;
	int FrameActual;

	void updateFondo(int velocidad);
	void rellenarAnimacionPlaneta();
	void reproducirAnimacionPlaneta();
	void changeState(stateMenu Newstate);
	void setStateVisible(stateMenu state, bool visible);
	void actualizarTopOpciones();
};