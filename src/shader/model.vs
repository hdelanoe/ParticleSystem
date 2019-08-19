#version 330 core
layout (location = 0) in vec3 aPos;
out float dist;

uniform float mouseX;
uniform float mouseY;
uniform float mouseZ;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    dist = sqrt((mouseX - aPos.x) * (mouseX - aPos.x) +
                (mouseY - aPos.y) * (mouseY - aPos.y) +
                (mouseZ - aPos.z) * (mouseZ - aPos.z));
}
