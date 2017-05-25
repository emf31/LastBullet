#pragma once

#include <iostream>
#include <State.h>
#include <LoadingStateGUI.h>
#include <ParalellTask.h>


struct AnimationStruct {
	std::string path;
	int numAnimations;
};



class LoadingState : public State {
public:
	LoadingState();
	virtual ~LoadingState();

	virtual void Inicializar();
	virtual void Clear();

	virtual void HandleEvent() override;
	virtual void Update(Time timeElapsed) override;
	virtual void Render(float interpolation, Time elapsedTime) override;

private:

	void readAllAssets();
	void NotificarServerCargaCompletada();

	float interpolation;
	LoadingStateGUI loadingStateGUI;
	ParalellTask* task;
	std::queue<std::string> colaAssets;
	AnimationStruct animation;
	Clock pruebas;
	bool needRender;

};