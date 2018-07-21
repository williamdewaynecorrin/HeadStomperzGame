//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "gamewindow.h"
namespace HSZGame 
{
// =================================================================================================
// CONSTRUCT / DESTRUCT
// =================================================================================================
// =================================================================================================
// -- constructs a gamewindow with given width and height using lsit initiliazation
// =================================================================================================
GameWindow::GameWindow(int width, int height) :
	GameWindow(width, height, "HEAD STOMPERZ ENGINE", false)
{

}

// =================================================================================================
// -- constructs a gamewindow with given width and height, window title and fullscreen mode
// =================================================================================================
GameWindow::GameWindow(int width, int height, char windowTitle[], bool fullScreen)
{
	this->width = width;
	this->height = height;
	this->fullscreen = fullscreen;
	this->window = WindowInit(width, height, windowTitle, fullscreen);
}

// =================================================================================================
// -- destructor
// =================================================================================================
GameWindow::~GameWindow()
{

}

// =================================================================================================
// FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- creates a GLFWwindow and returns the window pointer
// =================================================================================================
GLFWwindow* GameWindow::WindowInit(int w, int h, char windowTitle[], bool fullscreen)
{
	// -- attempt to initialize glfw
	GLenum glfwErr = glfwInit();

	// -- check to see if there was a problem with initialization
	if (glfwErr != GLFW_TRUE)
	{
		fprintf(stderr, "Couldn't initialize glfw\n");
		return NULL;
	}

	// -- initialize the window with specific attributes
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DECORATED, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	GLFWwindow *window = glfwCreateWindow(w, h, windowTitle, fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
	glfwMakeContextCurrent(window);

	// -- debug log the version and graphics device
	printf("Version: %s\n", glGetString(GL_VERSION));
	printf("Device: %s\n", glGetString(GL_RENDERER));

	// -- initialize glew and do the same thing with error checking
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	if (err != GLEW_OK)
	{
		// Problem: glewInit failed, something is not working right
		printf("glewInit failed. %s\n", glewGetErrorString(err));
		return NULL;
	}

	// -- return the window pointer
	return window;
}

// =================================================================================================
// -- sets the dimensions of the window
// =================================================================================================
bool GameWindow::SetWindowDimensions(int width, int height)
{
	if (window == nullptr) {
		printf("GLFWwindow has not yet been initialized. Please initialize first before calling SetWindowDimensions.");
		return false;
	}

	this->width = width;
	this->height = height;
	glfwSetWindowSize(window, width, height);

	return true;
}

// =================================================================================================
// -- sets the fullscreen status of the window
// =================================================================================================
bool GameWindow::SetFullscreen(bool isFullscreen)
{
	if (window == nullptr) {
		printf("GLFWwindow has not yet been initialized. Please initialize first before calling SetFullscreen.");
		return false;
	}

	this->fullscreen = isFullscreen;

	//get current position of window
	int x, y = 0;
	glfwGetWindowPos(window, &x, &y);

	//if we arent desiring fullscreen, we dont care about monitor
	if (!fullscreen) {
		glfwSetWindowMonitor(window, nullptr, x, y, width, height, GLFW_DONT_CARE);
		return true;
	}

	//try to obtain monitor from glfw
	GLFWmonitor* monitor = glfwGetWindowMonitor(window);

	if (monitor == nullptr) {
		printf("GLFWmonitor is null, therefore cannot set fullscreen mode to true.");
		return false;
	}

	//if we made it here everything is okay
	glfwSetWindowMonitor(window, monitor, x, y, width, height, GLFW_DONT_CARE);
	return true;
}

// =================================================================================================
// ACCESSORS
// =================================================================================================
// =================================================================================================
// -- accesses the actual GLFWwindow pointer
// =================================================================================================
GLFWwindow* GameWindow::GetGLFWwindow()
{
	return this->window;
}

// =================================================================================================
// -- accesses the GameWindow height attribute
// =================================================================================================
int GameWindow::GetHeight()
{
	return this->height;
}

// =================================================================================================
// -- accesses the GameWindow width attribute
// =================================================================================================
int GameWindow::GetWidth()
{
	return this->width;
}

// =================================================================================================
// -- accesses the GameWindow fullscreen attribute
// =================================================================================================
bool GameWindow::IsFullscreen()
{
	return this->fullscreen;
}

}