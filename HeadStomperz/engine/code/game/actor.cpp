//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "actor.h"

// -- forward declaration (see header)
#include "game\game.h"

namespace HSZGame {

Actor::Actor() :
	Actor("newactor")
{

}

Actor::Actor(char* name)
{
	actorid = Game::GenerateActorGUID();
	components = vector<unsigned int>();
	actorname = name;
}

Actor::~Actor()
{

}

const std::vector<unsigned int> Actor::GetComponents()
{
	return components;
}

void Actor::AddComponent(unsigned int componentid)
{
	if (std::find(components.begin(), components.end(), componentid) != components.end()) {
		printf("[ERROR]: This actor already contains given component. You are trying to duplicate.");
		return;
	}

	components.push_back(componentid);
}

}