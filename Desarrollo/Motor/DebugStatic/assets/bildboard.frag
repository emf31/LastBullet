#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

struct Material {
	sampler2D texture_diffuse;
    sampler2D texture_specular;
	sampler2D texture_normal;
    sampler2D texture_tangent;
    sampler2D texture_bitangent;
    sampler2D texture_emisivo;
    vec3 objectColor;
    float brillo;
}; 

uniform Material material;

void main()
{    
    FragColor = vec4(texture(material.texture_diffuse, TexCoords).rgb,1.0);
}