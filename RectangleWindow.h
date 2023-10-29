#pragma once

#include "qopenglwindow.h"
#include "qopenglvertexarrayobject.h"
#include "qopenglbuffer.h"


class MyShader;

class RectangleWindow : public QOpenGLWindow
{
public:
    RectangleWindow();
    ~RectangleWindow();

    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
private:
    MyShader* myShader;
    QOpenGLVertexArrayObject	vao;
    QOpenGLBuffer				vbo;
    QOpenGLBuffer				ibo;
};
