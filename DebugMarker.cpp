#include "DebugMarker.h"

DebugMarker* DebugMarker::dMarker = nullptr;

DebugMarker::DebugMarker()
{
	exFuncs.initializeOpenGLFunctions();
}

DebugMarker::~DebugMarker()
{
	if (dMarker != nullptr)
		delete dMarker;
}

void DebugMarker::DebugMark(const char* msg)
{
	exFuncs.glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION,
		GL_DEBUG_TYPE_MARKER, 0, GL_DEBUG_SEVERITY_LOW,
		-1, msg);
}

DebugMarker* DebugMarker::GetInstance()
{
	if (dMarker == nullptr)
	{
		dMarker = new DebugMarker();
	}

	return dMarker;
}