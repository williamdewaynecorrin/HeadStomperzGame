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
	this->currentlevelname = LEVEL_NONE;

	// -- create game instance
	if (gameinstance == nullptr)
	{
		gameinstance = this;
		printf("Static Game Instance singleton initialized.\n");
	}
	else printf("FATAL ERROR. Two Game Instances are running...are you constructring two Games?\n");

	// - init lists / maps
	levels = std::map<const char*, Level*>();
	cameras = std::vector<Camera2D*>();

	// -- construct component systems
	spritecs = new SpriteComponentSystem();
	transformcs = new TransformComponentSystem();
	collisioncs = new CollisionComponentSystem();
	// -- construct time object
	time = new Time();
	// -- construct camera object
	cameras.push_back(new Camera2D());
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
	ChangeLevel(*gameinstance->levels[levelname], levelname);
}

void Game::ChangeLevel(Level& to, char levelname[])
{
	//todo: unload current level, if exists
	if (gameinstance->currentlevelname != LEVEL_NONE)
	{
		gameinstance->transformcs->ClearFromCurrentLevel();
		gameinstance->collisioncs->ClearFromCurrentLevel();
		gameinstance->spritecs->ClearFromCurrentLevel();
	}

	// -- now we can change currentlevelname and load new level
	gameinstance->currentlevelname = levelname;
	// -- populate all component systems
	gameinstance->transformcs->PopulateFromCurrentLevel(GetCurrentLevel());
	gameinstance->collisioncs->PopulateFromCurrentLevel(GetCurrentLevel());
	gameinstance->spritecs->PopulateFromCurrentLevel(GetCurrentLevel());
	// -- init all cs
	gameinstance->transformcs->Initialize();
	gameinstance->collisioncs->Initialize();
	gameinstance->spritecs->Initialize();
}

Level* Game::GetCurrentLevel()
{
	return gameinstance->levels[gameinstance->currentlevelname];
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
		SetupForRender();
		UpdateCameras();
		UpdateComponentSystems();
		UpdateDisplay();

		// -- debug stuff
		GLenum error = glGetError();
		if (error != GLEW_OK)
			std::cout << glewGetErrorString(error) << std::endl;
	} 
	while (!gameover);
}

// =================================================================================================
// -- renders all objects currently needed to be rendered in the game 
// =================================================================================================
void Game::SetupForRender()
{
	// -- opengl stuff that we need to do
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_TEXTURE_2D);
	//// -- set camera projection
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//GetDefaultCamera()->GluOrthoSetup();
	//// -- set camera position
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//GetDefaultCamera()->GluTranslateSetup();
}
// =================================================================================================
// -- updates the game display, swapping screen buffers
// =================================================================================================
void Game::UpdateDisplay()
{
	//poll events and swap buffers
	glfwPollEvents();
	glfwSwapBuffers(window->GetGLFWwindow());

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
	transformcs->UpdateComponents(time->deltatime);
	collisioncs->UpdateComponents(time->deltatime);
	spritecs->UpdateComponents(time->deltatime);
}

void Game::LoadContent()
{
	ContentBase::LoadTexture2D("collectable_01", "content//textures//test_sprite_01.png", true);
	ContentBase::LoadTexture2D("planet_01", "content//textures//planet_01.png", true);
	ContentBase::LoadTexture2D("creature_01_idle", "content//textures//creature_01_idle01.png", true);
	ContentBase::LoadShader("sprite_default", "content//shaders//sprite.vert",
		"content//shaders//sprite.frag");
}

void Game::LoadLevels()
{
	// -- load level
	Level* test = new Level("test_level");
	AddLevel(test);

	// -- create planet actor
	unsigned int planetactorid = test->AddActor("planet_actor");

	// -- add actor components
	TransformComponent* planetT = new TransformComponent(planetactorid);
	planetT->position = vec2(-300.0f, 370.0f);
	planetT->scale = vec2(4.0f);
	test->RegisterComponent(planetT);
	SpriteComponent* planetsprite = new SpriteComponent(planetactorid);
	planetsprite->SetImage(ContentBase::GetTexture2D("planet_01"));
	test->RegisterComponent(planetsprite);
	CircleCollisionComponent* planetcircle = new CircleCollisionComponent(planetactorid, 510.0f);
	test->RegisterComponent(planetcircle);

	// -- create planet actor2
	unsigned int planetactorid2 = test->AddActor("planet_actor2");

	// -- add actor components
	TransformComponent* planetT2 = new TransformComponent(planetactorid2);
	planetT2->position = vec2(600.0f, 370.0f);
	planetT2->scale = vec2(4.0f);
	test->RegisterComponent(planetT2);
	SpriteComponent* planetsprite2 = new SpriteComponent(planetactorid2);
	planetsprite2->SetImage(ContentBase::GetTexture2D("planet_01"));
	test->RegisterComponent(planetsprite2);
	CircleCollisionComponent* planetcircle2 = new CircleCollisionComponent(planetactorid2, 510.0f);
	test->RegisterComponent(planetcircle2);

	// -- create char actor
	unsigned int characteractorid = test->AddActor("character_actor");
	// -- add actor components
	TransformComponent* characterT = new TransformComponent(characteractorid);
	characterT->position = vec2(-300.0f, -50.0f);
	test->RegisterComponent(characterT);
	SpriteComponent* charactersprite = new SpriteComponent(characteractorid);
	charactersprite->SetImage(ContentBase::GetTexture2D("creature_01_idle"));
	test->RegisterComponent(charactersprite);

	// -- change current level to test level
	ChangeLevel(test->GetName());
}

void Game::AddLevel(Level* l)
{
	levels[l->GetName()] = l;
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

	// -- load content first before initializing, in case inits use content
	LoadContent();
	LoadLevels();

	return true;
}
}