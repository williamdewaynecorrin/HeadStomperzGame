//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "texture2D.h"

namespace HSZGame {

Texture2D::Texture2D()
{
	// -- set default values for all this stuff
	width = 0;
	height = 0;
	internalformat = GL_RGB;
	imageformat = GL_RGB;
	wraps = GL_REPEAT;
	wrapt = GL_REPEAT;
	filtermin = GL_LINEAR;
	filtermax = GL_LINEAR;
	// -- actually generate the handle for the texture
	glGenTextures(1, &handle);
}

Texture2D::~Texture2D()
{
}

void Texture2D::Initialize(GLuint w, GLuint h, unsigned char* data)
{
	// -- set width and height
	this->width = w;
	this->height = h;
	// -- create texture
	Bind();
	glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width, height,
		0, imageformat, GL_UNSIGNED_BYTE, data);
	// -- set texture wrap modes and stuff
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wraps);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapt);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtermin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtermax);
	// -- unbind texture from buffer
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, handle);
}

void Texture2D::SetInternalFormat(GLuint e)
{
	internalformat = e;
}

void Texture2D::SetImageFormat(GLuint e)
{
	imageformat = e;
}

GLuint Texture2D::GetInternalFormat()
{
	return internalformat;
}

GLuint Texture2D::GetImageFormat()
{
	return imageformat;
}

//GLuint Texture2D::GetTextureID()
//{
//	return handle;
//}

}