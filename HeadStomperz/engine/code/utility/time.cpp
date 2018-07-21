//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "time.h"

namespace HSZGame {

// =================================================================================================
// CONSTRUCT / DESTRUCT
// =================================================================================================
Time::Time()
{
	// -- setup floating point values and frames
	totaltime = 0;
	deltatime = 0;
	timestep = 0.0166666666f;
	frames = 0;

	// -- setup system time stuff
	systemtimeatinitialize = time(0);
	systemtime = time(0);
	systemtimems = systemtime * 1000;
	systemtimemspreviousms = systemtimems;
}

Time::~Time()
{
}

// =================================================================================================
// FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- one tick of the time class. calculates deltatime, totaltime, system time and so on
// =================================================================================================
void Time::Tick()
{
	// -- one tick of a frame
	this->systemtime = time(0);
	this->systemtimems = systemtime * 1000;
	this->totaltime += this->timestep;
	this->frames++;
	this->deltatime = systemtimems - systemtimemspreviousms;
	this->systemtimemspreviousms = this->systemtimems;
}

}