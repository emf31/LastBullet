#version 330 core
out vec4 FragColor;

in vec3 TexCoords;

uniform sampler2D muzzle;

void main()
{    
    FragColor = texture(muzzle, TexCoords);
}