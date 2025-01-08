#version 410 core

in vec4 modelNormal;
in vec4 modelpos;
in vec2 uv;

out vec4 color;

uniform sampler2D texture0;
uniform vec3 posCam;

float coef_ambiental = 0.1;
float coef_especular = 0.8;
float coef_difusa = 0.8;

vec3 posLuz1 = vec3(0.0, 5.0, -5.0);
vec3 posLuz2 = vec3(5.0, 5.0, 0.0);
vec3 posLuz3 = vec3(-5.0, 5.0, 0.0);
vec3 matColor = vec3(1.0, 1.0, 1.0);
vec3 colorLuz = vec3(1.0, 0.0, 1.0);

float glossines = 50.0;

void main() {
    vec3 N = normalize( modelNormal.xyz );
    vec3 V = normalize(posCam - modelpos.xyz);
    //
    vec3 L1 = normalize(posLuz1 - modelpos.xyz);
    vec3 R1 = reflect(-L1,N);
    vec3 shadedcolor1 = coef_ambiental * matColor +
                        coef_difusa * matColor  * max(dot(N,L1),0.0) +
                        colorLuz * coef_especular * pow(max(dot(V,R1),0.0),glossines);
    //
    vec3 L2 = normalize(posLuz2 - modelpos.xyz);
    vec3 R2 = reflect(-L2,N);
    vec3 shadedcolor2 = coef_ambiental * matColor +
                        coef_difusa * matColor  * max(dot(N,L2),0.0) +
                        colorLuz * coef_especular * pow(max(dot(V,R2),0.0),glossines);
    //
    vec3 L3 = normalize(posLuz3 - modelpos.xyz);
    vec3 R3 = reflect(-L3,N);
    vec3 shadedcolor3 = coef_ambiental * matColor +
                        coef_difusa * matColor  * max(dot(N,L3),0.0) +
                        colorLuz * coef_especular * pow(max(dot(V,R3),0.0),glossines);
    //
    vec3 shadedcolor = shadedcolor1 + shadedcolor2 + shadedcolor3;
    //
    vec4 texColor = texture(texture0, uv);
    color = texColor * vec4(shadedcolor, 1.0);
}
