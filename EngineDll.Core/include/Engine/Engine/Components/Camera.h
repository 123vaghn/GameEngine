#pragma once

#include "Engine/Engine/Components/Behavior.h"

// Math
#include "Engine/Math/AngleF.h"
#include "Engine/Math/Matrix4Fx4F.h"
#include "Engine/Math/VectorF.h"

namespace Engine
{
	class Transform;
}

namespace Engine::Components
{
	enum class CameraProjectionType
	{
		Perspective,
		Ortho
	};

	class DLL_CLASS Camera : public Behavior
	{
	public:
		static const size_t ClassType;

	public:
		Camera();

		virtual ~Camera() override;
		
		virtual bool IsClassType(const size_t ClassType) const override;

		virtual void Tick() override;
		virtual void Render() override;

		void Input(const unsigned char *keys, float DeltaTime);
		
		void Move(const VectorF &Direction, float Speed);
		
		void CalculateProjectionMatrix();
		void CalculateViewMatrix();

		const Matrix4Fx4F &GetProjectionMatrix() const;
		const Matrix4Fx4F &GetViewMatrix() const;

		float GetWidth() const;
		float GetHeight() const;
		float GetFOV() const;
		CameraProjectionType GetProjectionType() const;
		float GetNear() const;
		float GetFar() const;

		float GetAspectRatio() const;

	private:
		CameraProjectionType m_ProjectionType;
		bool m_PMUpdate;
		float m_Width;
		float m_Height;
		float m_FOV;
		float m_Near;
		float m_Far;
		bool m_VMUpdate;

		Matrix4Fx4F m_ProjectionMatrix;
		Matrix4Fx4F m_ViewMatrix;
	};
}
