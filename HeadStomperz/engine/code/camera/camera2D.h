//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "glm\ext.hpp"
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
private:
	void UpdateProjection();
	void UpdateWorld();

	// -- projection vars
	vec2 topleft;
	vec2 bottomright;
	mat4 projectionortho;

	// -- transformation vars
	vec2 position;
	vec2 scale;
	float rotation;
	mat4 world;
};

}