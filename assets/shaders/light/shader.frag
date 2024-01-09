#version 330 core

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct PointLight {
    vec3 position;
    vec3 color;
    
    float constant;
    float linear;
    float quadratic;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

out vec4 FragColor;

#define MAX_POINT_LIGHTS 20

in vec3 position;  
in vec3 normal;
in vec2 texCoord;
  
uniform vec3 viewPos; 

uniform int numPointLights;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform Material material;

// function prototypes
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    vec3 norm = normalize(normal);
    vec3 viewDir = normalize(viewPos - position);
    
    vec3 result = vec3(0.0f, 0.0f, 0.0f);

    for(int i = 0; i < numPointLights; i++)
        result += CalcPointLight(pointLights[i], norm, position, viewDir);      
    
    FragColor = vec4(result, 1.0);
} 

// calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoord)) * light.color;
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoord)) * light.color;
    vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoord)) * light.color;
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
}