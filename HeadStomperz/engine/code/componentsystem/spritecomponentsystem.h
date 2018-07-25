// =================================================================================================
// == COMPONENT SYSTEM CLASS =======================================================================
// =================================================================================================

#pragma once
#include "componentsystem\componentsystem.h"
#include "component\spritecomponent.h"

namespace HSZGame {

class SpriteComponentSystem : public ComponentSystem<SpriteComponent>
{
public:
	SpriteComponentSystem();
	~SpriteComponentSystem();
	SpriteComponentSystem(ComponentSystem<Component*>* compsys);
	virtual void UpdateComponents(float dt);
	virtual void PopulateFromCurrentLevel();
	virtual void ClearFromCurrentLevel();
};

}