//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "glew.h"

namespace HSZGame {

class Texture2D
{
public:
	Texture2D();
	~Texture2D();
	void Initialize(GLuint w, GLuint h, unsigned char* data);
	void Bind() const;
	void SetInternalFormat(GLuint e);
	void SetImageFormat(GLuint e);
	GLuint GetInternalFormat();
	GLuint GetImageFormat();
	GLuint handle;
private:
	GLuint width, height;
	GLuint internalformat, imageformat;
	GLuint wraps, wrapt, filtermin, filtermax;
};

}