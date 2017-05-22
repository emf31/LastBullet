#version 330 core
layout (location = 0) in vec3 position;


uniform mat4 Lightmvp;
void main()
{
	gl_Position = Lightmvp * vec4(position, 1.0f); 
}  