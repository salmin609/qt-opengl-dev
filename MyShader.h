#pragma once

#include <string>
#include "QtOpenGL"

class QOpenGLShaderProgram;


class MyShader
{
public:
    MyShader(std::string vertexPath, std::string fragmentPath);
    ~MyShader();

    void EnableVertexAttribArray(int index);
    void SetAttributeBuffer(int location, GLenum type, int offset, int tupleSize, int stride = 0);
    void Bind();

private:
    QOpenGLShaderProgram* program;
};
