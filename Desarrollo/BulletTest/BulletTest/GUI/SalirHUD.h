#pragma once
#pragma once


#include <GUI.h>
#include <events\Event.h>



class SalirHUD : public Motor::GUI {
public:

	SalirHUD();

	void inicializar();

	virtual void update() override;

	virtual void handleEvent(Event * ev) override;

	bool onContinuarClicked();
	bool onSalirClicked();
	CEGUI::DefaultWindow *Window;

private:

	CEGUI::PushButton *Salir;
	CEGUI::PushButton *Continuar;
	

};