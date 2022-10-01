
// 
// Copyright (C) 2022, 2022 Joseph Combs.
//
//  
// This software is licensed under the BSD 3-Clause License. You may use this software 
// under the terms of the BSD 3-Clause License.
// 
// 
// See LICENSE for details.
// 


#pragma once

#include "Engine/Engine/Object.h"
#include "Engine/Math/Matrix4Fx4F.h"
#include "Engine/Math/QuaternionF.h"
#include "Engine/Math/VectorF.h"

namespace Engine::Components
{
	class Camera;
}

namespace Engine
{
	class Actor;
	class Transform;

	class DLL_CLASS Transform
	{
		friend class Actor;
		friend class Transform;

	public:
		Transform();

		bool Tick();

		void Rotate(AngleF Angle, const VectorF &Axis);
		void Rotate(const QuaternionF &Rotation);

		Matrix4Fx4F GetTransformation() const;
		Matrix4Fx4F GetProjectedTransformation(const Components::Camera &Camera) const;

		bool HasChanged() const;

		Transform *GetParent() const;
		Transform *GetRoot() const;

		const VectorF &GetPosition() const;
		const QuaternionF &GetRotation() const;
		const VectorF &GetScale() const;

		void SetParent(Transform *Parent);

		void SetPosition(const VectorF &Position);
		void SetRotation(const QuaternionF &Rotation);
		void SetScale(const VectorF &Scale);

		bool operator==(const Transform &Rhs);
		bool operator!=(const Transform &Rhs);

	private:
		bool m_Changed;

		mutable Transform *m_Parent = nullptr;
		mutable Matrix4Fx4F m_ParentMatrix;

		VectorF m_Position;
		QuaternionF m_Rotation;
		VectorF m_Scale;
	};
}
