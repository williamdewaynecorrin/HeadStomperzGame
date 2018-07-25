//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include <ctime>

namespace HSZGame {
// =================================================================================================
// == TIME CLASS ============================================================================
// =================================================================================================
class Time
{
public:
	Time();
	~Time();
	void Tick();

	// -- custom time with a fixed timestep
	float totaltime;
	float timestep;
	float deltatime;
	// -- frames
	int frames;
private:
	// -- system time
	long double systemtimeatinitialize;
	long double systemtime;
	long double systemtimems;
	long double systemtimemspreviousms;
};

}
