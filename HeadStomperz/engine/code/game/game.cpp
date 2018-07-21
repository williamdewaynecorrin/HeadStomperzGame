//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================


#include "game.h"

namespace HSZGame 
{
// =================================================================================================
// -- CONSTRUCTORS / DESTRUCTORS
// =================================================================================================
Game::Game()
{
	this->gameover = false;
}

Game::~Game()
{

}

// =================================================================================================
// -- PUBLIC FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- runs the game by initializing resources and kicking off the game update loop
// =================================================================================================
int Game::Run(RESOLUTION res)
{
	this->Initialize(res);
	this->Update();

	return 0;
}

// =================================================================================================
// -- PRIVATE INTERNAL FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- updates all aspects of the game that need to be currently updated
// =================================================================================================
void Game::Update()
{
	do
	{
		UpdateDisplay();
	} while (!gameover);
}

// =================================================================================================
// -- updates the game display, swapping screen buffers
// =================================================================================================
void Game::UpdateDisplay()
{
	//poll events and swap buffers
	glfwPollEvents();
	glfwSwapBuffers(window->GetGLFWwindow());

	////increase time
	//time += timeStep;

	////deal with modTime (time that is always from 0->1)
	//timeMod += timeStep;
	//if (timeMod >= 1.0f)
	//	timeMod -= 1.0f;

	////increase frame
	//frame++;

	////update input
	//input->UpdateLast();

	//gameover
	gameover = glfwGetKey(window->GetGLFWwindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS ||
		glfwWindowShouldClose(window->GetGLFWwindow()) != 0;
}

// =================================================================================================
// -- initializes the Game and all of its functionality
// =================================================================================================
bool Game::Initialize(RESOLUTION res)
{
	//decipher resolution from RESOLUTION enum
	int w, h = 0;
	switch (res)
	{
	case _1600x900:
		w = 1600;
		h = 900;
		break;
	case _1080x720:
		w = 1080;
		h = 720;
		break;
	case _800x600:
		w = 800;
		h = 600;
		break;
	}

	//create GameWindow using resolution
	this->window = new GameWindow(w, h);

	if (this->window == nullptr) {
		printf("Could not Initialize GameWindow.");
		return false;
	}

	return true;
}
}