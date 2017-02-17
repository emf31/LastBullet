#version 330 core

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

out vec4 color;


uniform sampler2D texture_diffuse1;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;

void main()
{    
	float gradoLuzAmbiente = 0.1f;
	
	//luz ambiente
	vec3 ambient=lightColor*gradoLuzAmbiente;
	
	//vector normal desde el modelo
	vec3 norm = normalize(Normal);
	
	//vector de direccion de la luz
	vec3 lightDir = normalize(lightPos - FragPos);
	
	//calculamos el impacto de la luz dependiendo de su angulo respecto a la normal del modelo
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;
	
	
    color = vec4(texture(texture_diffuse1, TexCoords));
	color *= vec4((ambient + diffuse) * objectColor, 1.0f);
}
