#version 330 core

in vec3 frag_Position;  // Fragment position in world space
in vec3 frag_Normal;    // Normal vector in world space
in vec4 frag_Color;     // Color from the vertex shader

out vec4 out_Color;     // Final color output

uniform vec3 light_Position;  // Position of the light source
uniform vec3 view_Position;   // Position of the camera/viewer
uniform vec3 light_Color;     // Light color
uniform float ambient_Strength; // Ambient light intensity
uniform float specular_Strength; // Specular highlight intensity
uniform int shininess;        // Shininess factor for specular reflection

void main()
{
  // Normalize the normal vector
  vec3 normal = normalize(frag_Normal);

  // Calculate the ambient component
  vec3 ambient = ambient_Strength * light_Color;

  // Calculate the diffuse component
  vec3 light_Dir = normalize(light_Position - frag_Position);
  float diff = max(dot(normal, light_Dir), 0.0);
  vec3 diffuse = diff * light_Color;

  // Calculate the specular component
  vec3 view_Dir = normalize(view_Position - frag_Position);
  vec3 reflect_Dir = reflect(-light_Dir, normal);
  float spec = pow(max(dot(view_Dir, reflect_Dir), 0.0), shininess);
  vec3 specular = specular_Strength * spec * light_Color;

  // Combine all lighting components
  vec3 lighting = ambient + diffuse + specular;

  // Apply lighting to the base color
  vec3 final_Color = lighting * frag_Color.rgb;

  // Output the final color
  out_Color = vec4(final_Color, frag_Color.a);
}