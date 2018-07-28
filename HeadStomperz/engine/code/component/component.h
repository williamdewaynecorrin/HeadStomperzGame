//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once

namespace HSZGame {

class Component
{
public:
	Component(unsigned int owningactorid);
	Component(unsigned int owningactorid, char* componentname);
	~Component();
	virtual bool Initialize();
	bool enabled;
	char *name;
	unsigned int ownerid;
	unsigned int componentid;
};

}