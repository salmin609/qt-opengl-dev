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
    void SendUniformMat4x4(const QMatrix4x4& uValue, const char* uName);

private:
    QOpenGLShaderProgram* program;
};
