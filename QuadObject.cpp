#include "QuadObject.h"
#include "MyShader.h"


QuadObject::QuadObject() : 
    vertexColors{ QColor("#f6a509"),
                   QColor("#cb2dde"),
                   QColor("#0eeed1"),
                   QColor("#068918") },
    shader(nullptr),
    frameCount(5000)
{
    shader = new MyShader("shaders/quadVertexShader.vert", "shaders/quadFragmentShader.frag");

    float vertices[] = {
        0.8f,  0.8f, 0.0f,  // top right
        0.8f, -0.8f, 0.0f,  // bottom right
        -0.8f, -0.8f, 0.0f,  // bottom left
        -0.8f,  0.8f, 0.0f
    };

    vertexBufferData.resize(2 * 4 * 3);

    float* dat = vertexBufferData.data();

    for (int i = 0; i < 4; ++i, dat += 6)
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

    shader->EnableVertexAttribArray(0);
    shader->SetAttributeBuffer(0, GL_FLOAT, 0, 3, stride);
    shader->EnableVertexAttribArray(1);
    shader->SetAttributeBuffer(1, GL_FLOAT, colorOffset, 3, stride);

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

QuadObject::~QuadObject()
{
    vao.destroy();
    vbo.destroy();
    ibo.destroy();
    delete shader;
}

void QuadObject::Draw()
{
    shader->Bind();
    vao.bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    vao.release();
}

void QuadObject::UpdateScene()
{
    float* dat = vertexBufferData.data();

    for (int i = 0; i < 4; ++i, dat += 6)
    {
        dat[3] = vertexColors[i].redF();
        dat[4] = vertexColors[i].greenF();
        dat[5] = vertexColors[i].blueF();
    }

    vbo.bind();
    vbo.allocate(vertexBufferData.data(), vertexBufferData.size() * sizeof(float));

}
