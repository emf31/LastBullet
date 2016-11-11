
#pragma once

#include <map>
#include <vector>

#include "input_constants.h"
#include "../Entities/Player.h"
#include "../Command/Command.h"

class InputHandler
{
public:
	static InputHandler& i() {
		static InputHandler singleton;
		return singleton;
	}

	void handleInput();
	void excuteCommands(Player* p);
	void borrarContenido();

	bool generate_input_commands(std::vector<Command*> &command_queue);
	void bind(EKEY_CODE key, Command *command);

private:
	// Punteros a todos los comandos
	Command *move_up;
	Command *move_down;
	Command *move_left;
	Command *move_right;
	Command *jump;
	Command *shoot_command;
	Command *shoot_commandGranada;
	Command *run_command;

	std::map <EKEY_CODE, Command*> commands;


	std::map <EKEY_CODE, State> state_map;
	std::map <EKEY_CODE, Action> action_map;

	bool input_mapping();
	void fill_command_queue(std::vector<Command*> &command_queue);

	void keydown(EKEY_CODE keyCode);
	void keyup(EKEY_CODE keyCode);

	bool is_held(EKEY_CODE key);
	bool was_pressed(EKEY_CODE key);

	std::vector<Command*> command_queue;

	InputHandler();

};

