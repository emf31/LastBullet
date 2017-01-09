#include "InGameHUD.h"


InGameHUD::InGameHUD() {	
}

void InGameHUD::inicializar() {
	init("GUI", GraphicEngine::i().getDevice());
	loadScheme("AlfiskoSkin.scheme");
	loadLayout("LastBulletHUD.layout");

	LabelVida = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));
	LabelArma = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	LabelMunicion = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
	LabelMunicionTotal = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(4));

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
