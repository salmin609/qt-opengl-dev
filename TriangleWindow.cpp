#include "TriangleWindow.h"
#include "MyShader.h"

TriangleWindow::TriangleWindow()
{

}

TriangleWindow::~TriangleWindow()
{
    context->makeCurrent(this);
    vao.destroy();
    vbo.destroy();
    delete myShader;
}

void TriangleWindow::Initialize()
{
    myShader = new MyShader("shaders/triangleVertexShader.vert", "shaders/triangleFragmentShader.frag");

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.bind();
    vbo.allocate(vertices, sizeof(vertices));

    vao.create();
    vao.bind();

    myShader->EnableVertexAttribArray(0);
    myShader->SetAttributeBuffer(0, GL_FLOAT, 0, 3, 0);

    vbo.release();
    vao.release();
}

void TriangleWindow::Render()
{
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClearColor(0.1f, 0.1f,0.2f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    myShader->Bind();
    vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    vao.release();
}






