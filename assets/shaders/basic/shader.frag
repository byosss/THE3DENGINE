// language: GLSL

#version 330 core
out vec4 FragColor;  

in vec3 FragPos;
in vec3 color;
in vec3 normal;

void main()
{
    FragColor = vec4(color, 1.0);
}