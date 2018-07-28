//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include <vector>
#include "game\level.h"

namespace HSZGame {

// =================================================================================================
// == COMPONENT SYSTEM CLASS =======================================================================
// =================================================================================================
template <class T>
class ComponentSystem
{
public:
	// -- ctor & dtor
	ComponentSystem<T>();
	~ComponentSystem<T>();

	// -- update components
	virtual void UpdateComponents(float dt) = 0;
	// -- init
	virtual void Initialize() = 0;
	// -- populates the components of this systems
	virtual void PopulateFromCurrentLevel(Level* populatefrom) = 0;
	// -- clears the components of this system
	virtual void ClearFromCurrentLevel() = 0;

protected:
	// -- actual list of components
	std::vector<T*> components;
};

// =================================================================================================
// -- CONSTRUCTORS / DESTRUCTORS
// =================================================================================================
template <class T>
ComponentSystem<T>::ComponentSystem()
{
	components = std::vector<T*>();
}

template <class T>
ComponentSystem<T>::~ComponentSystem()
{
	
}

//// -- update components
//template <class T>
//void ComponentSystem<T>::UpdateComponents(float dt)
//{
//
//}
//// -- populates the components of this systems
//template <class T>
//void ComponentSystem<T>::PopulateFromCurrentLevel()
//{
//
//}
//// -- clears the components of this system
//template <class T>
//void ComponentSystem<T>::ClearFromCurrentLevel()
//{
//
//}

}