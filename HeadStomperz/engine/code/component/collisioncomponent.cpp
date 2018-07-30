//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "collisioncomponent.h"

namespace HSZGame {

CollisionComponent::CollisionComponent(unsigned int owningactorid) :
	CollisionComponent(owningactorid, "default")
{

}
CollisionComponent::CollisionComponent(unsigned int owningactorid, char* componentname) :
	Component(owningactorid, componentname)
{

}

}