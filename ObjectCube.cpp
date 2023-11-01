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

//MyShader* ObjectCube::myShader = new MyShader("/Shaders/CubeVertexShader.vert", "/Shaders/CubeFragmentShader.frag");

ObjectCube::ObjectCube()
{
	myShader = new MyShader("shaders/CubeVertexShader.vert", "shaders/CubeFragmentShader.frag");

	gWVPlocation = myShader->GetUniformLocation("gWVP");

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
	vbo.destroy();
	vao.destroy();
}

void ObjectCube::Draw(const QMatrix4x4& gWVP)
{
	myShader->Bind();

	//need to pass GWVP


	vao.bind();
	glDrawArrays(GL_TRIANGLES, 0, 36);
	vao.release();
}
