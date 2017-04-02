#version 330 core
out vec4 FragColor;
in vec2 TexCoords;

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
    float radio;
    float radioExt;

};

vec3 calcularLuzSolar(SunLight sun,vec3 norm, vec3 viewDir,vec3 FragPos, vec3 Diffuse, float Specular);
vec3 calcularPointLight(PointLight light,vec3 norm, vec3 viewDir,vec3 FragPos, vec3 Diffuse, float Specular);
vec3 calcularFlashLight(FlashLight light,vec3 norm, vec3 viewDir,vec3 FragPos, vec3 Diffuse, float Specular);

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gTextura;
uniform sampler2D gTangent;
uniform sampler2D gBitangent;
uniform sampler2D gEmisivo;
uniform sampler2D gObjectColor;
uniform sampler2D gBloom;

uniform vec3 objectColor;
uniform vec3 viewPos;

uniform int draw_mode;

//luces
uniform int num_pointlight;
uniform int num_flashlight;
uniform SunLight sunlight;
uniform FlashLight flashlight[10];
uniform PointLight pointlight[10];


void main()
{             
    // Retrieve data from gbuffer
    //TexCoords = gCoords.rg;
    const float gamma = 0.4;
    const float exposure = 3.2;
    vec3 FragPos = texture(gPosition, TexCoords).rgb;
    vec3 Normal = texture(gNormal, TexCoords).rgb;
    vec3 Diffuse;
    Diffuse.r = texture(gTextura, TexCoords).r;
    Diffuse.g = texture(gTextura, TexCoords).g;
    Diffuse.b = texture(gTextura, TexCoords).b;
    float Specular = texture(gTextura, TexCoords).a;
    vec3 emissive = texture(gEmisivo, TexCoords).rgb;
    vec3 modelColor = texture(gObjectColor, TexCoords).rgb;
    vec3 bloom = texture(gBloom, TexCoords).rgb;
    
        vec3 colorFinal;
    //calculamos el vector vista (desde donde el observador ve el objeto)
    vec3 viewDir = normalize(viewPos - FragPos);
    //*********************************LUZ SOLAR*****************************************
   colorFinal=calcularLuzSolar(sunlight,Normal,viewDir,FragPos, Diffuse, Specular );
    //*********************************POINT LIGHT*****************************************
    for(int i=0;i<num_pointlight;i++){
        float distancia = length(pointlight[i].position - FragPos);
        if(distancia<=pointlight[i].radioExt)
       colorFinal+=calcularPointLight(pointlight[i],Normal,viewDir,FragPos,Diffuse,Specular);
    }
    //*********************************LUZ LINTERNA*****************************************
    for(int i=0;i<num_flashlight;i++){
       colorFinal+=calcularFlashLight(flashlight[i],Normal,viewDir,FragPos,Diffuse,Specular);
        
    }


    //colorFinal += emissive;
    //colorFinal = colorFinal * modelColor;

    //vec3 result = vec3(1.0) - exp(-colorFinal * exposure);
           
    //result = pow(result, vec3(1.0 / gamma));
    //colorFinal = result;



    colorFinal += bloom;
    if(draw_mode == 1)
        FragColor = vec4(colorFinal, 1.0);
    else if(draw_mode == 2)
        FragColor = vec4(FragPos, 1.0);
    else if(draw_mode == 3)
        FragColor = vec4(Normal, 1.0);
    else if(draw_mode == 4)
        FragColor = vec4(bloom, 1.0);
    else if(draw_mode == 5)
        FragColor = vec4(vec3(Specular), 1.0);


    //FragColor = vec4(0.35f,1.0f,0.9f, 1.0)* vec4(FragPos, 1.0);
    

}


vec3 calcularLuzSolar(SunLight sun,vec3 norm, vec3 viewDir,vec3 FragPos, vec3 Diffuse, float Specular){
        
    vec3 lightDir = normalize(-sunlight.direction);
    vec3 ambient = sunlight.ambiente * Diffuse ;
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = sunlight.difusa * diff * Diffuse; 
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16.0f);
    vec3 specular =  (spec * sunlight.especular) * Specular;

    return (ambient + diffuse + specular);
}

vec3 calcularPointLight(PointLight light,vec3 norm, vec3 viewDir,vec3 FragPos,vec3 Diffuse, float Specular){

//valores para que la luz deje de afectar cuando esta a una distancia de 100
float constant=1.0f; //siempre uno para asegurarnos que el denominador nunca es menor que 1
float linear=0.05; //la cantidad de atenueacion segun las distancia
float quadratic=0.015; //cantidad de atenuacion segun la distancia al cuadrado

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
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128.0f);
    vec3 specular =  (spec * light.especular) * Specular ; 

    // atenuacion
    float distance    = length(light.position - FragPos);
    float miatenuacion ;
    float attenuation = 1.0f / (constant + linear * distance + quadratic * (distance * distance));
    //ambient *= attenuation;
  // diffuse  *= attenuation;
    //specular *= attenuation;   


    if(distance>light.radio){
        miatenuacion = (distance-light.radio)*0.15;
        ambient -= miatenuacion;

        diffuse  -= miatenuacion;
        specular -= miatenuacion;  
        if(ambient.x<0.0f) ambient.x=0.f;
        if(ambient.y<0.0f) ambient.y=0.f;
        if(ambient.z<0.0f) ambient.z=0.f;
        if(diffuse.x<0.0f) diffuse.x=0.f;
        if(diffuse.y<0.0f) diffuse.y=0.f;
        if(diffuse.z<0.0f) diffuse.z=0.f;
        if(specular.x<0.0f) specular.x=0.f;
        if(specular.y<0.0f) specular.y=0.f;
        if(specular.z<0.0f) specular.z=0.f;
    }

    return (ambient + diffuse + specular);
}


vec3 calcularFlashLight(FlashLight light,vec3 norm, vec3 viewDir,vec3 FragPos,vec3 Diffuse, float Specular){
    //valores para que la luz deje de afectar cuando esta a una distancia de 100
    float constant=1.0f; //siempre uno para asegurarnos que el denominador nunca es menor que 1
    float linear=0.005; //la cantidad de atenueacion segun las distancia
    float quadratic=0.0001; //cantidad de atenuacion segun la distancia al cuadrado
    vec3 colorF=vec3(0.0f,0.0f,0.0f);

     vec3 lightDir = normalize(light.position - FragPos);
    float theta = dot(lightDir, normalize(-light.direction)); 
    if(theta > light.radioExterior) {
    //LUZ AMBIENTE
        vec3 ambient = light.ambiente * Diffuse;
        
       //LUZ DIFUSA   
       
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = light.difusa * diff * Diffuse;  
        
        //LUZ ESPECULAR
        vec3 reflectDir = reflect(-lightDir, norm);  
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128.0f);
        vec3 specular = light.especular * spec * Specular;
        

        // para el suavizado de la luz del flash, se va interpolando desde el radio exterior hasata el radio interior
        
        float epsilon = (light.radioInterior - light.radioExterior);
        float intensity = clamp((theta - light.radioExterior) / epsilon, 0.0, 1.0);
        ambient  *= intensity;
        diffuse  *= intensity;
        specular *= intensity;


        // atenuacion
       float distance    = length(light.position - FragPos);
       float attenuation = 1.0f / (constant + linear * distance + quadratic * (distance * distance));    

        ambient  *= attenuation;
       diffuse  *= attenuation;
       specular *= attenuation;   

        colorF = (ambient + diffuse + specular);

      
        
    }
        return colorF;
   


}