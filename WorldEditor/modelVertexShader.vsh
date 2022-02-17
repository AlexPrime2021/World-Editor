uniform mat4 u_viewMatrix;
uniform mat4 u_projectionMatrix;
uniform mat4 u_modelMatrix;

attribute vec4 a_vertex;
attribute vec3 a_normal;
attribute vec2 a_texCoord;

void main(void)
{
    gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * a_vertex;
}
