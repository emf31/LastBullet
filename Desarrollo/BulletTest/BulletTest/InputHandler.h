#pragma once
#include <map>
#include <vector>
#include <SDL.h>
#include "input_constants.h"
#include "Entities\Player.h"
class Command
{
public:
	virtual ~Command() {}
	virtual void execute(Player* character) = 0;
	virtual InputType get_input_type() = 0;
};

class InputHandler
{
private:
	// Pointers to all commands
	Command *move_up;
	Command *move_down;
	Command *move_left;
	Command *move_right;
	Command *jump;

	std::map <int, Command*> commands;

	// Gameplay context 
	std::map <int, State> state_map;
	std::map <int, Action> action_map;

	bool input_mapping();
	void dispatcher(std::vector<Command*> &command_queue);

	void keydown(SDL_Event &event);
	void keyup(SDL_Event &event);

	bool is_held(int key);
	bool was_pressed(int key);

public:
	InputHandler();
	~InputHandler();
	bool fill(std::vector<Command*> &command_queue);
	void configure(int key, Command *command);
};

class MoveUp : public Command
{
public:
	void execute(Character *character) { character->move_up(); }
	InputType get_input_type() { return STATE; }
};

class MoveLeft : public Command
{
public:
	void execute(Character *character) { character->move_left(); }
	InputType get_input_type() { return STATE; }
};

class MoveRight : public Command
{
public:
	void execute(Character *character) { character->move_right(); }
	InputType get_input_type() { return STATE; }
};

class MoveDown : public Command
{
public:
	void execute(Character *character) { character->move_down(); }
	InputType get_input_type() { return STATE; }
};

class Jump : public Command
{
public:
	void execute(Character *character) { character->jump(); }
	InputType get_input_type() { return ACTION; }
};
