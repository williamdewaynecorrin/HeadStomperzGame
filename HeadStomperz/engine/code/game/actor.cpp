//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "actor.h"

// -- forward declaration (see header)
#include "game\game.h"

namespace HSZGame {

Actor::Actor()
{
	actorid = Game::GenerateActorGUID();
	components = vector<unsigned int>();
}

Actor::~Actor()
{

}

//void Actor::Update(float dt)
//{
//
//}

}