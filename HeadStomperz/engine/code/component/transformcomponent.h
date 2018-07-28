//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "glm\ext.hpp"
#include "component\component.h"
using namespace glm;

namespace HSZGame {

enum TransformType
{
	REGULAR_T,
	SPRITE_T
};

class TransformComponent : public Component
{
public:
	TransformComponent(unsigned int owningactorid);
	TransformComponent(unsigned int owningactorid, char* componentname);
	~TransformComponent();
	virtual bool Initialize();
	void UpdateWorld();
	void UpdateWorldSprite(vec2 sz);
	mat4 GetWorldMatrix();
	void SetTransformType(TransformType type);
	// -- transformation vars
	vec2 position;
	vec2 scale;
	float rotation;
private:
	mat4 world;
	TransformType transformtype;
};

}