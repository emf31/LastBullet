#pragma once

#include <Player.h>

#include <GUI.h>
//#include <Player.h>

struct fila_tabla {
	CEGUI::DefaultWindow* label;
	CEGUI::DefaultWindow* muertes;
	CEGUI::DefaultWindow* bajas;
	CEGUI::DefaultWindow* puntos;
};

class InGameHUD : public Motor::GUI {
public:

	InGameHUD();

	void inicializar();

	virtual void update() override;

	virtual void handleEvent(Event * ev) override;

	void newFeed(const std::string& killer,const std::string& death);

	void updateLabelVida();

	void updateLabelArma();

	void updateLabelMunicion();

	void updateLabelMunicionTotal();

	void setTablaVisible(bool visible);

	void setPlayerName(int player, const std::string& nombre);

	void setPlayerKills(int player, int kills);

	void setPlayerDeaths(int player, int deaths);

	void setPlayerPoints(int player, int points);

	void setRanking(int rank);

	void setKills(int kills);

	void setDeaths(int death);

	void updateProgressBarVida();

	void updateProgressBarMunicion();

	void updateRelojes();

	void updateApuntando();

	void muestraFinPartida(const std::string& name);

	bool isInCuentaAtras() { return activeCuentaAtras; }

	bool setVisibleAllHUD(bool visible);

	fila_tabla player1;
	fila_tabla player2;
	fila_tabla player3;
	fila_tabla player4;

	void desactivarCuentaAtras();
	
	void empezarCuentaAtras();

	void updateCuentaAtras();

	void clear() {
		countTime.restart();
		feedTime.restart();
		count = 10;
		activeCuentaAtras = true;
	}

private:

	CEGUI::DefaultWindow* AllHUD;

	CEGUI::DefaultWindow* Feed;

	CEGUI::DefaultWindow* scope;

	CEGUI::DefaultWindow* LabelVida;
	//CEGUI::DefaultWindow* LabelArma;
	CEGUI::DefaultWindow* ImagenPistola;
	CEGUI::DefaultWindow* ImagenAsalto;
	CEGUI::DefaultWindow* ImagenRocket;
	CEGUI::DefaultWindow* ImagenSniper;
	CEGUI::DefaultWindow* LabelMunicion;
	CEGUI::DefaultWindow* LabelMunicionTotal;
	CEGUI::ProgressBar  * ProgressBarVida;
	CEGUI::ProgressBar  * ProgressBarMunicion;

	CEGUI::DefaultWindow* LabelEndGame;

	CEGUI::DefaultWindow* hitMarker;
	CEGUI::DefaultWindow* sangre;
	

	CEGUI::DefaultWindow* windowTabla;

	CEGUI::DefaultWindow* m_ranking;
	CEGUI::DefaultWindow* m_kills;
	CEGUI::DefaultWindow* m_deaths;

	CEGUI::DefaultWindow* m_LabelCuenta;
	CEGUI::DefaultWindow* m_LabelCuentaInfo;
	CEGUI::DefaultWindow* m_WindowCuenta;

	Player *p;

	
	Clock countTime;
	Clock feedTime;
	int count;
	bool activeCuentaAtras;
};