#version 330 core

struct Material {
	sampler2D texture_diffuse;
    sampler2D texture_specular;
	sampler2D texture_normal;
    float brillo;
}; 

struct SunLight {

vec3 lightColor;
vec3 direction;
}; 

struct FlashLight {
    vec3  position;
    vec3  direction;
    vec3 lightColor;
    float radioInterior;
    float radioExterior;
};  

struct PointLight {
    vec3  position;
    vec3 lightColor;
};


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
	
vec3 lightDir;
vec3 ambient;
vec3 norm;
vec3 diffuse;
vec4 color2;
float diff;
vec3 viewDir;
vec3 reflectDir;
float spec;
vec3 specular;
float gradoLuzAmbiente = 0.2f;

//valores para que la luz deje de afectar cuando esta a una distancia de 100
float constant=1.0f; //siempre uno para asegurarnos que el denominador nunca es menor que 1
float linear=0.09; //la cantidad de atenueacion segun las distancia
float quadratic=0.032; //cantidad de atenuacion segun la distancia al cuadrado

//*********************************POINT LIGHT*****************************************

	//LUZ AMBIENTE
	//vec3 ambient=lightColor*gradoLuzAmbiente;
	ambient = (pointlight.lightColor*gradoLuzAmbiente) * vec3(texture(material.texture_diffuse, TexCoords));
	
	//LUZ DIFUSA
	//vector normal desde el modelo
	norm = normalize(Normal);
	//vector de direccion de la luz
	lightDir = normalize(pointlight.position - FragPos);
	//calculamos el impacto de la luz dependiendo de su angulo respecto a la normal del modelo
	diff = max(dot(norm, lightDir), 0.0);
	//vec3 diffuse = diff * lightColor;
	diffuse = (pointlight.lightColor * diff) * vec3(texture(material.texture_diffuse, TexCoords));  
	
	//LUZ ESPECULAR
	//calculamos el vector vista (desde donde el observador ve el objeto) y el vector de reflexion de la luz
	viewDir = normalize(viewPos - FragPos);
	reflectDir = reflect(-lightDir, norm);
	
	//calculamos la luz especular, el 32 es la intensidad del brillo, cuando mas grande sea mas concentrado va a ser el brillo, se vera como un punto brillante
	spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
	specular =  (spec * pointlight.lightColor) * vec3(texture(material.texture_specular, TexCoords)) ; 

    // atenuacion
    float distance    = length(pointlight.position - FragPos);
    float attenuation = 1.0f / (constant + linear * distance + quadratic * (distance * distance));    
    diffuse  *= attenuation;
    specular *= attenuation;   

	color = vec4((ambient + diffuse + specular) * objectColor, 1.0f);


//*********************************LUZ SOLAR*****************************************
/*
	norm = normalize(Normal);
	lightDir = normalize(-sunlight.direction);
	ambient = (sunlight.lightColor*gradoLuzAmbiente) * vec3(texture(material.texture_diffuse, TexCoords));
	diff = max(dot(norm, lightDir), 0.0);
	diffuse = (lightColor*0.5) * diff * vec3(texture(material.texture_diffuse, TexCoords)); 
	viewDir = normalize(viewPos - FragPos);
	reflectDir = reflect(-lightDir, norm);
	spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
	specular =  (spec * sunlight.lightColor) * vec3(texture(material.texture_specular, TexCoords)) ;
	
	
    //color = vec4(texture(material.texture_diffuse, TexCoords));
	color = vec4((ambient + diffuse + specular) * objectColor, 1.0f);
*/
//*********************************LUZ LINTERNA*****************************************
/*
	lightDir = normalize(flashlight.position - FragPos);
    
    // Check if lighting is inside the spotlight cone
    float theta = dot(lightDir, normalize(-flashlight.direction)); 
    
 
        //LUZ AMBIENTE
        ambient = (flashlight.lightColor*gradoLuzAmbiente) * vec3(texture(material.texture_diffuse, TexCoords));
        
       //LUZ DIFUSA
        norm = normalize(Normal);        
        diff = max(dot(norm, lightDir), 0.0);
        diffuse = (flashlight.lightColor*0.6) * diff * vec3(texture(material.texture_diffuse, TexCoords));  
        
        //LUZ ESPECULAR
        viewDir = normalize(viewPos - FragPos);
        reflectDir = reflect(-lightDir, norm);  
        spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
        specular = flashlight.lightColor * spec * vec3(texture(material.texture_specular, TexCoords));
        

        // para el suavizado de la luz del flash, se va interpolando desde el radio exterior hasata el radio interior
    	float epsilon = (flashlight.radioInterior - flashlight.radioExterior);
   		float intensity = clamp((theta - flashlight.radioExterior) / epsilon, 0.0, 1.0);
    	diffuse  *= intensity;
    	specular *= intensity;


        // atenuacion
       distance    = length(flashlight.position - FragPos);
       attenuation = 1.0f / (constant + linear * distance + quadratic * (distance * distance));    


       diffuse  *= attenuation;
       specular *= attenuation;   
                
        color = vec4(ambient+diffuse + specular, 1.0f); 
    */
}
