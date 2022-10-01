#pragma once

namespace Engine::Graphics
{
	enum class BufferUsage
	{

	};

	enum class ShaderDataType : std::uint32_t
	{
		Float,
		Int,
		UnsignedInt,
		Float2,
		Float3,
		Float4,
		Int2,
		Int3,
		Int4,
		Matrix4Fx4F,
		Bool
	};
}
