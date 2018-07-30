//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once

#include "component\component.h"
#include "glm\ext.hpp"

using namespace glm;

namespace HSZGame {

class CollisionComponent : public Component
{
public:
	CollisionComponent(unsigned int owningactorid);
	CollisionComponent(unsigned int owningactorid, char* componentname);
	vec2 center;
};

}