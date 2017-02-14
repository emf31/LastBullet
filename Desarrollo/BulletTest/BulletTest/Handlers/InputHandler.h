
#pragma once

#include <map>
#include <vector>
#include <memory>

#include "input_constants.h"
#include <Player.h>
#include "../Command/Command.h"

typedef std::shared_ptr<Command> CommandPtr;

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

	bool generate_input_commands(std::vector<CommandPtr> &command_queue);
	void bind(EKEY_CODE key, CommandPtr command);

	

private:
	// Punteros a todos los comandos
	CommandPtr move_up;
	CommandPtr move_down;
	CommandPtr move_left;
	CommandPtr move_right;
	CommandPtr jump;
	CommandPtr shoot_asalto;
	CommandPtr shoot_rocket;
	CommandPtr shoot_pistola;
	CommandPtr shoot_commandGranada;
	CommandPtr run_command;
	CommandPtr list_up;
	CommandPtr list_down;
	CommandPtr reload;
	CommandPtr apuntar;

	std::map <EKEY_CODE, CommandPtr> commands;


	std::map <EKEY_CODE, State> state_map;
	std::map <EKEY_CODE, Action> action_map;

	bool input_mapping();
	void fill_command_queue(std::vector<CommandPtr> &command_queue);

	void keydown(EKEY_CODE keyCode);
	void keyup(EKEY_CODE keyCode);

	bool is_held(EKEY_CODE key);
	bool was_pressed(EKEY_CODE key);

	std::vector<CommandPtr> command_queue;

	InputHandler();

};

