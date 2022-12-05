//vertex
#include "410"
layout (location = 0) in vec3 aPos;
out vec4 gl_Position;
int main() {
    gl_Position = (vec4(aPos, 1.0));

}

//fragment
#include "410"
in vec4 gl_Position;
out vec4 fragColor;
int main() {
    fragColor = vec4(1.0, 1.0, 1.0, 1.0);
}