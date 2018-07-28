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
	// -- update the transform slightly different depending on its type
	switch (transformtype)
	{
	case REGULAR_T:
		world = glm::translate(vec3(position.x, position.y, 0.0f)) *
			glm::scale(vec3(scale.x, scale.y, 1.0f)) *
			glm::rotate(rotation, vec3(0.0f, 0.0f, 1.0f));
		break;
	case SPRITE_T:
		UpdateWorldSprite(vec2(10.0f));
		break;
	}
}

// =================================================================================================
// -- updates the world matrix for sprites (origin at center)
// =================================================================================================
void TransformComponent::UpdateWorldSprite(vec2 sz)
{
	/*world = glm::translate(vec3(position.x, position.y, 0.0f)) *
		glm::scale(vec3(scale.x, scale.y, 1.0f)) *
		glm::rotate(rotation, vec3(0.0f, 0.0f, 1.0f));*/

	world = glm::translate(world, vec3(position, 0.0f));
	world = glm::translate(world, vec3(0.5f * sz.x, 0.5f * sz.y, 0.0f)); // Move origin of rotation to center of quad
	world = glm::rotate(world, rotation, vec3(0.0f, 0.0f, 1.0f)); // Then rotate
	world = glm::translate(world, vec3(-0.5f * sz.x, -0.5f * sz.y, 0.0f)); // Move origin back
	world = glm::scale(world, vec3(scale, 1.0f)); // Last scale
}

}