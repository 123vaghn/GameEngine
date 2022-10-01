#version 330 core

out vec4 o_Color;

uniform vec4 _Color;

in vec2 TexCoord0;
uniform sampler2D _Texture2D;

uniform vec2 _UV0;

void main()
{
	o_Color = texture(_Texture2D, TexCoord0 * _UV0);
}