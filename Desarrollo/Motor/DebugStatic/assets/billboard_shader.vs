#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{

	mat4 modelView = view * model;

  	modelView[0][0] = 1.0; 
 	modelView[0][1] = 0.0; 
  	modelView[0][2] = 0.0; 


    modelView[1][0] = 0.0; 
    modelView[1][1] = 1.0; 
    modelView[1][2] = 0.0; 

  	modelView[2][0] = 0.0; 
  	modelView[2][1] = 0.0; 
  	modelView[2][2] = 1.0; 

	vec4 P = modelView *  vec4(position, 1.0f);
    gl_Position = projection * P;
    TexCoords = texCoords;
}