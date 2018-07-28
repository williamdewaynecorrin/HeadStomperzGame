//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "game\actor.h"
#include <map>

namespace HSZGame {

// =================================================================================================
// == LEVEL CLASS ==================================================================================
// =================================================================================================
class Level
{
public:
	// -- constructor and destructor
	Level(char levelname[]);
	~Level();

	// -- gets all actor instances in this level
	std::vector<Actor*> GetAllActors();
	// -- gets a given actor by unique id
	Actor* GetActorByID(unsigned int id);
	// -- gets a given actor's component by component type and actor id. returns first of that type
	template<typename ComponentType>
	ComponentType GetActorComponentByID(unsigned int actorid);
	// -- gets a given component by looking up the specific component id
	//template<typename ComponentType>
	//ComponentType GetActorComponentByComponentId(Actor& a, unsigned int componentid);

	// -- gets all components instances in this level
	std::vector<Component*> GetAllComponents();
	//gets all component instances of a certain type in this level
	template<class ComponentType>
	bool GetComponentsOfType(std::vector<ComponentType>* componentspointer);

	char* GetName();
	// -- add content to level
	unsigned int AddActor(char* actorname);
	void RegisterComponent(Component* c);
private:
	// -- list of all actors in this level
	std::map<unsigned int, Actor*> actors;
	//std::vector<Actor*> actors;

	// -- list of all components in this level
	std::map<unsigned int, Component*> components;
	//std::vector<Component*> components;
	char* name;
};

// =================================================================================================
// -- TEMPLATE FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- finds and pushes all components of given type into vector pointer. returns if vector size > 0
// =================================================================================================
template<class ComponentType>
bool Level::GetComponentsOfType(std::vector<ComponentType>* componentspointer)
{
	int complen = components.size();
	for (int i = 0; i < complen; ++i)
	{
		//T* casted = T*(components[i]);
		ComponentType casted = dynamic_cast<ComponentType>(components[i]);

		if (casted != nullptr)
			(*componentspointer).push_back(casted);
	}

	printf("GetComponentsOfType found %d components of type.",
		(*componentspointer).size());

	return (*componentspointer).size() > 0;
}

// =================================================================================================
// -- goes through all of actors components, returns first one if any that matches component type
// =================================================================================================
template<typename ComponentType>
ComponentType Level::GetActorComponentByID(unsigned int actorid)
{
	Actor* a = GetActorByID(actorid);
	const std::vector<unsigned int> actorcomponents = a->GetComponents();

	for (int i = 0; i < actorcomponents.size(); ++i)
	{
		// -- get component unique id
		unsigned int compuid = actorcomponents[i];
		ComponentType casted = dynamic_cast<ComponentType>(components[compuid]);
		
		if (casted != nullptr)
			return casted;
	}

	return nullptr;
}

//template<typename ComponentType>
//ComponentType Level::GetActorComponentByComponentId(Actor& a, unsigned int componentid)
//{
//	const std::vector<unsigned int> actorcomponents = a.GetComponents();
//
//	for (int i = 0; i < actorcomponents.size(); ++i)
//	{
//		unsigned int compid = actorcomponents[i];
//		
//		if (componentid == compid)
//		{
//			return dynamic_cast<ComponentType>(a->GetComponentByID(componentid));
//		}
//	}
//
//	return nullptr;
//}

}