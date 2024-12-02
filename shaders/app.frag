// Shader-ul de fragment / Fragment shader 
#version 330 core

in vec4 exColor;
out vec4 out_Color;

void main(void)
  {
    out_Color = exColor;
  }