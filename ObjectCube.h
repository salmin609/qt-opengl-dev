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

	void Draw();

private:
	static MyShader* myShader;
	static std::vector<float> vertices;
	QOpenGLBuffer vbo;
	QOpenGLVertexArrayObject vao;
};