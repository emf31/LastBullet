#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoords;

uniform mat4 lightSpaceMatrix;
uniform sampler2D gPosition;
void main()
{
	//nuestro gPosition es model * vec4(position, 1.0f); sacado de la pasada de geometria por eso en vez de
	// gl_Position = lightSpaceMatrix * model * vec4(position, 1.0f); hacemos :
	vec3 FragPos = texture(gPosition, texCoords).rgb;
    gl_Position = vec4(FragPos, 1.0f);
}  