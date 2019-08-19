#version 330 core
out vec4 FragColor;
in float dist;
void main()
{
    FragColor = vec4(0.25 + 0.75f * (1 - (dist * 1.5)),
                    0.305f + 0.695f * (1 - (dist * 1.5)),
                    0.36f + 0.64f * (1 - (dist * 1.5)), 1.0f);
}
