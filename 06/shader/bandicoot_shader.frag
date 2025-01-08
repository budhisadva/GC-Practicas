#version 410 core

in vec4 modelNormal;
in vec4 modelpos;
in vec2 uv;

out vec4 color;

uniform sampler2D texture0;
uniform vec3 posCam;

float coef_ambiental = 0.8;
float coef_especular = 1.0;
float coef_difusa = 0.8;

vec3 posLuz = vec3(0.0, 4.5, 2.0);
vec3 matColor = vec3(1.0,0.647,0.0);
vec3 colorLuz = vec3(0.0,1.0,1.0);

float glossines = 50.0;

void main() {
    vec3 L = normalize(posLuz - modelpos.xyz);
    vec3 N = normalize( modelNormal.xyz );
    vec3 R = reflect(-L,N);
    vec3 V = normalize(posCam - modelpos.xyz);

    vec3 shadedcolor = coef_ambiental * matColor +
                  coef_difusa * matColor  * max(dot(N,L),0.0) +
                  colorLuz * coef_especular * pow(max(dot(V,R),0.0),glossines);

    vec4 texColor = texture(texture0, uv);
    color = texColor * vec4(shadedcolor, 1.0);
}
