#pragma once

#include "qopenglvertexarrayobject.h"
#include "qopenglbuffer.h"

class MyShader;

class QuadObject 
{
public:
	QuadObject();
	~QuadObject();

	std::vector<QColor> vertexColors;
	void Draw();
	void UpdateScene();

private:
	QOpenGLVertexArrayObject	vao;
	QOpenGLBuffer				vbo;
	QOpenGLBuffer				ibo;
	MyShader* shader;
	std::vector<float> vertexBufferData;
	std::vector<QColor> toColors;
	std::vector<QColor> fromColors;
	unsigned frameCount;

};