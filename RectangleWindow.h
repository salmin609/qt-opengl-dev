#pragma once

#include "qopenglwindow.h"
#include "qopenglvertexarrayobject.h"
#include "qopenglbuffer.h"
#include "qopenglwidget.h"
#include "qopenglfunctions.h"

class MyShader;
class Camera3D;

class RectangleWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    RectangleWindow(QWidget* parent = nullptr);
    virtual ~RectangleWindow() Q_DECL_OVERRIDE;

    void UpdateScene();
    void AnimateColorsTo(const std::vector<QColor>& toColor);
    std::vector<QColor> vertexColors;
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
private:

    void Animate();

    MyShader* myShader;
    QOpenGLVertexArrayObject	vao;
    QOpenGLBuffer				vbo;
    QOpenGLBuffer				ibo;
    Camera3D* cam;


    std::vector<float> vertexBufferData;
    std::vector<QColor> toColors;
    std::vector<QColor> fromColors;
    unsigned frameCount;

};
