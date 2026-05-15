#version 330 core

in vec3 FragPos;
in vec4 MeshColour;
in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

uniform vec4 colour;

void main()
{
    FragColor = MeshColour * colour;
}