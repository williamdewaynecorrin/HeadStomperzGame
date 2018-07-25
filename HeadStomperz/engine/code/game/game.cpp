//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "game\game.h"

namespace HSZGame 
{
// =================================================================================================
// -- STATIC DECLARATIONS
// =================================================================================================
bool Game::gameover = false;
unsigned int Game::guidactor = 0;
unsigned int Game::guidcomponent = 0;
Game* Game::gameinstance = nullptr;

// =================================================================================================
// -- CONSTRUCTORS / DESTRUCTORS
// =================================================================================================
Game::Game()
{
	this->gameover = false;

	// -- create game instance
	if (gameinstance == nullptr)
	{
		gameinstance = this;
		printf("Static Game Instance singleton initialized.\n");
	}
	else printf("FATAL ERROR. Two Game Instances are running...are you constructring two Games?\n");
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
// -- STATIC FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- quits the application
// =================================================================================================
void Game::QuitApplication()
{
	gameover = true;
}

// =================================================================================================
// -- quits the application and prints given error message to console
// =================================================================================================
void Game::QuitApplicationWithError(char error[])
{
	gameover = true;
	printf(error);
}

// =================================================================================================
// -- returns a globally unique actor id by incrementing the value every time a guid is desired
// =================================================================================================
int Game::GenerateActorGUID()
{
	return guidactor++;
}

// =================================================================================================
// -- returns a globally unique component id by incrementing the value every time a guid is desired
// =================================================================================================
int Game::GenerateComponentGUID()
{
	return guidcomponent++;
}

void Game::ChangeLevel(char levelname[])
{

}

void Game::ChangeLevel(int levelindex)
{

}

Level* Game::GetCurrentLevel()
{
	return gameinstance->levels[gameinstance->currentlevelindex];
}

Camera2D* Game::GetDefaultCamera()
{
	return gameinstance->cameras[0];
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
		// -- update logic: tick the time, update component systems, update level, 
		// -- render, update display
		time->Tick();
		UpdateComponentSystems();
		UpdateDisplay();
		Render();
	} 
	while (!gameover);
}

// =================================================================================================
// -- renders all objects currently needed to be rendered in the game 
// =================================================================================================
void Game::Render()
{
	
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
// -- updates all the cameras in the camera list
// =================================================================================================
void Game::UpdateCameras()
{
	for (int i = 0; i < cameras.size(); ++i)
	{
		cameras[i]->Update(time->deltatime);
	}
}

// =================================================================================================
// -- updates the component sytems 
// =================================================================================================
void Game::UpdateComponentSystems()
{
	spritecs->UpdateComponents(time->deltatime);
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

	// -- init component systems
	spritecs = new SpriteComponentSystem();
	// -- init time object
	time = new Time();
	// -- init camera object
	cameras.push_back(new Camera2D());

	return true;
}
}