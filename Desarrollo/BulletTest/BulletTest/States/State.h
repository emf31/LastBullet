#pragma once

#include <iostream>
#include <Time.hpp>


namespace States{
	enum ID{
			InGame,
			Menu,
			Carga,
			Pause,
	};
}

class State {
public:
	virtual void Inicializar() = 0;
	virtual void Clear() = 0;

	virtual void HandleEvent() = 0;
	virtual void Update(Time timeElapsed) = 0;
	virtual void Render(float interpolation, Time elapsedTime) = 0;
	
	
	

	States::ID id;
	

};


