#include "InGameHUD.h"


InGameHUD::InGameHUD() : GUI() {	
}

void InGameHUD::inicializar() {
	init("../GUI", "InGameHUD");
	loadScheme("AlfiskoSkin.scheme");
	loadScheme("Generic.scheme");
	loadScheme("LastBulletHUD.scheme");
	loadScheme("sniper.scheme");
	loadLayout("LastBulletHUD.layout");
	


	LabelVida = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));
	//LabelArma = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	LabelMunicion = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
	LabelMunicionTotal = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(4));
	m_ranking = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(81));
	m_kills = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(82));
	m_deaths = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(83));
	ProgressBarVida = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(78));
	ProgressBarMunicion = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(79));

	ImagenPistola = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(61));
	ImagenPistola->setVisible(true);
	ImagenAsalto = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(62));
	ImagenAsalto->setVisible(false);
	ImagenRocket = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(63));
	ImagenRocket->setVisible(false);
	ImagenSniper = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(64));
	ImagenSniper->setVisible(false);

	LabelEndGame = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(54));

	windowTabla = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10));

	hitMarker = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(51));
	sangre = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(52));
	scope = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(77));

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
	updateProgressBarVida();
	updateProgressBarMunicion();


	updateRelojes();

	updateApuntando();

}

void InGameHUD::handleEvent(Event * ev)
{
}


void InGameHUD::updateRelojes() {
	hitMarker->setVisible(p->hit);
	sangre->setVisible(p->sangre);
}
void InGameHUD::updateApuntando() {
	scope->setVisible(p->getApuntando());
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
	/*CEGUI::String str;
	std::string string = p->getCurrentWeaponName();
	str = string.c_str();*/
	 if (p->getCurrentWeaponName() == "Pistola"){
		 ImagenPistola->setVisible(true);
		 ImagenAsalto->setVisible(false);
		 ImagenRocket->setVisible(false);
		 ImagenSniper->setVisible(false);
	 }
	 if (p->getCurrentWeaponName() == "Asalto") {
		 ImagenPistola->setVisible(false);
		 ImagenAsalto->setVisible(true);
		 ImagenRocket->setVisible(false);
		 ImagenSniper->setVisible(false);
	 }
	 if (p->getCurrentWeaponName() == "RocketLauncher") {
		 ImagenPistola->setVisible(false);
		 ImagenAsalto->setVisible(false);
		 ImagenRocket->setVisible(true);
		 ImagenSniper->setVisible(false);
	 }
	 if (p->getCurrentWeaponName() == "Sniper") {
		 ImagenPistola->setVisible(false);
		 ImagenAsalto->setVisible(false);
		 ImagenRocket->setVisible(false);
		 ImagenSniper->setVisible(true);
	 }
		 
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
 
 void InGameHUD::setRanking(int rank)
 {
	 std::ostringstream oss;
	 oss << rank;
	 m_ranking->setText(oss.str());
 }

 void InGameHUD::setKills(int kills)
 {
	 std::ostringstream oss;
	 oss << kills;
	 m_kills->setText(oss.str());
 }

 void InGameHUD::setDeaths(int death)
 {
	 std::ostringstream oss;
	 oss << death;
	 m_deaths->setText(oss.str());
 }

 void InGameHUD::updateProgressBarVida()
 {
	 ProgressBarVida->setProgress(p->getVida() / 100);
 }

 void InGameHUD::updateProgressBarMunicion()
 {
	 ProgressBarMunicion->setProgress((float)p->getAmmoActual() / (float)p->getCargadorActual());
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
