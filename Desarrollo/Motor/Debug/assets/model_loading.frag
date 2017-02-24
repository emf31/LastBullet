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
    float cutOff;
    float outerCutOff;
    float constant;
    float linear;
    float quadratic;
    
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
    
    if(theta > flashlight.cutOff) 
    {    
        // Ambient
        ambient = flashlight.lightColor*gradoLuzAmbiente * vec3(texture(material.texture_diffuse, TexCoords));
        
        // Diffuse 
        norm = normalize(Normal);        
        diff = max(dot(norm, lightDir), 0.0);
        diffuse = flashlight.lightColor * diff * vec3(texture(material.texture_diffuse, TexCoords));  
        
        // Specular
        viewDir = normalize(viewPos - FragPos);
        reflectDir = reflect(-lightDir, norm);  
        spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
        specular = flashlight.lightColor * spec * vec3(texture(material.texture_specular, TexCoords));
        

        // Spotlight (soft edges)
    	float theta = dot(lightDir, normalize(-flashlight.direction)); 
    	float epsilon = (flashlight.cutOff - flashlight.outerCutOff);
   		float intensity = clamp((theta - flashlight.outerCutOff) / epsilon, 0.0, 1.0);
    	diffuse  *= intensity;
    	specular *= intensity;


        // Attenuation
       float distance    = length(flashlight.position - FragPos);
       float attenuation = 1.0f / (flashlight.constant + flashlight.linear * distance + flashlight.quadratic * (distance * distance));    


       ambient  *= attenuation;  // Also remove attenuation from ambient, because if we move too far, the light in spotlight would then be darker than outside (since outside spotlight we have ambient lighting).
       diffuse  *= attenuation;
       specular *= attenuation;   
                
        color = vec4(ambient+diffuse + specular, 1.0f); 
        color2 = vec4(flashlight.lightColor*gradoLuzAmbiente * vec3(texture(material.texture_diffuse, TexCoords)), 1.0f); 
        if(color.x < color2.x && color.y < color2.y && color.z < color2.z){
        	color=color2;
        }
    }
    else{
    	// else, use ambient light so scene isn't completely dark outside the spotlight.
        color = vec4(flashlight.lightColor*gradoLuzAmbiente * vec3(texture(material.texture_diffuse, TexCoords)), 1.0f);
     	//color = vec4(0.30f, 1.0f , 0.30f , 1.0f);
    }    
    */
}
