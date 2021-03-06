#version 460
#extension GL_EXT_ray_tracing : enable
#extension GL_GOOGLE_include_directive : enable

#include "raycommon.glsl"

layout(location = 0) rayPayloadInEXT hitPayload prd;

layout (set = 0, binding = 10) uniform sampler2D[] skybox;

#define PI 3.141592

void main()
{
    vec3 dir            = normalize(gl_WorldRayDirectionEXT);
    vec2 uv             = vec2(0.5 + atan(dir.x, dir.z) / (2 * PI), 0.5 - asin(dir.y) / PI);
    vec3 color          = pow(texture(skybox[0], uv).xyz, vec3(2.2));
    prd.colorAndDist    = vec4(color, -1);
}