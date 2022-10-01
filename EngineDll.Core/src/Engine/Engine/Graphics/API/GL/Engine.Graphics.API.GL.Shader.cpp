
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.Shader.h"
#include "Engine/GL/GL3.h"
#include "Engine/Math/Matrix4Fx4F.h"
#include "Engine/Math/VectorF.h"

using namespace Engine;
using namespace Engine::Graphics;

static bool CompileShader(uint32_t &ID, uint32_t Mode, const char *const SourceCode)
{
	glShaderSource(ID, 1, static_cast<const GLchar *const *>(&SourceCode), 0);
	glCompileShader(ID);

	GLint isCompiled = 0;
	glGetShaderiv(ID, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(ID, maxLength, &maxLength, &infoLog[0]);

		std::cout << &infoLog[0] << std::endl;

		return true;
	}

#if defined(_DEBUG)
	std::cout << "Shader compilation: SUCCEEDED" << std::endl;
#endif

	return false;
}


/**
 * implementation
 */
API::GL::Shader::Shader() noexcept
{
}


/**
 * implementation
 */
API::GL::Shader::Shader(const char *const VertexShaderSourceCode, const char *const FragmentShaderSourceCode)
	: m_ID(glCreateProgram())
{
	GLuint VertexShader;
	GLuint FragmentShader;

	VertexShader = glCreateShader(GL_VERTEX_SHADER);
	FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	if (CompileShader(VertexShader, GL_VERTEX_SHADER, VertexShaderSourceCode))
	{
		glDeleteShader(VertexShader);
		glDeleteShader(FragmentShader);

#if defined(_DEBUG)
#endif

		return;
	}

	glAttachShader(m_ID, VertexShader);

	if (CompileShader(FragmentShader, GL_FRAGMENT_SHADER, FragmentShaderSourceCode))
	{
		glDeleteShader(VertexShader);
		glDeleteShader(FragmentShader);

#if defined(_DEBUG)
#endif

		return;
	}

	glAttachShader(m_ID, FragmentShader);

	glLinkProgram(m_ID);

	GLint isLinked = 0;
	glGetProgramiv(m_ID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(m_ID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(m_ID, maxLength, &maxLength, &infoLog[0]);

		std::cout << &infoLog[0] << std::endl;

		glDeleteShader(VertexShader);
		glDeleteShader(FragmentShader);

		glDeleteProgram(m_ID);

		return;
	}

	glDetachShader(m_ID, VertexShader);
	glDetachShader(m_ID, FragmentShader);
}


/**
 * implementation
 */
API::GL::Shader::Shader(const API::GL::Shader &Other)
{
}


/**
 * implementation
 */
API::GL::Shader::Shader(API::GL::Shader &&Other) noexcept
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_UniformIDs, m_UniformIDs);
}


/**
 * implementation
 */
API::GL::Shader::~Shader()
{
	glDeleteProgram(m_ID);
}


/**
 * implementation
 */
void API::GL::Shader::Bind() const
{
	glUseProgram(m_ID);
}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, double Uniform)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniform1f(uniform, static_cast<float>(Uniform));
}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, int32_t Uniform)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniform1i(uniform, Uniform);
}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, uint32_t Uniform)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniform1ui(uniform, Uniform);

}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, const VectorF &Uniform)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniform3f(uniform, Uniform.X, Uniform.Y, Uniform.Z);
}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, float F0, float F1)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniform2f(uniform, F0, F1);
}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, float F0, float F1, float F2, float F3)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniform4f(uniform, F0, F1, F2, F3);
}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, const Matrix4Fx4F &Uniform)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniformMatrix4fv(uniform, 1, GL_FALSE, Uniform);
}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, float *Array)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniform4fv(uniform, 1, Array);
}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, int32_t *Array)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniform4iv(uniform, 1, Array);
}


/**
 * implementation
 */
void API::GL::Shader::UploadUniformByName(const char *const Name, uint32_t *Array)
{
	int32_t uniform = GetUniformIDByName(Name);

	glUniform4uiv(uniform, 1, Array);
}


/**
 * implementation
 */
uint32_t API::GL::Shader::GetID() const
{
	return m_ID;
}


/**
 * implementation
 */
API::GL::Shader &API::GL::Shader::operator=(const API::GL::Shader &Other)
{
	return *this;
}


/**
 * implementation
 */
API::GL::Shader &API::GL::Shader::operator=(API::GL::Shader &&Other) noexcept
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_UniformIDs, m_UniformIDs);

	return *this;
}


/**
 * implementation
 */
int32_t API::GL::Shader::GetUniformIDByName(const char *const Name) const
{
	if (auto it = m_UniformIDs.find(Name); it != m_UniformIDs.end())
	{
		return it->second;
	}

	int32_t uniform = glGetUniformLocation(m_ID, Name);

	if (uniform != -1)
	{
		m_UniformIDs[Name] = uniform;
	}

	return uniform;
}

