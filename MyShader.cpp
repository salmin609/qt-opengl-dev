#include "MyShader.h"
#include "qopenglshaderprogram.h"

MyShader::MyShader(std::string vertexPath, std::string fragmentPath)
{
    program = new QOpenGLShaderProgram();

     if (!program->addShaderFromSourceFile(
                QOpenGLShader::Vertex, vertexPath.c_str()))
    {
        qDebug() << "Vertex shader errors :\n" << program->log();
    }

    if (!program->addShaderFromSourceFile(
            QOpenGLShader::Fragment, fragmentPath.c_str()))
    {
        qDebug() << "Fragment shader errors :\n" << program->log();
    }

    if (!program->link())
        qDebug() << "Shader linker errors :\n" << program->log();
}

void MyShader::EnableVertexAttribArray(int index)
{
    program->enableAttributeArray(index);
}

void MyShader::SetAttributeBuffer(int location, GLenum type, int offset, int tupleSize, int stride)
{
    program->setAttributeBuffer(location, type, offset, tupleSize, stride);
}

MyShader::~MyShader()
{
    delete program;
}

void MyShader::Bind()
{
    program->bind();
}
