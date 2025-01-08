#version 410 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 textura;

out vec4 modelNormal;
out vec4 modelpos;
out vec2 uv;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

void main() {
    modelpos = model * vec4(position, 1.0);
    modelNormal = (model * vec4(normal,1.0));

    gl_Position = projection * view * modelpos;
    uv = textura;
}
