//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "component.h"
#include "glew.h"

namespace HSZGame {

class SpriteComponent : public Component
{
public:
	SpriteComponent();
	~SpriteComponent();
	virtual bool Initialize(unsigned int owningactorid, char* componentname);
private:
	// -- GLuint handle for vertex buffer object
	GLuint vao;
};

}