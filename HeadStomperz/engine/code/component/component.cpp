//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "component.h"

// -- forward declaration
#include "game\game.h"

namespace HSZGame {

bool Component::Initialize(unsigned int owningactorid)
{
	return Initialize(owningactorid, "default");
}

bool Component::Initialize(unsigned int owningactorid, char* componentname)
{
	enabled = true;
	name = componentname;
	ownerid = owningactorid;
	componentid = Game::GenerateComponentGUID();
	return true;
}

}