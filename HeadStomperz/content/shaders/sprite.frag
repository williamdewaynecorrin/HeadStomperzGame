#version 330 core
in vec2 TexCoords;
out vec4 Color;

uniform sampler2D image;
uniform vec3 tint = vec3(1.0, 1.0, 1.0);
uniform float alpha = 1.0;

void main()
{
	Color = vec4 (tint, alpha) * texture(image, TexCoords);
}