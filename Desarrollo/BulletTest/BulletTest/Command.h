#pragma once
#include "Entities\Player.h"


class Command
{
public:
	Command();
	~Command();

	virtual void execute()=0;
};

