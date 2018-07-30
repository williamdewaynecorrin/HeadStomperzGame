//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "glm\ext.hpp"
#include "component\transformcomponent.h"
#include "glew.h"

using namespace glm;

namespace HSZGame {
// =================================================================================================
// == 2D CAMERA CLASS ==============================================================================
// =================================================================================================
class Camera2D
{
public:
	// -- constructor and destructor
	Camera2D();
	~Camera2D();
	// -- public methods
	void Update(float dt);
	mat4 GetProjectionMatrix();
	mat4 GetViewMatrix();
	vec2 GetPosition();
	void GluOrthoSetup();
	void GluTranslateSetup();
private:
	// -- update camera functions for projection and world
	void UpdateProjection();
	void UpdateView();
	void UpdateWorld();

	// -- projection vars
	vec2 topleft;
	vec2 bottomright;
	mat4 projectionortho;
	mat4 viewortho;
	TransformComponent* transform;
};

}