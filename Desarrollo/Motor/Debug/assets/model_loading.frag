#version 330 core

struct Material {
	sampler2D texture_diffuse;
    sampler2D texture_specular;
	sampler2D texture_normal;
    float brillo;
}; 

struct SunLight {
vec3 especular;
vec3 difusa;
vec3 ambiente;
vec3 direction;
}; 

struct FlashLight {
	vec3 especular;
	vec3 difusa;
	vec3 ambiente;
    vec3  position;
    vec3  direction;
    float radioInterior;
    float radioExterior;
};  

struct PointLight {
	vec3 especular;
	vec3 difusa;
	vec3 ambiente;
    vec3  position;
};

vec3 calcularLuzSolar(SunLight sun,vec3 norm, vec3 viewDir);
vec3 calcularPointLight(PointLight light,vec3 norm, vec3 viewDir);
vec3 calcularFlashLight(FlashLight light,vec3 norm, vec3 viewDir);


in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

out vec4 color;



uniform vec3 objectColor;
uniform vec3 viewPos;
uniform Material material;

//luces
uniform SunLight sunlight;
uniform FlashLight flashlight;
uniform PointLight pointlight;


void main()
{    
	
	vec3 colorFinal;
	//vector normal desde el modelo
	vec3 norm = normalize(Normal);
	//calculamos el vector vista (desde donde el observador ve el objeto)
	vec3 viewDir = normalize(viewPos - FragPos);

	//*********************************LUZ SOLAR*****************************************
	colorFinal=calcularLuzSolar(sunlight,norm,viewDir);
	//*********************************POINT LIGHT*****************************************
	colorFinal+=calcularPointLight(pointlight,norm,viewDir);
	//*********************************LUZ LINTERNA*****************************************
	colorFinal+=calcularFlashLight(flashlight,norm,viewDir);

	color = vec4(colorFinal, 1.0);
}

vec3 calcularLuzSolar(SunLight sun,vec3 norm, vec3 viewDir){
		
	vec3 lightDir = normalize(-sunlight.direction);
	vec3 ambient = sunlight.ambiente * vec3(texture(material.texture_diffuse, TexCoords));
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = sunlight.difusa * diff * vec3(texture(material.texture_diffuse, TexCoords)); 
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
	vec3 specular =  (spec * sunlight.especular) * vec3(texture(material.texture_specular, TexCoords)) ;

	return (ambient + diffuse + specular);
}

vec3 calcularPointLight(PointLight light,vec3 norm, vec3 viewDir){

//valores para que la luz deje de afectar cuando esta a una distancia de 100
float constant=1.0f; //siempre uno para asegurarnos que el denominador nunca es menor que 1
float linear=0.09; //la cantidad de atenueacion segun las distancia
float quadratic=0.032; //cantidad de atenuacion segun la distancia al cuadrado

	//LUZ AMBIENTE
	vec3 ambient = light.ambiente * vec3(texture(material.texture_diffuse, TexCoords));
	
	//LUZ DIFUSA
	//vector de direccion de la luz
	vec3 lightDir = normalize(light.position - FragPos);
	//calculamos el impacto de la luz dependiendo de su angulo respecto a la normal del modelo
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = (light.difusa * diff) * vec3(texture(material.texture_diffuse, TexCoords));  
	
	//LUZ ESPECULAR
	//calculamos el vector de reflexion de la luz
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
	vec3 specular =  (spec * light.especular) * vec3(texture(material.texture_specular, TexCoords)) ; 

    // atenuacion
    float distance    = length(pointlight.position - FragPos);
    float attenuation = 1.0f / (constant + linear * distance + quadratic * (distance * distance));    
    diffuse  *= attenuation;
    specular *= attenuation;   

	return (ambient + diffuse + specular);
}


vec3 calcularFlashLight(FlashLight light,vec3 norm, vec3 viewDir){
	//valores para que la luz deje de afectar cuando esta a una distancia de 100
	float constant=1.0f; //siempre uno para asegurarnos que el denominador nunca es menor que 1
	float linear=0.09; //la cantidad de atenueacion segun las distancia
	float quadratic=0.032; //cantidad de atenuacion segun la distancia al cuadrado

    //LUZ AMBIENTE
    vec3 ambient = light.ambiente * vec3(texture(material.texture_diffuse, TexCoords));
    
   //LUZ DIFUSA   
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.difusa * diff * vec3(texture(material.texture_diffuse, TexCoords));  
    
    //LUZ ESPECULAR
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
    vec3 specular = light.especular * spec * vec3(texture(material.texture_specular, TexCoords));
    

    // para el suavizado de la luz del flash, se va interpolando desde el radio exterior hasata el radio interior
    float theta = dot(lightDir, normalize(-flashlight.direction)); 
	float epsilon = (flashlight.radioInterior - flashlight.radioExterior);
	float intensity = clamp((theta - flashlight.radioExterior) / epsilon, 0.0, 1.0);
	diffuse  *= intensity;
	specular *= intensity;


    // atenuacion
   float distance    = length(flashlight.position - FragPos);
   float attenuation = 1.0f / (constant + linear * distance + quadratic * (distance * distance));    


   diffuse  *= attenuation;
   specular *= attenuation;   
            
   return (ambient + diffuse + specular); 
}