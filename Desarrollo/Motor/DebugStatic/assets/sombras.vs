#version 330 core
layout (location = 0) in vec3 position;


uniform mat4 lightSpaceMatrix;
uniform mat4 model;
void main()
{
	//nuestro gPosition es model * vec4(position, 1.0f); sacado de la pasada de geometria por eso en vez de
	gl_Position = lightSpaceMatrix * model * vec4(position, 1.0f); 
	//vec3 FragPos = texture(gPosition, texCoords).rgb;
    //gl_Position = lightSpaceMatrix * vec4(FragPos, 1.0f);
}  