#pragma once


#include <GraphicEngine.h>
#include <GUI.h>
#include <events\Event.h>



class LoadingStateGUI : public Motor::GUI {
public:

	LoadingStateGUI();

	void inicializar();

	virtual void update() override;

	virtual void handleEvent(Event * ev) override;

private:

	//std::thread t;



};

#pragma once
