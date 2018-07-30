//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "spritecomponent.h"
#include <stdio.h>
#include "graphics\contentbase.h"

namespace HSZGame {

SpriteComponent::SpriteComponent(unsigned int owningactorid) :
	SpriteComponent(owningactorid, "default")
{
	
}
SpriteComponent::SpriteComponent(unsigned int owningactorid, char* componentname) :
	Component(owningactorid, componentname)
{
	color = vec3(1.0f, 1.0f, 1.0f);
	alpha = 1.0f;
}

SpriteComponent::~SpriteComponent()
{

}

Shader SpriteComponent::GetShader()
{
	return shader;
}

void SpriteComponent::SetShader(Shader s)
{
	this->shader = s;
}

Texture2D SpriteComponent::GetImage()
{
	return image;
}

void SpriteComponent::SetImage(Texture2D image)
{
	this->image = image;
}

GLuint SpriteComponent::GetVAO()
{
	return vao;
}

// =================================================================================================
// COMPONENT INHERITED METHODS
// =================================================================================================
// -- initialize
bool SpriteComponent::Initialize()
{
	// -- call base class init
	bool success = Component::Initialize();

	if (!success)
	{
		printf("Error initializing parent Component class.");
		return false;
	}

	// -- now setup all the rendering stuff needed for sprites
	GLuint vbo;
	// -- construct vertices for a regular sprite that is 1x1
	float sz = 200.0f;
	float szdiv2 = sz / 2.0f;
	float tx = 1.0f / 2.0f;
	float txoffset = tx + .005f;

	GLfloat vertices[] = {
		// Pos      // Tex
		-szdiv2, szdiv2, -tx + txoffset, tx + txoffset,
		-szdiv2, -szdiv2, -tx + txoffset, -tx + txoffset,
		szdiv2, -szdiv2, tx + txoffset, -tx + txoffset,

		-szdiv2, szdiv2, -tx + txoffset, tx + txoffset,
		szdiv2, szdiv2, tx + txoffset, tx + txoffset,
		szdiv2, -szdiv2, tx + txoffset, -tx + txoffset
	};

	this->SetShader(ContentBase::GetDefaultSpriteShader());
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

	return success;
}

}