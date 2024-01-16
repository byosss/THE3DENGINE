#version 330 core

struct DirLight {
    vec3 direction;
    vec3 color;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
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

struct SpotLight {
    vec3 position;
    vec3 color;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};

out vec4 FragColor;

#define MAX_POINT_LIGHTS 5
#define MAX_DIR_LIGHTS 5
#define MAX_SPOT_LIGHTS 5

in vec3 position;  
in vec3 normal;
in vec2 texCoord;
  
uniform vec3 viewPos; 

uniform int numPointLights;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform int numDirLights;
uniform DirLight dirLights[MAX_DIR_LIGHTS];
uniform int numSpotLights;
uniform SpotLight spotLights[MAX_SPOT_LIGHTS];

uniform sampler2D ambientTexture;
uniform sampler2D diffuseTexture;
uniform sampler2D specularTexture;
uniform float shininess;

// function prototypes
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    vec3 norm = normalize(normal);
    vec3 viewDir = normalize(viewPos - position);
    
    vec3 result = vec3(0.0f, 0.0f, 0.0f);

    for(int i = 0; i < numDirLights; i++)
        result += CalcDirLight(dirLights[i], norm, viewDir);  

    for(int i = 0; i < numPointLights; i++)
        result += CalcPointLight(pointLights[i], norm, position, viewDir);

    for(int i = 0; i < numSpotLights; i++)
        result += CalcSpotLight(spotLights[i], norm, position, viewDir);     
    
    FragColor = vec4(result, 1.0);
} 

// calculates the color when using a directional light.
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    // combine results
    vec3 ambient = light.ambient * vec3(texture(ambientTexture, texCoord)) * light.color;
    vec3 diffuse = light.diffuse * diff * vec3(texture(diffuseTexture, texCoord)) * light.color;
    vec3 specular = light.specular * spec * vec3(texture(specularTexture, texCoord)) * light.color;
    return (ambient + diffuse + specular);
}

// calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient = light.ambient * vec3(texture(ambientTexture, texCoord)) * light.color;
    vec3 diffuse = light.diffuse * diff * vec3(texture(diffuseTexture, texCoord)) * light.color;
    vec3 specular = light.specular * spec * vec3(texture(specularTexture, texCoord)) * light.color;
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
}

// calculates the color when using a spot light.
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    // combine results
    vec3 ambient = light.ambient * vec3(texture(ambientTexture, texCoord)) * light.color;
    vec3 diffuse = light.diffuse * diff * vec3(texture(diffuseTexture, texCoord)) * light.color;
    vec3 specular = light.specular * spec * vec3(texture(specularTexture, texCoord)) * light.color;
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}