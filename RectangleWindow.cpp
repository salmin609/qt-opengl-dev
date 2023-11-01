#include "RectangleWindow.h"
#include "MyShader.h"
#include "QDebug"


RectangleWindow::RectangleWindow(QWidget* parent) :
    QOpenGLWidget(parent),
    vertexColors{  QColor("#f6a509"),
                   QColor("#cb2dde"),
                   QColor("#0eeed1"),
                   QColor("#068918") },
    myShader(nullptr),
    frameCount(5000)
{
    setMinimumSize(600, 400);
}

RectangleWindow::~RectangleWindow()
{
    makeCurrent();
    vao.destroy();
    vbo.destroy();
    ibo.destroy();
    delete myShader;
}

void RectangleWindow::initializeGL()
{
    initializeOpenGLFunctions();

    myShader = new MyShader("shaders/quadVertexShader.vert", "shaders/quadFragmentShader.frag");

    float vertices[] = {
        0.8f,  0.8f, 0.0f,  // top right
        0.8f, -0.8f, 0.0f,  // bottom right
        -0.8f, -0.8f, 0.0f,  // bottom left
        -0.8f,  0.8f, 0.0f
    };


    vertexBufferData.resize(2 * 4 * 3);

    float* dat = vertexBufferData.data();

    for(int i = 0; i < 4; ++i, dat += 6)
    {
        dat[0] = vertices[3 * i];
        dat[1] = vertices[3 * i + 1];
        dat[2] = vertices[3 * i + 2];

        dat[3] = vertexColors[i].redF();
        dat[4] = vertexColors[i].greenF();
        dat[5] = vertexColors[i].blueF();
    }

    vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.bind();

    vbo.allocate(vertexBufferData.data(), vertexBufferData.size() * sizeof(float));

    vao.create();
    vao.bind();

    int stride = 6 * sizeof(float);
    int colorOffset = 3 * sizeof(float);

    myShader->EnableVertexAttribArray(0);
    myShader->SetAttributeBuffer(0, GL_FLOAT, 0, 3, stride);
    myShader->EnableVertexAttribArray(1);
    myShader->SetAttributeBuffer(1, GL_FLOAT, colorOffset, 3, stride);

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    ibo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    ibo.create();
    ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    ibo.bind();
    ibo.allocate(indices, sizeof(indices));

    vbo.release();
    vao.release();

}

void RectangleWindow::paintGL()
{
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);

    myShader->Bind();
    vao.bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    vao.release();

    Animate();
}

void RectangleWindow::UpdateScene()
{
    float* dat = vertexBufferData.data();

    for(int i = 0; i < 4; ++i, dat += 6)
    {
        dat[3] = vertexColors[i].redF();
        dat[4] = vertexColors[i].greenF();
        dat[5] = vertexColors[i].blueF();
    }

    makeCurrent();

    vbo.bind();
    vbo.allocate(vertexBufferData.data(), vertexBufferData.size() * sizeof(float));

    update();
}

void RectangleWindow::AnimateColorsTo(const std::vector<QColor>& toColor)
{
    fromColors = vertexColors;
    toColors = toColor;
    frameCount = 0;

    Animate();
}

void RectangleWindow::Animate()
{
    const unsigned frame = 1200;

    if(frameCount++ > frame)
        return;

    double alpha = double(frameCount) / frame;

    int vertexColorsSize = vertexColors.size();

    for(int i = 0; i < vertexColorsSize; ++i)
    {
        double fromH, fromS, fromV;
        fromColors[i].getHsvF((float*)&fromH, (float*)&fromS, (float*)&fromV);
        qDebug() << fromColors[i];
        double toH, toS, toV;
        toColors[i].getHsvF((float*)&toH, (float*)&toS, (float*)&toV);

        vertexColors[i] = QColor::fromHsvF(toH * alpha + fromH * (1 - alpha),
                                           toS * alpha + fromS * (1 - alpha),
                                           toV * alpha + fromV * (1 - alpha));
    }

    UpdateScene();
}
