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

#pragma once

#include <iostream>
#include <Time.hpp>
#include <State.h>
#include <InGameHUD.h>
#include <DebugMenuGUI.h>
#include <SalirHUD.h>
#include <fstream>




class InGame : public State {
public:
	InGame();
	virtual ~InGame();

	virtual void Inicializar();
	virtual void Clear();

	virtual void HandleEvent() override;
	virtual void Update(Time timeElapsed) override;
	virtual void Render(float interpolation, Time elapsedTime) override;

	bool wantToExit;

private:
	InGameHUD ingameGUI;
	DebugMenuGUI debugMenu;
	SalirHUD salirGUI;
	float interpolation;

	Player* m_player;
	Enemy* ene;
};

