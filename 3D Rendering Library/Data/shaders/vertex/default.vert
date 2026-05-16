#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColour;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec2 aTexCoord;

out vec3 FragPos;
out vec4 MeshColour;
out vec3 Normal;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vec4 worldPos = model * vec4(aPos, 1.0);
    FragPos = vec3(worldPos);
    MeshColour = aColour;
    Normal = aNormal;  
    TexCoord = aTexCoord;
	
    gl_Position = projection * view * worldPos;
}