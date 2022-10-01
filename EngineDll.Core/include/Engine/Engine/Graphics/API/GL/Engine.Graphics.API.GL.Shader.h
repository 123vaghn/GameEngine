
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/Graphics/Shader.h"

namespace Engine::Graphics::API::GL
{
	class DLL_CLASS Shader : public Engine::Graphics::Shader
	{
	public:
		/// <summary>
		/// Creates a new, uninitialized OpenGL shader.
		/// </summary>
		Shader() noexcept;
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="VertexShader"></param>
		/// <param name="FragmentShader"></param>
		Shader(const char *const VertexShader, const char *const FragmentShader);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		Shader(const Shader &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		Shader(Shader &&Other) noexcept;

		~Shader() override;

		/// <summary>
		/// 
		/// </summary>
		void Bind() const override;
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Uniform"></param>
		void UploadUniformByName(const char *const Name, double Uniform) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Uniform"></param>
		void UploadUniformByName(const char *const Name, int32_t Uniform) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Uniform"></param>
		void UploadUniformByName(const char *const Name, uint32_t Uniform) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Uniform"></param>
		void UploadUniformByName(const char *const Name, const VectorF &Uniform) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="F0"></param>
		/// <param name="F1"></param>
		void UploadUniformByName(const char *const Name, float F0, float F1) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="F0"></param>
		/// <param name="F1"></param>
		/// <param name="F2"></param>
		/// <param name="F3"></param>
		void UploadUniformByName(const char *const Name, float F0, float F1, float F2, float F3) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Uniform"></param>
		void UploadUniformByName(const char *const Name, const Matrix4Fx4F &Uniform) override;
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Uniform"></param>
		void UploadUniformByName(const char *const Name, float *Uniform) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Uniform"></param>
		void UploadUniformByName(const char *const Name, int32_t *Uniform) override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <param name="Uniform"></param>
		void UploadUniformByName(const char *const Name, uint32_t *Uniform) override;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		uint32_t GetID() const override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		Shader &operator=(const Shader &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		Shader &operator=(Shader &&Other) noexcept;
	
	protected:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="Name"></param>
		/// <returns></returns>
		int32_t GetUniformIDByName(const char *const Name) const override;

	private:
		uint32_t m_ID;
		mutable std::unordered_map<const char*, int32_t> m_UniformIDs;
	};
}
