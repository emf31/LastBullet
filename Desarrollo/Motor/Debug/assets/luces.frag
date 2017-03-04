#version 330 core

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

vec3 calcularLuzSolar(SunLight sun,vec3 norm, vec3 viewDir, vec3 Diffuse, float Specular);
vec3 calcularPointLight(PointLight light,vec3 norm, vec3 viewDir, vec3 Diffuse, float Specular);
vec3 calcularFlashLight(FlashLight light,vec3 norm, vec3 viewDir, vec3 Diffuse, float Specular);


out vec4 color;
in vec2 TexCoords;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gTextura;

uniform vec3 objectColor;
uniform vec3 viewPos;

//luces
uniform int num_pointlight;
uniform int num_flashlight;
uniform SunLight sunlight;
uniform FlashLight flashlight[10];
uniform PointLight pointlight[10];


void main()
{             
    // Retrieve data from gbuffer
    vec3 FragPos = texture(gPosition, TexCoords).rgb;
    vec3 Normal = texture(gNormal, TexCoords).rgb;
    vec3 Diffuse = texture(gTextura, TexCoords).rgb;
    float Specular = texture(gTextura, TexCoords).a;
    
    // Then calculate lighting as usual
    vec3 lighting  = Diffuse * 0.1; // hard-coded ambient component
    for(int i = 0; i < NR_LIGHTS; ++i)
    {
        // Diffuse
        vec3 lightDir = normalize(lights[i].Position - FragPos);
        vec3 diffuse = max(dot(Normal, lightDir), 0.0) * Diffuse * lights[i].Color;
        // Specular
        vec3 halfwayDir = normalize(lightDir + viewDir);  
        float spec = pow(max(dot(Normal, halfwayDir), 0.0), 16.0);
        vec3 specular = lights[i].Color * spec * Specular;
        // Attenuation
        float distance = length(lights[i].Position - FragPos);
        float attenuation = 1.0 / (1.0 + lights[i].Linear * distance + lights[i].Quadratic * distance * distance);
        diffuse *= attenuation;
        specular *= attenuation;
        lighting += diffuse + specular;
    }    
    FragColor = vec4(lighting, 1.0);


    vec3 colorFinal;
    //calculamos el vector vista (desde donde el observador ve el objeto)
    vec3 viewDir = normalize(viewPos - FragPos);
    //*********************************LUZ SOLAR*****************************************
    colorFinal=calcularLuzSolar(sunlight,Normal,viewDir, Diffuse, Specular );
    //*********************************POINT LIGHT*****************************************
    for(int i=0;i<num_pointlight;i++){
        colorFinal+=calcularPointLight(pointlight[i],Normal,viewDir,Diffuse,Specular);
    }
    //*********************************LUZ LINTERNA*****************************************
    for(int i=0;i<num_flashlight;i++){
    colorFinal+=calcularFlashLight(flashlight[i],Normal,viewDir,Diffuse,Specular);
    }
    color = vec4(colorFinal, 1.0);

}


vec3 calcularLuzSolar(SunLight sun,vec3 norm, vec3 viewDir, vec3 Diffuse, vec3 Specular){
        
    vec3 lightDir = normalize(-sunlight.direction);
    vec3 ambient = sunlight.ambiente * Diffuse ;
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = sunlight.difusa * diff * Diffuse; 
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
    vec3 specular =  (spec * sunlight.especular) * Specular;

    return (ambient + diffuse + specular);
}

vec3 calcularPointLight(PointLight light,vec3 norm, vec3 viewDir,vec3 Diffuse, float Specular){

//valores para que la luz deje de afectar cuando esta a una distancia de 100
float constant=1.0f; //siempre uno para asegurarnos que el denominador nunca es menor que 1
float linear=0.09; //la cantidad de atenueacion segun las distancia
float quadratic=0.032; //cantidad de atenuacion segun la distancia al cuadrado

    //LUZ AMBIENTE
    vec3 ambient = light.ambiente * Diffuse;
    
    //LUZ DIFUSA
    //vector de direccion de la luz
    vec3 lightDir = normalize(light.position - FragPos);
    //calculamos el impacto de la luz dependiendo de su angulo respecto a la normal del modelo
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = (light.difusa * diff) * Diffuse;  
    
    //LUZ ESPECULAR
    //calculamos el vector de reflexion de la luz
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
    vec3 specular =  (spec * light.especular) * Specular ; 

    // atenuacion
    float distance    = length(light.position - FragPos);
    float attenuation = 1.0f / (constant + linear * distance + quadratic * (distance * distance));    
    diffuse  *= attenuation;
    specular *= attenuation;   

    return (ambient + diffuse + specular);
}


vec3 calcularFlashLight(FlashLight light,vec3 norm, vec3 viewDir,vec3 Diffuse, float Specular){
    //valores para que la luz deje de afectar cuando esta a una distancia de 100
    float constant=1.0f; //siempre uno para asegurarnos que el denominador nunca es menor que 1
    float linear=0.09; //la cantidad de atenueacion segun las distancia
    float quadratic=0.032; //cantidad de atenuacion segun la distancia al cuadrado

    //LUZ AMBIENTE
    vec3 ambient = light.ambiente * Diffuse;
    
   //LUZ DIFUSA   
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.difusa * diff * Diffuse;  
    
    //LUZ ESPECULAR
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.brillo);
    vec3 specular = light.especular * spec * Specular;
    

    // para el suavizado de la luz del flash, se va interpolando desde el radio exterior hasata el radio interior
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = (light.radioInterior - light.radioExterior);
    float intensity = clamp((theta - light.radioExterior) / epsilon, 0.0, 1.0);
    diffuse  *= intensity;
    specular *= intensity;


    // atenuacion
   float distance    = length(light.position - FragPos);
   float attenuation = 1.0f / (constant + linear * distance + quadratic * (distance * distance));    


   diffuse  *= attenuation;
   specular *= attenuation;   
            
   return (ambient + diffuse + specular); 
}