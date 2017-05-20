#pragma once


#include <GraphicEngine.h>
#include <GUI.h>
#include <events\Event.h>
#include <Player.h>



class MenuGUI : public Motor::GUI {
public:
	struct PlayerSlot {
		CEGUI::DefaultWindow* name;
		CEGUI::DefaultWindow* ReadyImage;
		CEGUI::DefaultWindow* NotReadyImage;

		bool isEmpty() {
			if (name->getText() == "") {
				return true;
			} else {
				return false;
			}
		}

		void setReady(bool ready) {
			if (ready) {
				NotReadyImage->setVisible(false);
				ReadyImage->setVisible(true);
			} else {
				NotReadyImage->setVisible(true);
				ReadyImage->setVisible(false);
			}
		}

		std::string getName() {
			return name->getText().c_str();
		}

		void setName(const std::string& nombre) {
			name->setText(nombre);
		}

		void setFree() {
			setName("");
			NotReadyImage->setVisible(false);
			ReadyImage->setVisible(false);
		}

	};

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
	bool onApplySounds(const CEGUI::EventArgs & e);
	bool onUpdateSliderSound(const CEGUI::EventArgs & e);
	bool onUpdateSliderMusic(const CEGUI::EventArgs & e);
	bool onBotsSlider(const CEGUI::EventArgs & e);
	

	bool onReadyBtnClicked(const CEGUI::EventArgs & e);
	bool onInviteBtnClicked(const CEGUI::EventArgs & e);
	bool onBackButtonClicked(const CEGUI::EventArgs & e);

	PlayerSlot* setNameOnPlayerSlot(const std::string& name);

	void setSlotFree(const std::string& str);

	void changeStateToLobbyView() {
		changeState(stateMenu::enumLobby);
	}

	PlayerSlot* findSlotByName(const std::string& name) {
		if (PlayerSlot1.getName() == name) {
			return &PlayerSlot1;
		}
		if (PlayerSlot2.getName() == name) {
			return &PlayerSlot2;
		}
		if (PlayerSlot3.getName() == name) {
			return &PlayerSlot3;
		}
		if (PlayerSlot4.getName() == name) {
			return &PlayerSlot4;
		}
		return nullptr;
	}

	PlayerSlot* findEmptyNameSlot() {

		if (PlayerSlot1.isEmpty()) {
			return &PlayerSlot1;
		}
		if (PlayerSlot2.isEmpty()) {
			return &PlayerSlot2;
		}
		if (PlayerSlot3.isEmpty()) {
			return &PlayerSlot3;
		}
		if (PlayerSlot4.isEmpty()) {
			return &PlayerSlot4;
		}
		return nullptr;
	}

	bool onConnectClicked(const CEGUI::EventArgs & e);
	bool onEditBoxClicked(const CEGUI::EventArgs & e);

	CEGUI::Editbox *editBox;

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
	CEGUI::DefaultWindow* LobbyWindow;

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
	CEGUI::PushButton *connect;
	

	CEGUI::PushButton *Atras1;
	CEGUI::PushButton *Atras2;
	CEGUI::PushButton *Atras3;
	CEGUI::PushButton *Atras4;

	CEGUI::PushButton *ApplySounds;
	CEGUI::Slider *SoundSlider;
	CEGUI::Slider *MusicSlider;
	CEGUI::DefaultWindow* SoundLabel;
	CEGUI::DefaultWindow* MusicLabel;

	CEGUI::Slider *sliderBots;
	CEGUI::DefaultWindow *numBots;

	CEGUI::DefaultWindow *imagen;
	CEGUI::DefaultWindow *imagen2;

	std::vector < CEGUI::String > animacionPlaneta;

	//Lobby
	CEGUI::PushButton *ReadyBtn;
	CEGUI::PushButton *InviteBtn;
	CEGUI::PushButton *BackBtn;

	PlayerSlot PlayerSlot1;
	PlayerSlot PlayerSlot2;
	PlayerSlot PlayerSlot3;
	PlayerSlot PlayerSlot4;

	/*CEGUI::DefaultWindow* PlayerSlot1Lbl;
	CEGUI::DefaultWindow* PlayerSlot2Lbl;
	CEGUI::DefaultWindow* PlayerSlot3Lbl;
	CEGUI::DefaultWindow* PlayerSlot4Lbl;
	CEGUI::DefaultWindow* Player1Ready;
	CEGUI::DefaultWindow* Player2Ready;
	CEGUI::DefaultWindow* Player3Ready;
	CEGUI::DefaultWindow* Player4Ready;
	CEGUI::DefaultWindow* Player1NotReady;
	CEGUI::DefaultWindow* Player2NotReady;
	CEGUI::DefaultWindow* Player3NotReady;
	CEGUI::DefaultWindow* Player4NotReady;*/

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