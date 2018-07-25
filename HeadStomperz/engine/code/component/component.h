//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once

namespace HSZGame {

class Component
{
public:
	virtual bool Initialize(unsigned int owningactorid);
	virtual bool Initialize(unsigned int owningactorid, char* componentname);
	bool enabled;
	char *name;
	unsigned int ownerid;
	unsigned int componentid;
};

}