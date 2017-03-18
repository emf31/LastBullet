
#include "StateFactory.h"
#include <InGame.h>
#include <Menu.h>
#include <LoadingState.h>

State* StateFactory::CreateState(States::ID id){
    
    if(id == States::ID::InGame){
		return new InGame();
	}
	else if (id == States::ID::Menu) {
		return new Menu();
	}
	else if (id == States::ID::Carga) {
		return new LoadingState();
	}

	return NULL;
}