#version 330 core
layout (location = 0) in vec3 position;


uniform mat4 Lightmvp;
void main()
{
	gl_Position = Lightmvp * vec4(position, 1.0f); 
	gl_Position.z = 2.0*log(gl_Position.w)/log(200.0f) - 1; 
    gl_Position.z *= gl_Position.w;
}  