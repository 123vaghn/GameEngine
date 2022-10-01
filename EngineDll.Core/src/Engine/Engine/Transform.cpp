
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


#include "pch.h"
#include "Engine/Engine/Transform.h"
#include "Engine/Engine/Components/Camera.h"
#include "Engine/Exception.h"

using namespace Engine;
using namespace Engine::Components;


/**
 * implementation
 */
Transform::Transform()
	: m_Changed(false),
	  m_ParentMatrix(Matrix4Fx4F::GetIdentityMatrix4Fx4F()),
	  m_Position(0, 0, 0),
	  m_Rotation(1, 0, 0, 0),
	  m_Scale(1, 1, 1)
{
}


/**
 * implementation
 */
bool Transform::Tick()
{


	return true;
}


/**
 * implementation
 */
void Transform::Rotate(AngleF Angle, const VectorF &Axis)
{
	m_Rotation = QuaternionF::CreateFromAxisAngle(Axis, Angle) * m_Rotation;
	m_Rotation.Normalize();
}


/**
 * implementation
 */
void Transform::Rotate(const QuaternionF &Rotation)
{
	m_Position.Rotate(Rotation);
}


/**
 * implementation
 */
Matrix4Fx4F Transform::GetTransformation() const
{
	Matrix4Fx4F transformation = Matrix4Fx4F::CreateTRS(m_Position, m_Rotation, m_Scale);
	
	if (m_Parent)
	{
		m_ParentMatrix = m_Parent->GetTransformation();
	}
	else
	{
		m_ParentMatrix = Matrix4Fx4F::GetIdentityMatrix4Fx4F();
	}
	
	return m_ParentMatrix * transformation;
}


/**
 * implementation
 */
Matrix4Fx4F Transform::GetProjectedTransformation(const Camera &Camera) const
{
	Matrix4Fx4F projection = Camera.GetProjectionMatrix();
	Matrix4Fx4F view = Camera.GetViewMatrix();
	Matrix4Fx4F model = GetTransformation();

	/**
	 * Column-major multiplication.
	 * 
	 * The way the math library is setup currently *may* (unfortunately) give the illusion of this being row-major multiplication.
	 * Remember: Column-major multiplication.
	 * 
	 * 
	 * This means:
	 * 
	 * M 
	 * V 
	 * P 
	 * 
	 * Should be multiplied (or rather written) in reverse order, but then this multiplication code will run right to left.
	 * So, in reality, PVM is MVP.
	 */
	return projection * view * model; // model * view * projection
}


/**
 * implementation
 */
bool Transform::HasChanged() const
{
	return m_Changed;
}


/**
 * implementation
 */
Transform *Transform::GetParent() const
{
	return m_Parent;
}


/**
 * implementation
 */
Transform *Transform::GetRoot() const
{
	/**
	 * A transform is never will be a const object, so removing the const here is fine.
	 * 
	 * Don't over think things.
	 */
	return m_Parent ? m_Parent : const_cast<Transform *>(this);
}


/**
 * implementation
 */
const VectorF &Transform::GetPosition() const
{
	return m_Position;
}


/**
 * implementation
 */
const QuaternionF &Transform::GetRotation() const
{
	return m_Rotation;
}


/**
 * implementation
 */
const VectorF &Transform::GetScale() const
{
	return m_Scale;
}


/**
 * implementation
 */
void Transform::SetParent(Transform *Parent)
{
	m_Parent = Parent;
}


/**
 * implementation
 */
void Transform::SetPosition(const VectorF &Position)
{
	m_Position = Position;
}


/**
 * implementation
 */
void Transform::SetRotation(const QuaternionF &Rotation)
{
	m_Rotation = Rotation;
}


/**
 * implementation
 */
void Transform::SetScale(const VectorF &Scale)
{
	m_Scale = Scale;
}


/**
 * implementation
 */
bool Transform::operator==(const Transform &Rhs)
{
	return 
		m_Position == Rhs.m_Position;
}


/**
 * implementation
 */
bool Transform::operator!=(const Transform &Rhs)
{
	return !(*this == Rhs);
}



