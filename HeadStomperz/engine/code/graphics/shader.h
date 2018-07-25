//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#pragma once
#include "glew.h"
#include "glm\ext.hpp"
using namespace glm;

namespace HSZGame {

class Shader
{
public:
	Shader();
	~Shader();
	// -- sets this shader as the active shader
	Shader &SetAsActiveShader();
	// -- compiles this shader given vertex shader, frag shader and optional geometry shader
	void Compile(const char* vertexshader, const char* fragmentshader,
		const char* geoshader = nullptr);
	// -- lots of helper functions for setting uniform variables inside the shader
	void SetInteger(const char* uniformname, int value);
	void SetFloat(const char* uniformname, float value);
	void SetFloat2(const char* uniformname, float value1, float value2);
	void SetFloat2(const char* uniformname, vec2& pair);
	void SetFloat3(const char* uniformname, float value1, float value2, float value3);
	void SetFloat3(const char* uniformname, vec3& pair);
	void SetFloat4(const char* uniformname, float value1, float value2, float value3, float value4);
	void SetFloat4(const char* uniformname, vec4& pair);
	void SetMatrix4x4(const char* uniformname, mat4& matrix);
	GLuint GetShaderID();
private:
	GLuint shaderid;
	void CheckCompileErrors(GLuint obj, std::string type);
};

}