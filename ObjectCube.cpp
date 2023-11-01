#include "ObjectCube.h"
#include "MyShader.h"

std::vector<float> ObjectCube::vertices{
	-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,
		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,

		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f
};

MyShader* ObjectCube::myShader = new MyShader("/Shaders/CubeVertexShader.vert", "/Shaders/CubeFragmentShader.frag");

ObjectCube::ObjectCube()
{
	vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	vbo.create();
	vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	vbo.bind();
	vbo.allocate(vertices.size() * sizeof(float));

	vao.create();
	vao.bind();
	myShader->EnableVertexAttribArray(0);
	myShader->SetAttributeBuffer(0, GL_FLOAT, 0, 3);

	vbo.release();
	vao.release();
}

ObjectCube::~ObjectCube()
{
	delete myShader;
}

void ObjectCube::Draw()
{
	myShader->Bind();

	//need to pass GWVP


	vao.bind();
	glDrawArrays(GL_TRIANGLES, 0, 36);
	vao.release();
}
