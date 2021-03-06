#version 450
layout(location = 0) in vec2 outUV;
layout(location = 0) out vec4 fragColor;

layout(set = 0, binding = 0) uniform sampler2D finalTexture;



void main()
{
  vec2  uv    = outUV;
  float gamma = 1. / 2.2;

  vec4 color = texture(finalTexture, uv);
  vec3 rgb = color.xyz;
  rgb = max(rgb, 0.001);
  //rgb = rgb / ( rgb + vec3(1.0));
  rgb = pow(rgb, vec3(gamma));

  fragColor = vec4(rgb, color.w);
}
