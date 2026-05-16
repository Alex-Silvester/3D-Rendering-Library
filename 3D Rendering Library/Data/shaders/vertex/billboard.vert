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
	mat4 model_view = view * model;
	
	model_view[0][0] = 1;
	model_view[0][1] = 0;
	model_view[0][2] = 0;
	
	model_view[1][0] = 0;
	model_view[1][1] = 1; 
	model_view[1][2] = 0;
	
	model_view[2][0] = 0;
	model_view[2][1] = 0;
	model_view[2][2] = 1;
	
	FragPos = aPos;
	gl_Position = projection * model_view * vec4(aPos, 1.0);
	
	MeshColour = aColour;
}