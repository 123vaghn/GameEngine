#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords0;

uniform mat4x4 uMVP;
uniform mat4x4 uWorldMatrix;

out vec3 Normal0;
out vec2 TexCoords0;
out vec3 FragPosition0;

void main()
{
	gl_Position = uMVP * vec4(aPos, 1.0);

	Normal0 = mat3(transpose(inverse(uWorldMatrix))) * aNormal;
	TexCoords0 = aTexCoords0;

	FragPosition0 = vec3(uWorldMatrix * vec4(aPos, 1.0));
}
