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
	bool onUpdateSliderSound(const CEGUI::EventArgs & e);
	bool onUpdateSliderMusic(const CEGUI::EventArgs & e);
	bool onBotsSlider(const CEGUI::EventArgs & e);
	bool onLanServerBtnActivated(const CEGUI::EventArgs & e);
	bool onLanServerBtnDeactivated(const CEGUI::EventArgs & e);
	bool onShadowsChange(const CEGUI::EventArgs & e);

	bool onMaxKillClicked(const CEGUI::EventArgs & e);
	
	

	bool onReadyBtnClicked(const CEGUI::EventArgs & e);
	bool onInviteBtnClicked(const CEGUI::EventArgs & e);
	bool onBackButtonClicked(const CEGUI::EventArgs & e);
	bool DifficultySliderChanged(const CEGUI::EventArgs & e);

	std::string numberShadowToString(int number);

	PlayerSlot* setNameOnPlayerSlot(const std::string& name);

	int getNumBots() {
		return (int)sliderBots->getCurrentValue();
	}

	void setSlotFree(const std::string& str);

	void freeAllSlots();

	void changeStateToLobbyView() {
		changeState(stateMenu::enumLobby);
	}

	PlayerSlot* findSlotByName(const std::string& name);

	PlayerSlot* findEmptyNameSlot();

	bool onConnectClicked(const CEGUI::EventArgs & e);
	bool onEditBoxClicked(const CEGUI::EventArgs & e);
	void setServerType(int type);

	bool onFullscreenChange(const CEGUI::EventArgs & e);
	bool onWindowedChange(const CEGUI::EventArgs & e);

	CEGUI::Editbox *editBox;

private:

	long int imagen1_x;
	long int imagen2_x;
	int m_shadows;

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
	CEGUI::PushButton *OptionsBtn;

	CEGUI::ToggleButton *LanServerBtn;

	CEGUI::DefaultWindow *ServerLbl;
	CEGUI::DefaultWindow *InternetLbl;
	CEGUI::DefaultWindow *LanLbl;

	CEGUI::Slider *MaxKillEb;
	CEGUI::DefaultWindow *MaxKillLbl;

	CEGUI::Slider *BotDifficultySlider;
	CEGUI::DefaultWindow *BotDifficultyLbl;


	PlayerSlot PlayerSlot1;
	PlayerSlot PlayerSlot2;
	PlayerSlot PlayerSlot3;
	PlayerSlot PlayerSlot4;

	//Video

	CEGUI::Slider* Sombras;
	CEGUI::DefaultWindow* SombrasLabel;
	CEGUI::ToggleButton* Clipping;
	CEGUI::ToggleButton* Oclusions;
	CEGUI::RadioButton* Windowed;
	CEGUI::RadioButton* Fullscreen;

	std::shared_ptr<NetPlayer> netPlayer;

	int FrameActual;

	void updateFondo(int velocidad);
	void rellenarAnimacionPlaneta();
	void reproducirAnimacionPlaneta();
	void changeState(stateMenu Newstate);
	void setStateVisible(stateMenu state, bool visible);
	void actualizarTopOpciones();
	
	std::string intToBotDifficulty(int diff);

	int stringToBotDifficulty(const std::string& diff);

	stateMenu lastState;

	unsigned int lastKey = 0;
};