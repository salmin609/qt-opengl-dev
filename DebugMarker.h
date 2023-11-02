#pragma once
#include <QOpenGLExtraFunctions>

class DebugMarker 
{
public:
	DebugMarker(const DebugMarker& other) = delete;
	void operator=(const DebugMarker&) = delete;
	~DebugMarker();

	void DebugMark(const char* msg);

	static DebugMarker* GetInstance();
private:
	DebugMarker();
	static DebugMarker* dMarker;

	QOpenGLExtraFunctions exFuncs;
};

