#pragma once

#include "qopenglwindow.h"
#include "qopenglvertexarrayobject.h"
#include "qopenglbuffer.h"
#include "qopenglwidget.h"
#include "qopenglfunctions.h"
#include "qmatrix4x4.h"

class MyShader;
class Camera3D;
class QuadObject;
class ObjectCube;

class RectangleWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    RectangleWindow(QWidget* parent = nullptr);
    virtual ~RectangleWindow() Q_DECL_OVERRIDE;

    void UpdateScene();
    QuadObject* quadObject;
    ObjectCube* cubeObject;


protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
private:
    Camera3D* cam;
    QMatrix4x4 projMat;
};
