// =================================================================================================
// == COMPONENT SYSTEM CLASS =======================================================================
// =================================================================================================

#include "spritecomponentsystem.h"
#include "game\game.h"

namespace HSZGame {

SpriteComponentSystem::SpriteComponentSystem()
{

}

SpriteComponentSystem::SpriteComponentSystem(ComponentSystem<Component*>* compsys)
{
	//this->components = compsys->GetComponentList();
}

SpriteComponentSystem::~SpriteComponentSystem()
{

}

void SpriteComponentSystem::UpdateComponents(float dt)
{
	return;
}

void SpriteComponentSystem::PopulateFromCurrentLevel()
{
	std::vector<SpriteComponent*>* spritesinlevel = nullptr;
	if (Game::GetCurrentLevel()->GetComponentsOfType(spritesinlevel))
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
	return;
}

}