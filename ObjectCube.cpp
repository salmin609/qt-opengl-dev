#include "ObjectCube.h"
#include "MyShader.h"
#include "DebugMarker.h"

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

	vao.create();
	vao.bind();

	

	vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	vbo.create();
	vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	vbo.bind();
	vbo.allocate(vertices.data(), vertices.size() * sizeof(float));

	myShader->EnableVertexAttribArray(0);
	myShader->SetAttributeBuffer(0, GL_FLOAT, 0, 3, 3);

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
	//todo
	//f.glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION,
	//	GL_DEBUG_TYPE_MARKER, 0, GL_DEBUG_SEVERITY_LOW,
	//	-1, "DRAW");
	//DebugMarker::GetInstance()->DebugMark("Draw");

	myShader->Bind();

	//need to pass GWVP

	vao.bind();
	myShader->SendUniformMat4x4(gWVP, "gWVP");
	
	glDrawArrays(GL_TRIANGLES, 0, 36);
	vao.release();
}
