#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 color;
layout(location=2) in vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 out_color;
out vec2 TexCoord;

void main(){
    out_color = color;
    TexCoord = texCoord;
    vec4 vertex = view * vec4(position.x, position.y, position.z, 1.0f);
    gl_Position = vertex;
}