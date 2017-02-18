
#include "StateFactory.h"
#include <InGame.h>
#include <Menu.h>

State* StateFactory::CreateState(States::ID id){
    
    if(id == States::ID::InGame){
		return new InGame();
	}
	else if (id == States::ID::Menu) {
		return new Menu();
	}
	return NULL;
}