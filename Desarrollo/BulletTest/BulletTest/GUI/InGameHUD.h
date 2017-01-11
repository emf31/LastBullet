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
class InGameHUD: public Motor::GUI {
public:

	InGameHUD();

	void inicializar();

	virtual void update() override;

	void updateLabelVida();

	void updateLabelArma();

	void updateLabelMunicion();

	void updateLabelMunicionTotal();

	void setTablaVisible(bool visible);

	void setPlayerName(int player, const std::string& nombre);

	void setPlayerKills(int player, int kills);

	void setPlayerDeaths(int player, int deaths);

	void setPlayerPoints(int player, int points);

	void updateRelojes();

	fila_tabla player1;
	fila_tabla player2;
	fila_tabla player3;
	fila_tabla player4;
private:
	CEGUI::DefaultWindow* LabelVida;
	CEGUI::DefaultWindow* LabelArma;
	CEGUI::DefaultWindow* LabelMunicion;
	CEGUI::DefaultWindow* LabelMunicionTotal;

	CEGUI::DefaultWindow* hitMarker;
	CEGUI::DefaultWindow* sangre;

	CEGUI::DefaultWindow* windowTabla;

	

	Player *p;

};