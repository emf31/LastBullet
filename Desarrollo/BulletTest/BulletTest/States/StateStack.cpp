#include "StateStack.h"
#include <StateFactory.h>


StateStack::StateStack() {
	
	currentState = States::ID::Menu;
	
	CreateStates();
	//Solo inicializamos el estado menu
}

StateStack::~StateStack() {
	for(std::unordered_map<States::ID, State*>::iterator iterator = mapStates.begin(); iterator != mapStates.end(); iterator++) {
		delete iterator->second;
	}
}

void StateStack::CreateStates() {
	mapStates.insert(std::make_pair(States::ID::Menu , StateFactory::CreateState(States::ID::Menu)));
	mapStates.insert(std::make_pair(States::ID::InGame , StateFactory::CreateState(States::ID::InGame)));
	mapStates.insert(std::make_pair(States::ID::Carga, StateFactory::CreateState(States::ID::Carga)));
}

State* StateStack::GetCurrentState() const {
	auto found = mapStates.find(currentState);
	if (found != mapStates.end())
		return found->second;
	//no existe devolvemos 0

	return NULL;
}

State* StateStack::GetState(States::ID id) const {
	auto found = mapStates.find(id);
	if (found != mapStates.end())
		return found->second;
	//no existe devolvemos 0

	return NULL;
}

void StateStack::SetCurrentState(States::ID id) {
	if(id != currentState)
	{
		States::ID aux = currentState;

		currentState = id;

		if(id == States::ID::InGame){
			
		}
		
	}
}
