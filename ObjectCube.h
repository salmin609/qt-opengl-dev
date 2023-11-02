#pragma once
#include <vector>
#include "qopenglbuffer.h"
#include "qopenglvertexarrayobject.h"

class MyShader;

class ObjectCube 
{
public:
	ObjectCube();
	~ObjectCube();

	void Draw(const QMatrix4x4& gWVP);

private:
	MyShader* myShader;
	static std::vector<float> vertices;
	QOpenGLBuffer vbo;
	QOpenGLVertexArrayObject vao;
};