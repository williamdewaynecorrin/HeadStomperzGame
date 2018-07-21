//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "game.h"
using namespace HSZGame;

// =================================================================================================
// -- main entry point for the engine. creates game and runs it, kicking off all that is needed.
// =================================================================================================
int main(int argc, char **argv)
{
	Game game = Game();
	game.Run(_1600x900);
	return 0;
}