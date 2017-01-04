/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   State.hpp
 * Author: joselu
 *
 * Created on 26 de marzo de 2016, 19:49
 */

#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <Time.hpp>
//#include <SFML/Graphics.hpp>
//#include "../Entities/Enemigo.hpp"
//#include <SFML/Window.hpp>

namespace States{
	enum ID{
			InGame,
			Menu,
			Carga,
			Transition,
			Pause,
			Muerte
	};
}

class State {
public:
   // virtual void HandleEvents(Event &event) = 0;
	virtual void Update(Time timeElapsed) = 0;
	virtual void Render(float interpolation, Time elapsedTime) = 0;

	virtual void Clear() = 0;
	virtual void Inicializar() = 0;

	States::ID id;
	
	int level=0;

};

#endif /* STATE_HPP */

