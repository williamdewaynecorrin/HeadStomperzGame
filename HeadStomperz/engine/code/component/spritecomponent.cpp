//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "spritecomponent.h"
#include <stdio.h>

namespace HSZGame {

SpriteComponent::SpriteComponent()
{

}

SpriteComponent::~SpriteComponent()
{

}

// =================================================================================================
// COMPONENT INHERITED METHODS
// =================================================================================================
// -- initialize
bool SpriteComponent::Initialize(unsigned int owningactorid, char* componentname)
{
	// -- call base class init
	bool success = Component::Initialize(owningactorid, componentname);
	if (!success)
	{
		printf("Error initializing parent Component class.");
		return false;
	}
	// -- now setup all the rendering stuff needed for sprites
	GLuint vbo;
	// -- construct vertices for a regular sprite that is 1x1
	GLfloat vertices[] = {
		// Pos      // Tex
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};
	// -- generate the needed handles
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// -- now bind to the vao
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

}