//#version 330 core
//
//layout (location = 0) in vec4 in_Position;  // Vertex position (vec3 for 3D)
//layout (location = 1) in vec3 in_Normal;    // Vertex normal
//layout (location = 2) in vec4 in_Color;     // Vertex color
//
//uniform mat4 model;     // Model transformation matrix
//uniform mat4 view;      // View transformation matrix
//uniform mat4 projection; // Projection transformation matrix
//
//out vec3 frag_Position;  // Position of the fragment in world space
//out vec3 frag_Normal;    // Normal vector in world space
//out vec4 frag_Color;     // Vertex color (unchanged)
//
//void main()
//{
//   // Transform the vertex position into clip space
//   gl_Position = projection * view * model * in_Position;
//
//   // Transform the position and normal to world space
//   frag_Position = vec3(model * in_Position);
//   frag_Normal = mat3(transpose(inverse(model))) * in_Normal;
//
//   // Pass the color to the fragment shader
//   frag_Color = in_Color;
//}

// Shader-ul de varfuri / Vertex shader
#version 330 core

layout (location = 0) in vec4 in_Position;
layout (location = 1) in vec4 in_Color;

out vec4 ex_Color;

void main ()
{
   gl_Position = in_Position;
   ex_Color = in_Color;
}