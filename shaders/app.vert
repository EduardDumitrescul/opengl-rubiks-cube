// Shader-ul de varfuri / Vertex shader
#version 330 core

layout (location = 0) in vec4 inPosition;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

uniform vec4 color;

out vec4 exColor;

void main ()
{
   gl_Position = projection * view * model * inPosition;
   exColor = color;
}