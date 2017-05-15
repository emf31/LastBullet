#pragma once

#include <Time.hpp>
#include <StateStack.h>
class TimePerFrame;
class Game
{
public:
	Game();
	virtual ~Game();

	void run();

	static const int server_port;
	

private:
	void inicializar();
	void inicializarRutas();

	bool processEvents(); 
	void update(Time elapsedTime);
	void render(float interpolation, Time elapsedTime);

	void clear();
	
	float interpolation;

	StateStack& stateStack;
};