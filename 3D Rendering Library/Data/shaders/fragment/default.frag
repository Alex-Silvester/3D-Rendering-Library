#version 330 core

in vec3 FragPos;
in vec4 MeshColour;
in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

uniform vec4 colour;

uniform int hasTexture;
uniform sampler2D Texture;

uniform vec3 lightPos;
uniform float lightIntensity;

void main()
{
    vec4 tex = texture(Texture, TexCoord);

    float light = dot(normalize(Normal), normalize(lightPos-FragPos))*lightIntensity;

    FragColor = MeshColour * colour * mix(vec4(1.0f), tex, hasTexture) * vec4(vec3(light),1.0f);
}