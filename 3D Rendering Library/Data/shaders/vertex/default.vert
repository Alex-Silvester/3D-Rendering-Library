#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColour;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec2 aTexCoord;

out vec3 FragPos;
out vec4 Colour;
out vec3 Normal;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 Position;
uniform vec3 Scale;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Colour = aColour;
    Normal = aNormal;  
    TexCoord = aTexCoord;
	
    gl_Position = projection * view * vec4(FragPos + Position, 1.0);
} 