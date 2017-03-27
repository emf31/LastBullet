#version 330 core
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gTextura;
layout (location = 3) out vec3 gTangent;
layout (location = 4) out vec3 gBitangent;



struct Material {
	sampler2D texture_diffuse;
    sampler2D texture_specular;
	sampler2D texture_normal;
    sampler2D texture_tangent;
    sampler2D texture_bitangent;
    float brillo;
}; 

in vec2 txtcoords;
in vec3 FrgPs;
in vec3 Normal;
in mat3 normalMatrix;

uniform Material material;

void main()
{    

    //posicion
    gPosition.xyz = FrgPs;

    //leemos las normales de la textura, como la textura identifica un color y va de 0 a 1 tenemos que pasarlo a rango de -1 a 1 para que sea un vector de normales.
    gNormal = texture(material.texture_normal, txtcoords).rgb;
    gNormal = normalize(gNormal * 2.0 - 1.0);   
    
    
    //textura difusa
    gTextura.rgb = texture(material.texture_diffuse, txtcoords).rgb;
    
    //textura especular, guardada en la ultima componente, ya que usamos un vec4 para no tener que usar otro
    //vector para la textura especular
    gTextura.a = texture(material.texture_specular, txtcoords).r;

    //leemos las tangentes que nos las da assimp
    gTangent = texture(material.texture_tangent, txtcoords).rgb;

    //leemos las bitangentes que nos las da assimp
    gBitangent = texture(material.texture_bitangent, txtcoords).rgb;

    //calculamos la matriz BTN para pasar el vector normal de coordenadas tangentes a coordenadas del mundo
    vec3 T = normalize(normalMatrix * gTangent);
    vec3 B = normalize(normalMatrix * gBitangent);
    vec3 N = normalize(normalMatrix * Normal);  
    mat3 TBN = mat3(T,B,N);

    //convertimos la normal a coordenadas del mundo
    gNormal = normalize(TBN * gNormal);

}