//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "collisioncomponentsystem.h"
#include "game/game.h"

namespace HSZGame {

CollisionComponentSystem::CollisionComponentSystem()
{

}

CollisionComponentSystem::~CollisionComponentSystem()
{

}

void CollisionComponentSystem::Initialize()
{
	// -- for every transform component in this list
	for (int i = 0; i < components.size(); ++i)
	{
		// update transformations
		components[i]->Initialize();
	}
}

void CollisionComponentSystem::UpdateComponents(float dt)
{
	// -- get current level
	Level* currentlevel = Game::GetCurrentLevel();

	// -- for every transform component in this list
	for (int i = 0; i < components.size(); ++i)
	{
		// - only update if we are enabled
		if (!components[i]->enabled)
			skip;

		// Prepare transformations
		TransformComponent* collisiontransform = currentlevel->GetActorComponentByID<TransformComponent*>(components[i]->ownerid);

		if (collisiontransform != nullptr)
			components[i]->center = collisiontransform->position;
	}

	// -- for every transform component in this list
	for (int i = 0; i < components.size(); ++i)
	{
		// - only update if we are enabled
		if (!components[i]->enabled)
			skip;

		// -- are we checking a circle?
		CircleCollisionComponent* cc1 = dynamic_cast<CircleCollisionComponent*>(components[i]);
		if (cc1 != nullptr)
		{
			for (int j = i + 1; j < components.size(); ++j)
			{
				// - only continue if they are enabled
				if (!components[j]->enabled)
					skip;

				CircleCollisionComponent* cc2 = dynamic_cast<CircleCollisionComponent*>(components[j]);

				if (cc2 != nullptr)
				{
					if (Intersects(*cc1, *cc2))
					{
						printf("THERE IS COLLISION HAPPENING.\n");
						currentlevel->GetActorComponentByID<TransformComponent*>(cc2->ownerid)->enabled = false;
						cc2->enabled = false;
					}
				}
			}
		}
	}
}

void CollisionComponentSystem::PopulateFromCurrentLevel(Level* populatefrom)
{
	std::vector<CollisionComponent*>* collisioncomponentsinlevel = new std::vector<CollisionComponent*>();
	if (populatefrom->GetComponentsOfType(collisioncomponentsinlevel))
	{
		for (int i = 0; i < collisioncomponentsinlevel->size(); ++i)
		{
			CollisionComponent* collision = collisioncomponentsinlevel->at(i);
			components.push_back(collision);
		}
	}
}

void CollisionComponentSystem::ClearFromCurrentLevel()
{
	for (int i = 0; i < components.size(); ++i)
	{
		components.pop_back();
	}
	return;
}

// -- returns weather the two given circles intersect each other
bool CollisionComponentSystem::Intersects(CircleCollisionComponent& c1, CircleCollisionComponent& c2)
{
	float d = (c1.center.x - c2.center.x) * (c1.center.x - c2.center.x) +
		(c1.center.y - c2.center.y) * (c1.center.y - c2.center.y);
	float r = c1.radius * c1.radius + c2.radius * c2.radius;

	return d <= r;
}

}