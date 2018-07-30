//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "transformcomponent.h"

namespace HSZGame {

TransformComponent::TransformComponent(unsigned int owningactorid) :
	TransformComponent(owningactorid, "default")
{

}

TransformComponent::TransformComponent(unsigned int owningactorid, char* componentname) :
	Component(owningactorid, componentname)
{
	// -- transformation stuff
	position = vec2(0.0f, 0.0f);
	scale = vec2(1.0f, 1.0f);
	rotation = 0.0f;
	// -- world matrix calculated by ROTATE SCALE TRANSLATE - remember reverse order
	transformtype = REGULAR_T;
	UpdateWorld();
}


TransformComponent::~TransformComponent()
{

}

mat4 TransformComponent::GetWorldMatrix()
{
	return world;
}

bool TransformComponent::Initialize()
{
	return Component::Initialize();
}

void TransformComponent::SetTransformType(TransformType type)
{
	transformtype = type;
}

// =================================================================================================
// -- updates the world matrix
// =================================================================================================
void TransformComponent::UpdateWorld()
{
	//position += 0.01f;

	if (this->ownerid == 0)
		rotation += 0.1f;
	else if (this->ownerid == 1)
		position.x -= 0.25f;
	world = glm::translate(vec3(position.x, position.y, 0.0f)) *
		//glm::translate(vec3(50.0f, 50.0f, 0.0f)) *
		glm::rotate(glm::radians(rotation), vec3(0.0f, 0.0f, 1.0f)) *
		glm::scale(vec3(scale.x, scale.y, 1.0f));// *
		//glm::translate(vec3(-50.0f, -50.0f, 0.0f));
}

// =================================================================================================
// -- updates the world matrix for sprites (origin at center)
// =================================================================================================
void TransformComponent::UpdateWorldSprite(vec2 sz)
{

}

}