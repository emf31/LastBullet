#pragma once

#include "State.h"

class StateFactory {
public:
    static State* CreateState(States::ID id);
private:

};

