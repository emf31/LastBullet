#include "InputHandler.h"
#include "../Command/MoveDown.h"
#include "../Command/MoveUp.h"
#include "../Command/MoveRight.h"
#include "../Command/MoveLeft.h"
#include "../Command/ListWeaponUp.h"
#include "../Command/ListWeaponDown.h"
#include "../Command/Jump.h"
#include "../Command/ShootAsalto.h"
#include "../Command/ShootRocket.h"
#include "../Command/ShootPistola.h"
#include "../Command/Reload.h"
#include "../Command/Apuntar.h"




InputHandler::InputHandler()
{

	// Creamos punteros para todos los commands
	move_up = CommandPtr(new MoveUp());
	move_down = CommandPtr(new MoveDown());
	move_left = CommandPtr(new MoveLeft());
	move_right = CommandPtr(new MoveRight());
	list_up = CommandPtr(new ListWeaponUp());
	list_down = CommandPtr(new ListWeaponDown());
	jump = CommandPtr(new Jump());
	shoot_asalto = CommandPtr(new ShootAsalto());
	shoot_rocket = CommandPtr(new ShootRocket());
	shoot_pistola = CommandPtr(new ShootPistola());
	reload = CommandPtr(new Reload());
	apuntar = CommandPtr(new Apuntar());

	// Player
	commands[GLFW_KEY_W] = move_up;
	commands[GLFW_KEY_A] = move_left;
	commands[GLFW_KEY_S] = move_down;
	commands[GLFW_KEY_D] = move_right;
	commands[GLFW_KEY_R] = reload;
	/*commands[GLFW_KEY_UNKNOWN] = list_up;
	commands[GLFW_KEY_UNKNOWN] = list_down;*/
	commands[GLFW_KEY_SPACE] = jump;
	commands[GLFW_MOUSE_BUTTON_1] = shoot_pistola;
	commands[GLFW_MOUSE_BUTTON_2] = apuntar;

	
}

void InputHandler::bind(int key, CommandPtr command)
{
	commands[key] = command;    // guardamos las teclas asignadas
}

void InputHandler::handleInput()
{
	generate_input_commands(command_queue);
}

void InputHandler::excuteCommands(Player* p)
{
	while (!command_queue.empty()) {
		command_queue.back()->execute(p);
		command_queue.pop_back();
	}

	float scroll = Input::i().getMouseScroll();

	if (scroll == 1.f) {
		list_up->execute(p);
	}
	else if(scroll == -1.f){
		list_down->execute(p);
	}

	Input::i().resetMouseScroll();
}

bool InputHandler::generate_input_commands(std::vector<CommandPtr> &command_queue)
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
	std::map<int, CommandPtr>::iterator iter;
	for (iter = commands.begin(); iter != commands.end(); iter++) {
		if (Input::i().keyDown(iter->first)) {
			keydown(iter->first);
		}
		else if (Input::i().keyUp(iter->first)) {
			keyup(iter->first);
		}
	}

	return false;

}

void InputHandler::fill_command_queue(std::vector<CommandPtr> &command_queue)
{
	std::map<int, CommandPtr>::iterator iter;
	for (iter = commands.begin(); iter != commands.end(); iter++) {
		if (is_held(iter->first) && iter->second->get_input_type() == STATE)
			command_queue.push_back(iter->second);
		else if (was_pressed(iter->first) && iter->second->get_input_type() == ACTION)
			command_queue.push_back(iter->second);
	}
}

void InputHandler::keydown(int keyCode)
{
	if (state_map[keyCode] == RELEASED)
		action_map[keyCode] = EXECUTE;
	state_map[keyCode] = PRESSED;
}

void InputHandler::keyup(int keyCode)
{
	state_map[keyCode] = RELEASED;
}

bool InputHandler::is_held(int key)
{
	if(state_map[key])
		return true;
	return false;
}

bool InputHandler::was_pressed(int key)
{
	if(action_map[key])
		return true;
	return false;
}

void InputHandler::borrarContenido()
{

}