//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#define LEVEL_NONE "LEVEL_NULL"

#pragma once
#include "graphics\gamewindow.h"
#include "graphics\resolution.h"
#include "game\level.h" //also includes actor, vector
#include "componentsystem\spritecomponentsystem.h"
#include "componentsystem\transformcomponentsystem.h"
#include "camera\camera2D.h"
#include "utility\time.h"
#include "graphics\contentbase.h"
#include "glm\ext.hpp"
#include <map>

namespace HSZGame 
{
// =================================================================================================
// == GAME CLASS ===================================================================================
// =================================================================================================
class Game
{
public:
	// constructors ================================================================================
	Game();
	~Game();

	// external functions ==========================================================================
	int Run(RESOLUTION res);

	// static functions ============================================================================
	static void QuitApplication();
	static void QuitApplicationWithError(char error[]);
	static int GenerateActorGUID();
	static int GenerateComponentGUID();
	static void ChangeLevel(char levelname[]);
	static void ChangeLevel(Level& to, char levelname[]);
	static Level* GetCurrentLevel();
	static Camera2D* GetDefaultCamera();
private:
	// internal engine functions ===================================================================
	bool Initialize(RESOLUTION res);
	void LoadContent();
	void LoadLevels();
	void Update();
	void UpdateDisplay();
	void UpdateCameras();
	void UpdateComponentSystems();
	void Render();
	void AddLevel(Level* l);

	// variable members ============================================================================
	GameWindow* window;
	std::map<const char*, Level*> levels;
	SpriteComponentSystem* spritecs;
	TransformComponentSystem* transformcs;
	char* currentlevelname;
	std::vector<Camera2D*> cameras;
	Time* time;

	// static variable members =====================================================================
	static bool gameover;
	static unsigned int guidactor;
	static unsigned int guidcomponent;
	static Game* gameinstance;
};

}