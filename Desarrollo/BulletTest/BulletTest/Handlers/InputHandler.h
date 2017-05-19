
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
	void bind(int key, CommandPtr command);

	

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
	CommandPtr run_command;
	CommandPtr list_up;
	CommandPtr list_down;
	CommandPtr reload;
	CommandPtr apuntar;

	std::map <int, CommandPtr> commands;


	std::map <int, State> state_map;
	std::map <int, Action> action_map;

	bool input_mapping();
	void fill_command_queue(std::vector<CommandPtr> &command_queue);

	void keydown(int keyCode);
	void keyup(int keyCode);

	bool is_held(int key);
	bool was_pressed(int key);

	std::vector<CommandPtr> command_queue;

	InputHandler();

};

