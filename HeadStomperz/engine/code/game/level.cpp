//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "level.h"
namespace HSZGame {

Level::Level(char levelname[])
{
	name = levelname;
	actors = std::map<unsigned int, Actor*>();
	components = std::map<unsigned int, Component*>();
}

Level::~Level()
{

}

// =================================================================================================
// -- PUBLIC FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- returns the actor associated with given id; nullptr if doesnt exist
// =================================================================================================
Actor* Level::GetActorByID(unsigned int id)
{
	int actorlen = actors.size();

	for (int i = 0; i < actorlen; ++i)
	{
		if (actors[i]->actorid == id)
			return actors[i];
	}

	return nullptr;
}

// =================================================================================================
// -- gets all actors in this level
// =================================================================================================
std::vector<Actor*> Level::GetAllActors()
{
	typedef map<unsigned int, Actor*> MapType;
	std::vector<Actor*> v;

	for (MapType::iterator it = actors.begin(); it != actors.end(); ++it) {
		v.push_back(it->second);
	}

	return v;
}

// =================================================================================================
// -- gets all components in this level
// =================================================================================================
std::vector<Component*> Level::GetAllComponents()
{
	typedef map<unsigned int, Component*> MapType;
	std::vector<Component*> v;

	for (MapType::iterator it = components.begin(); it != components.end(); ++it) {
		v.push_back(it->second);
	}

	return v;
}

// =================================================================================================
// -- gets all components in this level
// =================================================================================================
unsigned int Level::AddActor(char* actorname)
{
	Actor* a = new Actor(actorname);
	actors[a->actorid] = a;
	return a->actorid;
}
void Level::RegisterComponent(Component* component)
{
	components[component->componentid] = component;
	actors[component->ownerid]->AddComponent(component->componentid);
}

char* Level::GetName()
{
	return name;
}

}