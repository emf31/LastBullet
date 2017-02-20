#version 330 core

struct Material {
	sampler2D texture_diffuse;
    sampler2D texture_specular;
	sampler2D texture_normal;
    float brillo;
}; 

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

out vec4 color;



uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

uniform Material material;

void main()
{    
	
	
	//LUZ AMBIENTE
	float gradoLuzAmbiente = 0.2f;
	//vec3 ambient=lightColor*gradoLuzAmbiente;
	vec3 ambient = (lightColor*gradoLuzAmbiente) * vec3(texture(material.texture_diffuse, TexCoords));
	
	//LUZ DIFUSA
	//vector normal desde el modelo
	vec3 norm = normalize(Normal);
	//vector de direccion de la luz
	vec3 lightDir = normalize(lightPos - FragPos);
	//calculamos el impacto de la luz dependiendo de su angulo respecto a la normal del modelo
	float diff = max(dot(norm, lightDir), 0.0);
	//vec3 diffuse = diff * lightColor;
	vec3 diffuse = (lightColor * diff) * vec3(texture(material.texture_diffuse, TexCoords));  
	
	//LUZ ESPECULAR
	//calculamos el vector vista (desde donde el observador ve el objeto) y el vector de reflexion de la luz
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	
	//calculamos la luz especular, el 32 es la intensidad del brillo, cuando mas grande sea mas concentrado va a ser el brillo, se vera como un punto brillante
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
	vec3 specular =  (spec * lightColor) * vec3(texture(material.texture_specular, TexCoords)) ; 
	
	
    //color = vec4(texture(material.texture_diffuse, TexCoords));
	color = vec4((ambient + diffuse + specular) * objectColor, 1.0f);
}
