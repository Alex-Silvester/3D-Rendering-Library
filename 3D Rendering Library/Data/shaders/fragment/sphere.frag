#version 330 core

in vec3 FragPos;
in vec4 MeshColour;
in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

uniform vec4 colour;

uniform float radius;
uniform float aa_dist;

float map(
    float input_val, 
    float input_start, float input_end,
    float output_start, float output_end)
{
  return 
  output_start + 
  ((output_end - output_start) / (input_end - input_start)) *
  (input_val - input_start);
}

void main()
{
    vec4 inside = vec4(0.f);

    float r_sqrd = radius * radius;

    float dist = (FragPos.x * FragPos.x + FragPos.y * FragPos.y);
    float radius_s = r_sqrd - aa_dist;

    float aa_val = map(
    clamp(dist, radius_s, radius),
    radius_s, radius,
    1.f,0.f);

    aa_val = smoothstep(0.f,1.f,aa_val);

    inside = vec4(max(abs(aa_val)*sign(r_sqrd - dist), 0.f));

    FragColor = MeshColour * colour * inside;
}