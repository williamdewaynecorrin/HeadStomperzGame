//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "circlecollisioncomponent.h"

namespace HSZGame {

CircleCollisionComponent::CircleCollisionComponent(unsigned int owningactorid, float radius) :
	CircleCollisionComponent(owningactorid, "default", radius)
{

}
CircleCollisionComponent::CircleCollisionComponent(unsigned int owningactorid, char* componentname, float radius) :
	CollisionComponent(owningactorid, componentname)
{
	this->radius = radius;
}

}