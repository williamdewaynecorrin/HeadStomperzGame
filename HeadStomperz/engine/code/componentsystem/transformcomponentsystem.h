//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "componentsystem\componentsystem.h"
#include "component\transformcomponent.h"

namespace HSZGame {

class TransformComponentSystem : public ComponentSystem<TransformComponent>
{
public:
	TransformComponentSystem();
	~TransformComponentSystem();
	// -- updates & renders all of the spritecomponents
	virtual void UpdateComponents(float dt);
	// -- init
	virtual void Initialize();
	// -- populates the component system with objects of this container type from current level
	virtual void PopulateFromCurrentLevel(Level* populatefrom);
	// -- clears the component system of all its components. used when changing levels / unloading
	virtual void ClearFromCurrentLevel();
};

}