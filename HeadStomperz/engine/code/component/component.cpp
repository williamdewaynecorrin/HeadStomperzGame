//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "component.h"

// -- forward declaration
#include "game\game.h"

namespace HSZGame {

Component::Component(unsigned int owningactorid) :
	Component(owningactorid, "default")
{

}

Component::Component(unsigned int owningactorid, char* componentname)
{
	enabled = true;
	name = componentname;
	ownerid = owningactorid;
	componentid = Game::GenerateComponentGUID();

	printf("Component init.");
}

Component::~Component()
{

}

bool Component::Initialize()
{
	return true;
}

}