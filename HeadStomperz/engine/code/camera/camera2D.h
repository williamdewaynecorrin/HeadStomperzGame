//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "glm\ext.hpp"
using namespace glm;

namespace HSZGame {

class camera2D
{
public:
	camera2D();
	~camera2D();
	void Update(float dt);
private:
	void UpdateProjection();
	void UpdateView();

	// -- projection vars
	vec2 topleft;
	vec2 bottomright;
	mat4 projectionortho;

	// -- view vars
};

}