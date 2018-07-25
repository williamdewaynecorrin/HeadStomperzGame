//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "contentbase.h"

namespace HSZGame{

// Instantiate static variables
std::map<const char*, Texture2D> ContentBase::textures;
std::map<const char*, Shader> ContentBase::shaders;

ContentBase::ContentBase()
{
}

Shader ContentBase::LoadShader(char* storagename, const char* vertshaderfile,
	const char* fragshaderfile, const char* geoshader)
{
	shaders[storagename] = LoadShaderFromFile(vertshaderfile, fragshaderfile, geoshader);
	return shaders[storagename];
}

Shader ContentBase::GetShader(char* storagename)
{
	return shaders[storagename];
}

Texture2D ContentBase::LoadTexture2D(char* storagename, const char* filename, bool usealpha)
{
	textures[storagename] = LoadTexture2DFromFile(filename, usealpha);
	return textures[storagename];
}

Texture2D ContentBase::GetTexture2D(char* storagename)
{
	return textures[storagename];
}

void ContentBase::ClearAll()
{
	// (Properly) delete all shaders	
	for (auto iter : shaders)
		glDeleteProgram(iter.second.GetShaderID());
	// (Properly) delete all textures
	for (auto iter : textures)
		glDeleteTextures(1, &iter.second.handle);
}

Shader ContentBase::LoadShaderFromFile(const char *vShaderFile, const char *fShaderFile,
	const char *gShaderFile)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try
	{
		// Open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;
		// Read file's buffer contents into streams
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();
		// close file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();
		// Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
		// If geometry shader path is present, also load a geometry shader
		if (gShaderFile != nullptr)
		{
			std::ifstream geometryShaderFile(gShaderFile);
			std::stringstream gShaderStream;
			gShaderStream << geometryShaderFile.rdbuf();
			geometryShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (std::exception e)
	{
		printf("ERROR::SHADER: Failed to read shader files\n");
	}
	const GLchar *vShaderCode = vertexCode.c_str();
	const GLchar *fShaderCode = fragmentCode.c_str();
	const GLchar *gShaderCode = geometryCode.c_str();
	// 2. Now create shader object from source code
	Shader shader;
	shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
	return shader;
}

Texture2D ContentBase::LoadTexture2DFromFile(const char *file, bool alpha)
{
	// Create Texture object
	Texture2D texture;
	if (alpha)
	{
		texture.SetInternalFormat(GL_RGBA);
		texture.SetImageFormat(GL_RGBA);
	}
	// Load image
	int width, height;
	unsigned char* image = SOIL_load_image(file, &width, &height, 0, 
		texture.GetImageFormat() == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
	// Now generate texture
	texture.Initialize(width, height, image);
	// And finally free image data
	SOIL_free_image_data(image);
	return texture;
}

}