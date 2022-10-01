
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

namespace Engine
{
	struct Vector2D;
	struct VectorF;
	struct Vector4;
	struct Matrix4Fx4F;
}

namespace Engine::Graphics
{
	class DLL_CLASS Shader
	{
	public:
		static Shader *Create(const char *const VertexShader, const char *const FragmentShader);

	public:
		Shader();

		virtual ~Shader();

		virtual void Bind() const = 0;

		virtual void UploadUniformByName(const char *const Name, double Uniform) = 0;
		virtual void UploadUniformByName(const char *const Name, int32_t Uniform) = 0;
		virtual void UploadUniformByName(const char *const Name, uint32_t Uniform) = 0;
		virtual void UploadUniformByName(const char *const Name, const VectorF &Uniform) = 0;
		virtual void UploadUniformByName(const char *const Name, float F0, float F1) = 0;
		virtual void UploadUniformByName(const char *const Name, float F0, float F1, float F2, float F3) = 0;
		virtual void UploadUniformByName(const char *const Name, const Matrix4Fx4F &Uniform) = 0;
		virtual void UploadUniformByName(const char *const Name, float *Array) = 0;
		virtual void UploadUniformByName(const char *const Name, int32_t *Array) = 0;
		virtual void UploadUniformByName(const char *const Name, uint32_t *Array) = 0;

		virtual uint32_t GetID() const = 0;

	protected:
		virtual int32_t GetUniformIDByName(const char *const Name) const = 0;
	};
}
