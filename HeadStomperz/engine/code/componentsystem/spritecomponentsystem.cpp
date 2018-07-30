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
	// -- for every sprite component in this list
	for (int i = 0; i < components.size(); ++i)
	{
		// init sprites
		components[i]->Initialize();
	}
}

void SpriteComponentSystem::UpdateComponents(float dt)
{
	// -- get current level
	Level* currentlevel = Game::GetCurrentLevel();
	// -- for every sprite component in this list
	for (int i = 0; i < components.size(); ++i)
	{
		// - only update if we are enabled
		if (!components[i]->enabled)
			skip;

		// Prepare transformations
		TransformComponent* spritetransform = currentlevel->GetActorComponentByID<TransformComponent*>(components[i]->ownerid);

		// -- bind this sprites shader as active
		components[i]->GetShader().SetAsActiveShader();
		// -- set world & proj matrix
		mat4 mvp = currentlevel->ActiveCamera()->GetProjectionMatrix() * currentlevel->ActiveCamera()->GetViewMatrix() * 
			spritetransform->GetWorldMatrix();

		components[i]->GetShader().SetMatrix4x4("model", spritetransform->GetWorldMatrix());
		components[i]->GetShader().SetMatrix4x4("view", currentlevel->ActiveCamera()->GetViewMatrix());
		components[i]->GetShader().SetMatrix4x4("projection", currentlevel->ActiveCamera()->GetProjectionMatrix());
		components[i]->GetShader().SetMatrix4x4("mvp", mvp);
		// -- set sprite color attribute
		components[i]->GetShader().SetFloat3("tint", components[i]->color);
		components[i]->GetShader().SetFloat("alpha", components[i]->alpha);

		if (components[i]->GetImage().IsAlphaBlended())
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}
		else
		{
			glDisable(GL_BLEND);
		}

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