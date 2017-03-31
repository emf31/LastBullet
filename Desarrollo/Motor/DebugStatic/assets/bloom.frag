#version 330 core
out vec4 FragColor;
in vec2 TexCoords;

uniform sampler2D scene;
uniform sampler2D bloomBlur;

void main()
{             
    const float gamma = 2.2;
    vec3 escena = texture(scene, TexCoords).rgb;      
    vec3 bloom = texture(bloomBlur, TexCoords).rgb;
    vec3 color = escena + bloom;
    //gama correction
    /*

    hdrColor += bloomColor; // additive blending
    // tone mapping
    vec3 result = vec3(1.0) - exp(-hdrColor * exposure);
    // also gamma correct while we're at it       
    result = pow(result, vec3(1.0 / gamma));
    */
    FragColor = vec4(color, 1.0f);
    
}