//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "component\component.h"
#include <vector>

using namespace std;

namespace HSZGame {

class Actor
{
public:
	Actor();
	Actor(char* name);
	~Actor();
	void AddComponent(unsigned int componentid);
	unsigned int actorid;
	char* actorname;
	/*template<typename ComponentType>*/
	/*ComponentType GetComponentByID(unsigned int componentid);*/
	const std::vector<unsigned int> GetComponents();
private:
	std::vector<unsigned int> components;
};

//template<typename ComponentType>
//ComponentType Actor::GetComponentByID(unsigned int componentid)
//{
//	return Game::GetCurrentLevel()->GetActorComponentByComponentId(this, componentid);
//}

}