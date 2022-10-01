#version 330 core

in vec3 Normal0;
in vec2 TexCoords0;
in vec3 FragPosition0;

uniform sampler2D uTexture2D;
uniform vec2 uUV0;

uniform vec3 LightPosition;
uniform vec3 LightColor;
uniform float LightIntensity;
uniform vec3 LightDirection;



/**
 * The finalized color to be applied on the per-pixel basis.
 * FragColor, by nature, is volatile.
 */
out vec4 FragColor;

void main()
{
	vec3 ambient = 0.1 * LightColor;
	vec4 sampledColor = texture(uTexture2D, TexCoords0 * uUV0);

	vec3 norm = normalize(Normal0);
	vec3 lightDir = normalize(LightPosition - FragPosition0);
	float diff = max(dot(norm, lightDir), 0);
	vec3 diffuse = diff * LightColor;
	
	vec4 result = (vec4(ambient, 1) + vec4(diffuse, 1)) * sampledColor;

	FragColor = result;
}
