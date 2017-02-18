#pragma once

#include <iostream>
#include <State.h>



class Menu : public State {
public:
	Menu();
	virtual ~Menu();

	virtual void Inicializar();
	virtual void Clear();

	virtual void HandleEvent() override;
	virtual void Update(Time timeElapsed) override;
	virtual void Render(float interpolation, Time elapsedTime) override;

private:

	float interpolation;


};

