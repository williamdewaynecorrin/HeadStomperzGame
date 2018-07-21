//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include <stdio.h>
#include "glew.h"
#include "glfw3.h"
namespace HSZGame 
{
// =================================================================================================
// == GAME WINDOW CLASS ============================================================================
// =================================================================================================
class GameWindow
{
public:
	// constructors ================================================================================
	GameWindow(int width, int height);
	GameWindow(int width, int height, char windowTitle[], bool fullScreen);
	~GameWindow();

	// initialize window function ==================================================================
	GLFWwindow* WindowInit(int w, int h, char windowTitle[], bool fullscreen);

	// change window attributes functions ==========================================================
	bool SetWindowDimensions(int width, int height);
	bool SetFullscreen(bool isFullscreen);

	// get window attributes functions =============================================================
	GLFWwindow* GetGLFWwindow();
	int GetHeight();
	int GetWidth();
	bool IsFullscreen();
private:
	// private window attribute variables ==========================================================
	int height, width;
	bool fullscreen;
	// the actual window object from GLFW ==========================================================
	GLFWwindow* window;
};

}