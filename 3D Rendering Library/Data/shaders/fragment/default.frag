#version 330 core

in vec3 FragPos;
in vec4 MeshColour;
in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

uniform vec4 colour;

uniform vec3 light_pos;
uniform float light_intensity;
uniform float ambient_light;
uniform vec3 obj_position;

void main()
{
    float direct_light = dot(Normal, light_pos - obj_position) * light_intensity;
    
    FragColor = MeshColour * colour * (direct_light + ambient_light);
}