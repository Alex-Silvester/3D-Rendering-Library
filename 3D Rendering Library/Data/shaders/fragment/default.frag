#version 330 core

in vec3 FragPos;
in vec4 MeshColour;
in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

uniform vec4 colour;

uniform int hasTexture;
uniform sampler2D Texture;

void main()
{
    vec4 tex = texture(Texture, TexCoord);

    FragColor = MeshColour * colour * mix(vec4(1.0f), tex, hasTexture);
}