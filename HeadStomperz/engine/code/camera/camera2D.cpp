//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "camera\camera2D.h"

namespace HSZGame {

// =================================================================================================
// CONSTRUCT / DESTRUCT
// =================================================================================================
Camera2D::Camera2D()
{
	// -- projection stuff
	topleft = vec2(0.0f, 0.0f);
	bottomright = vec2(800.0f, 600.0f);
	// -- glm::ortho: x, width, heigiht, y
	projectionortho = glm::ortho(topleft.x, bottomright.x, bottomright.y, topleft.y);

	// -- transformation stuff
	position = vec2(0.0f, 0.0f);
	scale = vec2(1.0f, 1.0f);
	rotation = 0.0f;
	// -- world matrix calculated by ROTATE SCALE TRANSLATE - remember reverse order
	world = glm::translate(vec3(position.x, position.y, 0.0f)) *
		glm::scale(vec3(scale.x, scale.y, 1.0f)) *
		glm::rotate(radians(rotation), vec3(0.0f, 0.0f, 1.0f));
			
}


Camera2D::~Camera2D()
{
}

// =================================================================================================
// PUBLIC FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- updates all aspects of the camera
// =================================================================================================
void Camera2D::Update(float dt)
{
	UpdateProjection();
	UpdateWorld();
}

// =================================================================================================
// PRIVATE FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- updates the projection matrix
// =================================================================================================
void Camera2D::UpdateProjection()
{
	// -- update projection matrix using glm::ortho (x, width, height, y)
	projectionortho = glm::ortho(topleft.x, bottomright.x, bottomright.y, topleft.y);
}

// =================================================================================================
// -- updates the world matrix
// =================================================================================================
void Camera2D::UpdateWorld()
{
	world = glm::translate(vec3(position.x, position.y, 0.0f)) *
		glm::scale(vec3(scale.x, scale.y, 1.0f)) *
		glm::rotate(rotation, vec3(0.0f, 0.0f, 1.0f));
}

}