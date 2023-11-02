#include "RectangleWindow.h"
#include "MyShader.h"
#include "QDebug"
#include <Camera.h>
#include "QuadObject.h"
#include "ObjectCube.h"
#include "DebugMarker.h"

RectangleWindow::RectangleWindow(QWidget* parent) :
    QOpenGLWidget(parent)
{
    setMinimumSize(600, 400);
}

RectangleWindow::~RectangleWindow()
{
    //makeCurrent();
    delete quadObject;
    delete cubeObject;
    delete cam;

}

void RectangleWindow::initializeGL()
{
    initializeOpenGLFunctions();

    // Enable depth buffer
    //glEnable(GL_DEPTH_TEST);
    // Enable back face culling
    //glEnable(GL_CULL_FACE);

    cam = new Camera3D();
    quadObject = new QuadObject();
    cubeObject = new ObjectCube();
}

void RectangleWindow::paintGL()
{
    //DebugMarker::GetInstance()->DebugMark("paintGL");
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);

    quadObject->Draw();

    QMatrix4x4 camMat = cam->toMatrix();
    QMatrix4x4 pvMat = projMat * camMat;

    //cubeObject->Draw(pvMat);
}

void RectangleWindow::resizeGL(int width, int height)
{
    // Calculate aspect ratio
    qreal aspect = qreal(width) / qreal(height ? height : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;

    // Reset projection
    projMat.setToIdentity();

    // Set perspective projection
    projMat.perspective(fov, aspect, zNear, zFar);
}

void RectangleWindow::UpdateScene()
{
    quadObject->UpdateScene();
    makeCurrent();
    update();
}