//==================================================================================================
//--------------------- Head Stomperz -------------- William Dewayne Corrin ------------------------
//--------------------------------------- (c) William Dewayne Corrin, 2018  ------------------------
//==================================================================================================

#include "shader.h"
#include <iostream>>

namespace HSZGame {

// =================================================================================================
// CONSTRUCT / DESTRUCT
// =================================================================================================
Shader::Shader()
{
}

Shader::~Shader()
{
}

GLuint Shader::GetShaderID()
{
	return shaderid;
}

Shader& Shader::SetAsActiveShader()
{
	glUseProgram(this->shaderid);
	return *this;
}

// =================================================================================================
// COMPILE SHADER
// =================================================================================================
void Shader::Compile(const char* vertexshader, const char* fragmentshader, const char* geoshader)
{
	GLuint sVertex, sFragment, gShader;
	// -- vertex shader creation and compilation
	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexshader, NULL);
	glCompileShader(sVertex);
	CheckCompileErrors(sVertex, "VERTEX");
	// -- fragment shader creation and compilation
	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentshader, NULL);
	glCompileShader(sFragment);
	CheckCompileErrors(sFragment, "FRAGMENT");
	// If geometry shader source code is given, also compile geometry shader
	if (geoshader != nullptr)
	{
		gShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(gShader, 1, &geoshader, NULL);
		glCompileShader(gShader);
		CheckCompileErrors(gShader, "GEOMETRY");
	}
	// Shader Program
	this->shaderid = glCreateProgram();
	// -- attach vertex and fragment shaders to this shaderid
	glAttachShader(this->shaderid, sVertex);
	glAttachShader(this->shaderid, sFragment);
	// -- do the same for geometry shader if it exists
	if (geoshader != nullptr)
		glAttachShader(this->shaderid, gShader);

	// -- link the shader program
	glLinkProgram(this->shaderid);
	CheckCompileErrors(this->shaderid, "PROGRAM");
	// -- we can now delete shaders because they are in our program
	glDeleteShader(sVertex);
	glDeleteShader(sFragment);
	if (geoshader != nullptr)
		glDeleteShader(gShader);
}

// =================================================================================================
// SET UNIFORM SHADER FUNCTIONS
// =================================================================================================
// -- sets given variable name value to given integer value
void Shader::SetInteger(const char* uniformname, int value)
{
	glUniform1i(glGetUniformLocation(shaderid, uniformname), value);
}
// -- sets given variable name value to given float value
void Shader::SetFloat(const char* uniformname, float value)
{
	glUniform1f(glGetUniformLocation(shaderid, uniformname), value);
}
// -- sets given variable name value to given float values
void Shader::SetFloat2(const char* uniformname, float value1, float value2)
{
	glUniform2f(glGetUniformLocation(shaderid, uniformname), value1, value2);
}
// -- sets given variable name value to given glm::vec2 value
void Shader::SetFloat2(const char* uniformname, vec2& pair)
{
	glUniform2f(glGetUniformLocation(shaderid, uniformname), pair.x, pair.y);
}
// -- sets given variable name value to given float values
void Shader::SetFloat3(const char* uniformname, float value1, float value2, float value3)
{
	glUniform3f(glGetUniformLocation(shaderid, uniformname), value1, value2, value3);
}
// -- sets given variable name value to given glm::vec3 value
void Shader::SetFloat3(const char* uniformname, vec3& pair)
{
	glUniform3f(glGetUniformLocation(shaderid, uniformname), pair.x, pair.y, pair.z);
}
// -- sets given variable name value to given float values
void Shader::SetFloat4(const char* uniformname, float value1, float value2, float value3, float value4)
{
	glUniform4f(glGetUniformLocation(shaderid, uniformname), value1, value2, value3, value4);
}
// -- sets given variable name value to given glm::vec4 value
void Shader::SetFloat4(const char* uniformname, vec4& pair)
{
	glUniform4f(glGetUniformLocation(shaderid, uniformname), pair.x, pair.y, pair.z, pair.w);
}
// -- sets given variable name value to given matrix value
void Shader::SetMatrix4x4(const char* uniformname, mat4& matrix)
{
	glUniformMatrix4fv(glGetUniformLocation(shaderid, uniformname), 1, GL_FALSE, &matrix[0][0]);
}

// =================================================================================================
// PRIVATE FUNCTIONS
// =================================================================================================
// -- checks and prints shader compile errors if they exist
void Shader::CheckCompileErrors(GLuint obj, std::string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(obj, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(obj, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
		else printf("Compiled %s shader with no errors.\n", type.c_str());
	}
	else
	{
		glGetProgramiv(obj, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(obj, 1024, NULL, infoLog);
			std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
}
}