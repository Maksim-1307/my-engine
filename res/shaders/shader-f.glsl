#version 330 core

in vec3 out_color;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D Texture;

void main()
{
	color = texture(Texture, TexCoord);
}