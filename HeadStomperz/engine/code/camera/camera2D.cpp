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
	float szx = 1600.0f;
	float szy = 900.0f;
	// -- projection stuff
	topleft = vec2(-szx, -szy);
	bottomright = vec2(szx, szy);
	// -- glm::ortho: x, width, heigiht, y
	projectionortho = glm::ortho(topleft.x, bottomright.x, bottomright.y, topleft.y);
	transform = new TransformComponent(100000);
	//transform->position.x = -100.0f;
}


Camera2D::~Camera2D()
{
}

void Camera2D::GluOrthoSetup()
{
	glOrtho(topleft.x, bottomright.x, bottomright.y, topleft.y, 0.0001f, 10000000.0f);
}

void Camera2D::GluTranslateSetup()
{
	glTranslatef(transform->position.x, transform->position.y, 0.0f);
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
	UpdateView();
	UpdateWorld();
}

mat4 Camera2D::GetProjectionMatrix()
{
	return projectionortho;
}

mat4 Camera2D::GetViewMatrix()
{
	return viewortho;
}

vec2 Camera2D::GetPosition()
{
	return transform->position;
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

void Camera2D::UpdateView()
{
	viewortho = transform->GetWorldMatrix();
}

// =================================================================================================
// -- updates the world matrix
// =================================================================================================
void Camera2D::UpdateWorld()
{
	transform->UpdateWorld();
}

}