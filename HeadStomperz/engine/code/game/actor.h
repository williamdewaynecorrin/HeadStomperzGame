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
	~Actor();
	virtual void Update(float dt) = 0;
	unsigned int actorid;
private:
	std::vector<unsigned int> components;
};

}