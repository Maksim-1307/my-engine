#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 out_color;

void main(){
    out_color = color;
    vec4 vertex = projection * view * model * vec4(position.x, position.y, position.z, 1.0f);
    gl_Position = vertex;
}