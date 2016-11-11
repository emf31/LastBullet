#include "InputHandler.h"
#include "../Command/MoveDown.h"
#include "../Command/MoveUp.h"
#include "../Command/MoveRight.h"
#include "../Command/MoveLeft.h"
#include "../Command/Jump.h"
#include "../Command/ShootCommand.h"
#include "../Command/ShootCommandGranada.h"
#include "../Command/RunCommand.h"
#include "../MastEventReceiver.hpp"
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;



InputHandler::InputHandler()
{

	// Creamos punteros para todos los commands
	move_up = new MoveUp();
	move_down = new MoveDown();
	move_left = new MoveLeft();
	move_right = new MoveRight();
	jump = new Jump();
	shoot_command = new ShootCommand();
	shoot_commandGranada = new ShootCommandGranada();
	run_command = new RunCommand();
	// Player
	
	commands[KEY_KEY_W] = move_up;
	commands[KEY_KEY_A] = move_left;
	commands[KEY_KEY_S] = move_down;
	commands[KEY_KEY_D] = move_right;
	commands[KEY_SPACE] = jump;
	commands[KEY_LBUTTON] = shoot_command;
	commands[KEY_RBUTTON] = shoot_commandGranada;
	commands[KEY_LSHIFT] = run_command;
	
	
}

void InputHandler::bind(EKEY_CODE key, Command *command)
{
	commands[key] = command;    // guardamos las teclas asignadas
}

void InputHandler::handleInput()
{
	InputHandler::i().generate_input_commands(command_queue);
}

void InputHandler::excuteCommands(Player* p)
{
	while (!command_queue.empty()) {
		command_queue.back()->execute(p);
		command_queue.pop_back();
	}
}

bool InputHandler::generate_input_commands(std::vector<Command*> &command_queue)
{
	bool exit = input_mapping();

	if (exit) return true;
	else {
		fill_command_queue(command_queue);
		action_map.clear();
		return false;
	}
}

bool InputHandler::input_mapping()
{
	std::map<EKEY_CODE, Command*>::iterator iter;
	for (iter = commands.begin(); iter != commands.end(); iter++) {
		if (MastEventReceiver::i().keyDown(iter->first)) {
			keydown(iter->first);
		}
		else if (MastEventReceiver::i().keyUp(iter->first)) {
			keyup(iter->first);
		}
	}

	return false;


	/*SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
<<<<<<< HEAD
	if (event.type == SDL_QUIT) {
	return true;
	} else if (event.type == SDL_KEYDOWN) {
	if (event.key.keysym.sym == SDLK_ESCAPE) {
	return true;
	}
	keydown(event);
	}
	else if (event.type == SDL_KEYUP) {
	keyup(event);
	}

	}

=======
		if (event.type == SDL_QUIT) {
			return true;
		} else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				return true;
			}
			keydown(event);
		}
		else if (event.type == SDL_KEYUP) {
			keyup(event);
		}
			
	}
		
>>>>>>> refs/remotes/origin/Irrlitch+Bullet

	return false;*/
}

void InputHandler::fill_command_queue(std::vector<Command*> &command_queue)
{
	std::map<EKEY_CODE, Command*>::iterator iter;
	for (iter = commands.begin(); iter != commands.end(); iter++) {
		if (is_held(iter->first) && iter->second->get_input_type() == STATE)
			command_queue.push_back(iter->second);
		else if (was_pressed(iter->first) && iter->second->get_input_type() == ACTION)
			command_queue.push_back(iter->second);
	}
}

void InputHandler::keydown(EKEY_CODE keyCode)
{
	if (state_map[keyCode] == RELEASED)
		action_map[keyCode] = EXECUTE;
	state_map[keyCode] = PRESSED;
}

void InputHandler::keyup(EKEY_CODE keyCode)
{
	state_map[keyCode] = RELEASED;
}

bool InputHandler::is_held(EKEY_CODE key)
{
	return state_map[key];
}

bool InputHandler::was_pressed(EKEY_CODE key)
{
	return action_map[key];
}

void InputHandler::borrarContenido()
{
	// Delete all command pointers    
	std::map<EKEY_CODE, Command*>::iterator iter;
	for (iter = commands.begin(); iter != commands.end(); iter++)
		delete iter->second;
}