//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "transformcomponentsystem.h"
#include "game\game.h"

namespace HSZGame {

	TransformComponentSystem::TransformComponentSystem()
	{

	}

	TransformComponentSystem::~TransformComponentSystem()
	{

	}

	void TransformComponentSystem::Initialize()
	{

	}

	void TransformComponentSystem::UpdateComponents(float dt)
	{
		// -- for every sprite component in this list
		for (int i = 0; i < components.size(); ++i)
		{
			// update transformations
			components[i]->UpdateWorld();
		}
	}

	void TransformComponentSystem::PopulateFromCurrentLevel(Level* populatefrom)
	{
		std::vector<TransformComponent*>* transformsinlevel = new std::vector<TransformComponent*>();
		if (populatefrom->GetComponentsOfType(transformsinlevel))
		{
			for (int i = 0; i < transformsinlevel->size(); ++i)
			{
				TransformComponent* transform = transformsinlevel->at(i);
				components.push_back(transform);
			}
		}
	}

	void TransformComponentSystem::ClearFromCurrentLevel()
	{
		for (int i = 0; i < components.size(); ++i)
		{
			components.pop_back();
		}
		return;
	}

}