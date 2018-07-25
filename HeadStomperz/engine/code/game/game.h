//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "graphics\gamewindow.h"
#include "graphics\resolution.h"
#include "game\level.h" //also includes actor, vector
#include "componentsystem\spritecomponentsystem.h"
#include "camera\camera2D.h"
#include "utility\time.h"
#include "glm\ext.hpp"

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
	static void ChangeLevel(int levelindex);
	static Level* GetCurrentLevel();
	static Camera2D* GetDefaultCamera();
private:
	// internal engine functions ===================================================================
	bool Initialize(RESOLUTION res);
	void Update();
	void UpdateDisplay();
	void UpdateCameras();
	void UpdateComponentSystems();
	void Render();

	// variable members ============================================================================
	GameWindow* window;
	std::vector<Level*> levels;
	SpriteComponentSystem* spritecs;
	int currentlevelindex;
	std::vector<Camera2D*> cameras;
	Time* time;

	// static variable members =====================================================================
	static bool gameover;
	static unsigned int guidactor;
	static unsigned int guidcomponent;
	static Game* gameinstance;
};

}