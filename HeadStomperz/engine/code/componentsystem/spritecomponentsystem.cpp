// =================================================================================================
// == COMPONENT SYSTEM CLASS =======================================================================
// =================================================================================================

#include "spritecomponentsystem.h"
#include "game\game.h"

namespace HSZGame {

SpriteComponentSystem::SpriteComponentSystem()
{

}

SpriteComponentSystem::~SpriteComponentSystem()
{

}

void SpriteComponentSystem::Initialize()
{

}

void SpriteComponentSystem::UpdateComponents(float dt)
{
	// -- get current level
	Level* currentlevel = Game::GetCurrentLevel();
	// -- for every sprite component in this list
	for (int i = 0; i < components.size(); ++i)
	{
		// Prepare transformations
		components[i]->GetShader().SetAsActiveShader();
		TransformComponent* spritetransform = currentlevel->GetActorComponentByID<TransformComponent*>(components[i]->ownerid);

		// -- set world matrix
		components[i]->GetShader().SetMatrix4x4("model", spritetransform->GetWorldMatrix());
		// -- set sprite color attribute
		components[i]->GetShader().SetFloat3("spriteColor", components[i]->color);

		// -- set the active texture and then bind the image using VAO
		glActiveTexture(GL_TEXTURE0);
		components[i]->GetImage().Bind();
		glBindVertexArray(components[i]->GetVAO());
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}
}

void SpriteComponentSystem::PopulateFromCurrentLevel(Level* populatefrom)
{
	std::vector<SpriteComponent*>* spritesinlevel = new std::vector<SpriteComponent*>();
	if (populatefrom->GetComponentsOfType(spritesinlevel))
	{
		for (int i = 0; i < spritesinlevel->size(); ++i)
		{
			SpriteComponent* sprite = spritesinlevel->at(i);
			components.push_back(sprite);
		}
	}
}

void SpriteComponentSystem::ClearFromCurrentLevel()
{
	for (int i = 0; i < components.size(); ++i)
	{
		components.pop_back();
	}
	return;
}

}