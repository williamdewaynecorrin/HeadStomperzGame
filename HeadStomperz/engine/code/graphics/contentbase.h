//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "graphics\shader.h"
#include "graphics\texture2D.h"
//#include <Windows.h>
#include <SOIL.h>

namespace HSZGame {

class ContentBase
{
public:
	static Shader LoadShader(char* storagename, const char* vertshaderfile, 
		const char* fragshaderfile, const char* geoshader = nullptr);
	static Shader GetShader(char* storagename);
	static Texture2D LoadTexture2D(char* storagename, const char* filename, bool usealpha);
	static Texture2D GetTexture2D(char* storagename);
	static void	ClearAll();
private:
	ContentBase();
	static std::map<const char*, Shader> shaders;
	static std::map<const char*, Texture2D> textures;
	static Shader LoadShaderFromFile(const char *vShaderFile, const char *fShaderFile,
		const char *gShaderFile);
	static Texture2D ContentBase::LoadTexture2DFromFile(const char *file, bool alpha);
};

}
