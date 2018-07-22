//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include <vector>
#include "game\actor.h"

namespace HSZGame {

class Level
{
public:
	Level();
	~Level();
private:
	std::vector<Actor*> actors;
};

}