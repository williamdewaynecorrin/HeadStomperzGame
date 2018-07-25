//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "game\actor.h"

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
	// -- retrieves a given actor by unique id
	Actor* GetActorByID(unsigned int id);

	// -- gets all components instances in this level
	std::vector<Component*> GetAllComponents();
	//gets all component instances of a certain type in this level
	template<class T>
	bool GetComponentsOfType(std::vector<T*>* componentspointer);
private:
	// -- list of all actors in this level
	std::vector<Actor*> actors;
	// -- list of all components in this level
	std::vector<Component*> components;
	char* name;
};

// =================================================================================================
// -- TEMPLATE FUNCTIONS
// =================================================================================================
// =================================================================================================
// -- finds and pushes all components of given type into vector pointer. returns if vector size > 0
// =================================================================================================
template<class T>
bool Level::GetComponentsOfType(std::vector<T*>* componentspointer)
{
	int complen = components.size();
	for (int i = 0; i < complen; ++i)
	{
		//T* casted = T*(components[i]);
		T* casted = dynamic_cast<T*>(components[i]);

		if (casted != nullptr)
			(*componentspointer).push_back(casted);
	}

	printf("GetComponentsOfType found %d components of type.",
		(*componentspointer).size());

	return (*componentspointer).size() > 0;
}

}