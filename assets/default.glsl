//vertex
#version 410
layout (location = 0) in vec3 aPos;
out vec3 fPos;
uniform mat4 projection;
void main() {
    vec4 position = projection * vec4(aPos, 1.0) ;
    gl_Position = position;
    fPos = aPos;
}

//fragment
#version 410
in vec3 fPos;
out vec4 fragColor;
uniform vec3 color;
void main() {
    fragColor = vec4(color, 1.0);

}