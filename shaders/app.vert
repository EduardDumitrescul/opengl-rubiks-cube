#version 330 core

layout (location = 0) in vec4 in_Position;  // Vertex position
layout (location = 1) in vec3 in_Normal;    // Vertex normal

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;


uniform vec3 lightPos;
uniform vec3 viewPos;
 //  Se preia din buffer de pe a doua pozitie (1) atributul care contine normala;

out vec3 Normal;
out vec3 FragPos;
out vec3 inLightPos;
out vec3 inViewPos;


void main(void)
{
   gl_Position = projection*view*model*vec4(in_Position);
   Normal=vec3(mat3(transpose(inverse(model))) * in_Normal);
   inLightPos= lightPos;
   inViewPos= viewPos;
   FragPos = vec3(model * in_Position);
} 

