#version 330 core
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gTextura;


struct Material {
	sampler2D texture_diffuse;
    sampler2D texture_specular;
	sampler2D texture_normal;
    float brillo;
}; 

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

uniform Material material;

void main()
{    
    // Store the fragment position vector in the first gbuffer texture
    gPosition = FragPos;
    // Also store the per-fragment normals into the gbuffer
    gNormal = normalize(Normal);
    // And the diffuse per-fragment color
    gTextura.rgb = texture(material.texture_diffuse, TexCoords).rgb;
    // Store specular intensity in gAlbedoSpec's alpha component
    gTextura.a = texture(material.texture_specular, TexCoords).r;
}