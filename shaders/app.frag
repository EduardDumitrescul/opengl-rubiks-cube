//
// ================================================
// | Grafica pe calculator                        |
// ================================================
// | Laboratorul IX - 09_02f_Shader.frag |
// =======================================
// 
//  Shaderul de fragment
//

#version 330 core

in vec3 FragPos;
in vec3 Normal;
in vec3 inLightPos;
in vec3 inViewPos;

out vec4 out_Color;

uniform vec4 color;
uniform vec3 lightColor;

uniform vec3 fogColor;  // Fog color
uniform float density;  // Fog density
uniform bool drawShadow;
void main(void)
{
  if(drawShadow == false) {
    //  Ambient;
    float ambientStrength = 0.7f;
    vec3 ambient_light = ambientStrength * lightColor;          //  ambient_light=ambientStrength*lightColor; 
    vec3 ambient_term= ambient_light * vec3(color);             //  ambient_material=objectColor;

    //  Diffuse; 
    vec3 norm = normalize(Normal);                              //  vectorul s;
    vec3 lightDir = normalize(inLightPos - FragPos);            //  vectorul L;
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse_light = lightColor;                            //  diffuse_light=lightColor;
    vec3 diffuse_term = diff * diffuse_light * vec3(color);     //  diffuse_material=objectColor;

    //  Specular;
    float specularStrength = 0.9f;
    float shininess = 32.0f;
    vec3 viewDir = normalize(inViewPos - FragPos);              //  versorul catre observator;
    vec3 reflectDir = normalize(reflect(-lightDir, norm));      //  versorul vectorului R;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular_light = specularStrength  * lightColor;       //  specular_light=specularStrength  * lightColor;
    vec3 specular_term = spec * specular_light * vec3(color);   //  specular_material=objectColor;

    //  Culoarea finala; 
    vec3 emission=vec3(0.1, 0.1, 0.1);
    //vec3 emission=vec3(1.0,0.8,0.4);
    vec3 result = emission + (ambient_term + diffuse_term + specular_term);

    float distance = length(inViewPos - FragPos);
    float fogFactor = exp(-density * density * distance * distance);
    fogFactor = clamp(fogFactor, 0.0, 1.0);
    vec3 finalColor = fogFactor * vec3(color) + (1.0 - fogFactor) * fogColor;

    out_Color = vec4(finalColor, 1);
  }
  else {
    float distance = length(inViewPos - FragPos);
    float fogFactor = exp(-density * density * distance * distance);
    fogFactor = clamp(fogFactor, 0.0, 1.0);
    vec3 finalColor = fogFactor * vec3(0, 0, 0) + (1.0 - fogFactor) * fogColor;
    out_Color = vec4(finalColor, 1);
  }
 
}