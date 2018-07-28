//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "component.h"
#include "glew.h"
#include "graphics\texture2D.h"
#include "graphics\shader.h"

namespace HSZGame {

class SpriteComponent : public Component
{
public:
	SpriteComponent(unsigned int owningactorid);
	SpriteComponent(unsigned int owningactorid, char* componentname);
	~SpriteComponent();
	virtual bool Initialize();
	void SetShader(Shader s);
	Shader GetShader();
	Texture2D GetImage();
	GLuint GetVAO();
	vec3 color;
	float alpha;
private:
	// -- GLuint handle for vertex buffer object
	GLuint vao;
	Texture2D image;
	Shader shader;
};

}