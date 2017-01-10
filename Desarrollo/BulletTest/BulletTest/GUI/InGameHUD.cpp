#include "InGameHUD.h"


InGameHUD::InGameHUD() {	
}

void InGameHUD::inicializar() {
	init("GUI", GraphicEngine::i().getDevice());
	loadScheme("AlfiskoSkin.scheme");
	loadScheme("Generic.scheme");
	loadLayout("LastBulletHUD.layout");

	LabelVida = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));
	LabelArma = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	LabelMunicion = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
	LabelMunicionTotal = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(4));

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
}
void InGameHUD::updateLabelVida() {
	std::ostringstream oss;
	oss << p->getLifeComponent()->getVida();
	CEGUI::String str(oss.str());
	LabelVida->setText(str);
}

 void InGameHUD::updateLabelArma() {
	CEGUI::String str;
	std::string string = p->getCurrentWeapon();
	str = string.c_str();
	LabelArma->setText(str);
}

 void InGameHUD::updateLabelMunicion() {
	std::ostringstream oss;
	CEGUI::String str;
	oss << p->getAmmoActual() << "/" << p->getCargadorActual();
	LabelMunicion->setText(oss.str());
 }

 void InGameHUD::updateLabelMunicionTotal() {
	std::ostringstream oss;
	CEGUI::String str;
	oss << p->getAmmoTotal();
	LabelMunicionTotal->setText(oss.str());
 }
