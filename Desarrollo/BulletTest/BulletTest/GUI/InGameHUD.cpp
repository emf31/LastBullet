#include "InGameHUD.h"


InGameHUD::InGameHUD() {	
}

void InGameHUD::inicializar() {
	init("../GUI", GraphicEngine::i().getDevice());
	loadScheme("AlfiskoSkin.scheme");
	loadScheme("Generic.scheme");
	loadLayout("LastBulletHUD.layout");

	LabelVida = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));
	LabelArma = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	LabelMunicion = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
	LabelMunicionTotal = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(4));

	LabelEndGame = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(54));

	windowTabla = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10));

	hitMarker = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(51));
	sangre = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(52));

	player1.label = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(1));
	player1.bajas = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(11));
	player1.muertes = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(12));
	player1.puntos = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(13));

	player2.label = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(2));
	player2.bajas = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(21));
	player2.muertes = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(22));
	player2.puntos = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(23));

	player3.label = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(3));
	player3.bajas = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(31));
	player3.muertes = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(32));
	player3.puntos = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(33));

	player4.label = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(4));
	player4.bajas = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(41));
	player4.muertes = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(42));
	player4.puntos = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10)->getChild(0)->getChild(43));

	p = static_cast<Player*>(EntityManager::i().getEntity(PLAYER));
}
void InGameHUD::update() {
	//p = static_cast<Player*>(EntityManager::i().getEntity(PLAYER));
	updateLabelVida();
	updateLabelArma();
	updateLabelMunicion();
	updateLabelMunicionTotal();

	updateRelojes();

}

void InGameHUD::handleEvent(Event * ev)
{
}


void InGameHUD::updateRelojes() {
	hitMarker->setVisible(p->hit);
	sangre->setVisible(p->sangre);
}
void InGameHUD::muestraFinPartida() {
	LabelEndGame->setVisible(true);
	setTablaVisible(true);

}
void InGameHUD::updateLabelVida() {
	std::ostringstream oss;
	oss << p->getLifeComponent().getVida();
	CEGUI::String str(oss.str());
	LabelVida->setText(str);
}

 void InGameHUD::updateLabelArma() {
	CEGUI::String str;
	std::string string = p->getCurrentWeaponName();
	str = string.c_str();
	LabelArma->setText(str);
}

 void InGameHUD::updateLabelMunicion() {
	std::ostringstream oss;
	oss << p->getAmmoActual() << "/" << p->getCargadorActual();
	LabelMunicion->setText(oss.str());
 }

 void InGameHUD::updateLabelMunicionTotal() {
	std::ostringstream oss;
	CEGUI::String str;
	int ammoTotal = p->getAmmoTotal();
	if (ammoTotal == -1) {
		LabelMunicionTotal->setText("RECARGANDO");
	}
	else {
		oss << p->getAmmoTotal();
		LabelMunicionTotal->setText(oss.str());
	}

 }

 void InGameHUD::setTablaVisible(bool visible) {
	windowTabla->setVisible(visible);
 }

 void InGameHUD::setPlayerKills(int player, int kills) {
	 std::ostringstream oss;
	 oss << kills;
	 switch (player) {
	 case 1:
		 player1.bajas->setText(oss.str());
		 
		 break;

	 case 2:
		 player2.bajas->setText(oss.str());
		 break;

	 case 3:
		 player3.bajas->setText(oss.str());
		 break;

	 case 4:
		 player4.bajas->setText(oss.str());
		 break;
	 }
 }

 void InGameHUD::setPlayerDeaths(int player, int deaths) {
	 std::ostringstream oss;
	 oss << deaths;
	 switch (player) {
	 case 1:
		 /*std::ostringstream oss;
		 oss << nombre;*/
		 player1.muertes->setText(oss.str());
		 break;

	 case 2:
		 player2.muertes->setText(oss.str());
		 break;

	 case 3:
		 player3.muertes->setText(oss.str());
		 break;

	 case 4:
		 player4.muertes->setText(oss.str());
		 break;
	 }
 }

 void InGameHUD::setPlayerPoints(int player, int points) {
	 std::ostringstream oss;
	 oss << points;
	 switch (player) {
	 case 1:
		 /*std::ostringstream oss;
		 oss << nombre;*/
		 player1.puntos->setText(oss.str());
		 break;

	 case 2:
		 player2.puntos->setText(oss.str());
		 break;

	 case 3:
		 player3.puntos->setText(oss.str());
		 break;

	 case 4:
		 player4.puntos->setText(oss.str());
		 break;
	 }
 }

 void InGameHUD::setPlayerName(int player, const std::string & nombre) {
	 switch (player) {
	 case 1:
		 /*std::ostringstream oss;
		 oss << nombre;*/
		 player1.label->setText(nombre.c_str());
		 break;

	 case 2:
		 player2.label->setText(nombre.c_str());
		 break;

	 case 3:
		 player3.label->setText(nombre.c_str());
		 break;

	 case 4:
		 player4.label->setText(nombre.c_str());
		 break;
	 }
 }
