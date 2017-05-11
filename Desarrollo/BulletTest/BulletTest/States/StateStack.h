#pragma once

#include <State.h>
#include <unordered_map>

class StateStack {
public:
	static StateStack& i() {
		static StateStack singleton;
		return singleton;
	}

	
	void   CreateStates();
	State* GetState(States::ID id) const;
	State* GetCurrentState() const;
	void   SetCurrentState(States::ID id);

	States::ID GetCurrentStateID() { return currentState; }
	
	
	States::ID currentState;
	
	
	
private:
	StateStack();
	~StateStack();
   
	std::unordered_map<States::ID, State*> mapStates;
};


