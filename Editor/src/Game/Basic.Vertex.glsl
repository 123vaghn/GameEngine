#version 330 core

layout (location = 0) in vec3 a_Pos;
layout (location = 1) in vec2 a_TexCoord0;
layout (location = 2) in vec3 a_Normal;

uniform mat4x4 _MVP;

out vec2 TexCoord0;

void main()
{
	gl_Position = _MVP * vec4(a_Pos, 1.0);

	TexCoord0 = a_TexCoord0;
}