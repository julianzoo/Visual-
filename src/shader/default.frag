#version 330 core

in vec4 tColor; // in == attribute
in vec3 tFragPos;
out vec4 FragColor; // out == varying

void main(void)
{
    FragColor = tColor;
}
