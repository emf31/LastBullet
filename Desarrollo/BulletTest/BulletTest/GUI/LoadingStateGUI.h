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

	void setTotalAssets(int total);

	void setAssetName(std::string& name);

private:

	//std::thread t;
	CEGUI::DefaultWindow* Label;
	CEGUI::ProgressBar* ProgressBar;

	std::string Assetname;
	int assetActual;
	int totalAssets;
};

#pragma once
