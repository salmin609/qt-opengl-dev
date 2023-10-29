#pragma once

#include "mainwindow.h"
#include "qopenglvertexarrayobject.h"
#include "QOpenGLBuffer"


class MyShader;

class TriangleWindow : public OpenglWindow
{
public:
    TriangleWindow();
    ~TriangleWindow() Q_DECL_OVERRIDE;

    void Initialize() Q_DECL_OVERRIDE;
    void Render() Q_DECL_OVERRIDE;

private:
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vbo;

    MyShader* myShader;
};
