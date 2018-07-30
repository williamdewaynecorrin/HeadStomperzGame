//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "component\collisioncomponent.h"

namespace HSZGame {

class CircleCollisionComponent : public CollisionComponent
{
public:
	CircleCollisionComponent(unsigned int owningactorid, float radius);
	CircleCollisionComponent(unsigned int owningactorid, char* componentname, float radius);
	float radius;
};

}