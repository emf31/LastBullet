#version 330 core

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

out vec4 color;


uniform sampler2D texture_diffuse1;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{    
	
	
	//LUZ AMBIENTE
	float gradoLuzAmbiente = 0.1f;
	vec3 ambient=lightColor*gradoLuzAmbiente;
	
	//LUZ DIFUSA
	//vector normal desde el modelo
	vec3 norm = normalize(Normal);
	//vector de direccion de la luz
	vec3 lightDir = normalize(lightPos - FragPos);
	//calculamos el impacto de la luz dependiendo de su angulo respecto a la normal del modelo
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;
	
	//LUZ ESPECULAR
	float gradoLuzEspecular = 0.5f;
	//calculamos el vector vista (desde donde el observador ve el objeto) y el vector de reflexion de la luz
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	
	//calculamos la luz especular, el 32 es la intensidad del brillo, cuando mas grande sea mas concentrado va a ser el brillo, se vera como un punto brillante
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
	vec3 specular = gradoLuzEspecular * spec * lightColor; 
	
	
    color = vec4(texture(texture_diffuse1, TexCoords));
	color *= vec4((ambient + diffuse + specular) * objectColor, 1.0f);
}
