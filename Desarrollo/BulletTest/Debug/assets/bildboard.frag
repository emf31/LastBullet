#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D text;

void main()
{    
    vec4 color = texture(text, TexCoords);
    if(color.a<0.1){
    	discard;
    } 
    FragColor = color;

}