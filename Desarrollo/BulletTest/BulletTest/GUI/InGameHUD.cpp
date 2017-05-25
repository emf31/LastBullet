#include "InGameHUD.h"
#include "CEGUI/Font.h"
#include <World.h>

InGameHUD::InGameHUD() : GUI(), count(10), activeCuentaAtras(){
}

void InGameHUD::inicializar() {
	init("../GUI", "InGameHUD");
	loadScheme("AlfiskoSkin.scheme");
	loadScheme("Generic.scheme");
	loadScheme("LastBulletHUD.scheme");
	loadScheme("sniper.scheme");
	loadLayout("LastBulletHUD.layout");

	// Create a custom font which we use to draw the list items. This custom
	// font won't get effected by the scaler and such.
	CEGUI::FontManager& fontManager(CEGUI::FontManager::getSingleton());
	CEGUI::Font& font(fontManager.createFromFile("DejaVuSans-12.font"));
	// Set it as the default
	m_context->setDefaultFont(&font);

	
	//Here we create a font and apply it to the renew font name button
	CEGUI::Font& labelFont = fontManager.createFreeTypeFont("DejaVuSans-20", 20.f, true, "DejaVuSans.ttf",
		CEGUI::Font::getDefaultResourceGroup(), CEGUI::ASM_Vertical, CEGUI::Sizef(1280.0f, 720.0f));


	AllHUD = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1));

	Feed = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
	Feed->setFont(&labelFont);

	m_WindowCuenta = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(6));

	m_LabelCuentaInfo = static_cast<CEGUI::DefaultWindow*>(m_WindowCuenta->getChild(7));
	m_LabelCuentaInfo->setFont(&labelFont);

	m_LabelCuenta = static_cast<CEGUI::DefaultWindow*>(m_WindowCuenta->getChild(5));
	m_LabelCuenta->setFont(&labelFont);

	
	

	LabelVida = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(1));
	//LabelArma = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
	LabelMunicion = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(3));
	LabelMunicionTotal = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(4));

	m_ranking = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(81));
	m_kills = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(82));
	m_deaths = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(83));

	ProgressBarVida = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(78));
	ProgressBarMunicion = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(79));

	ImagenPistola = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(61));
	ImagenPistola->setVisible(true);
	ImagenAsalto = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(62));
	ImagenAsalto->setVisible(false);
	ImagenRocket = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(63));
	ImagenRocket->setVisible(false);
	ImagenSniper = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(64));
	ImagenSniper->setVisible(false);

	LabelEndGame = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(54));
	LabelEndGame->setFont(&labelFont);

	windowTabla = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10));

	hitMarker = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(51));
	sangre = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(52));
	scope = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(77));

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
	
	if (activeCuentaAtras) {
		updateCuentaAtras();
	}
	if (feedTime.getElapsedTime().asSeconds() >= 2.f && Feed->getText()!="") {
		Feed->setVisible(false);
	}


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

void InGameHUD::newFeed(const std::string & killer,const std::string & death)
{
	
	if (killer != death) {
		if (killer == EntityManager::i().getEntity(PLAYER)->getName()) {
			Feed->setText("You killed " + death);
		}
		else {
			Feed->setText(killer+ " killed You ");
		}
		
	}
	else {
		Feed->setText("You killed yourself");
	}
	Feed->setVisible(true);
	feedTime.restart();
}


void InGameHUD::updateRelojes() {

	if (!World::i().getPartida()->isFinished()) {
		hitMarker->setVisible(p->hit);
		sangre->setVisible(p->sangre);
	}

}
void InGameHUD::updateApuntando() {
	if (!World::i().getPartida()->isFinished()) {
		scope->setVisible(p->getApuntando());
	}
}
void InGameHUD::muestraFinPartida(const std::string& name) {

	LabelEndGame->setVisible(true);
	World::i().getPartida()->setFinished(true);
	hitMarker->setVisible(false);
	scope->setVisible(false);
	SceneManager::i().zoomZout();
	EntityManager::i().stopInterpolateAllEntities();
	std::string finalText = "GAME FINISHED! \n";
	finalText.append(name);
	finalText.append(" won the game.");
	LabelEndGame->setText(finalText);
	//setTablaVisible(true);

}

bool InGameHUD::setVisibleAllHUD(bool visible)
{
	AllHUD->setVisible(visible);
	return true;
}

void InGameHUD::desactivarCuentaAtras() {
	activeCuentaAtras = false;

	m_WindowCuenta->setVisible(false);
}

void InGameHUD::empezarCuentaAtras() {
	countTime.restart();
	activeCuentaAtras = true;

	m_WindowCuenta->setVisible(true);
}

void InGameHUD::updateCuentaAtras() {
	if (countTime.getElapsedTime().asSeconds() > 1.f) {
		countTime.restart();
		count--;

		m_LabelCuenta->setText(std::to_string(count));

		if (count == 0) {
			activeCuentaAtras = false;
			desactivarCuentaAtras();
			World::i().getPartida()->setPlayerReady(true);
		}
	}
}

void InGameHUD::updateLabelVida() {
	std::ostringstream oss;
	oss << (int)p->getLifeComponent().getVida();
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
		LabelMunicionTotal->setText("REL.");
	}
	else {
		oss << p->getAmmoTotal();
		LabelMunicionTotal->setText(oss.str());
	}

 }

 void InGameHUD::setTablaVisible(bool visible) {
	windowTabla->setVisible(visible);
	if (World::i().getPartida()->isFinished()) {
		LabelEndGame->setVisible(!visible);
	}
	
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
