#version 330 core

in vec2 TexCoords;

out vec4 color;

uniform sampler2D texture_diffuse1;
uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{    
    color = vec4(texture(texture_diffuse1, TexCoords));
	color *= vec4(lightColor * objectColor, 1.0f);
}
