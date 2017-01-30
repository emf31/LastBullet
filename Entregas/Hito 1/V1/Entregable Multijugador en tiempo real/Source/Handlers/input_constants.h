#pragma once
enum InputType
{
	ACTION,
	STATE,
	RANGE
};

enum Action
{
	EXECUTE = true,
	STOP = false
};

enum State
{
	PRESSED = true,
	RELEASED = false
};