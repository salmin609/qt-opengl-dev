#include "mainwindow.h"

OpenglWindow::OpenglWindow(QWindow* parent)
    : QWindow(parent), context(nullptr)
{
    setSurfaceType(QWindow::OpenGLSurface);
}

void OpenglWindow::exposeEvent(QExposeEvent* /*event*/)
{
    RenderNow();
}

bool OpenglWindow::event(QEvent* event)
{
    switch(event->type())
    {
    case QEvent::UpdateRequest:
        RenderNow();
        break;
    default:
        return QWindow::event(event);
    }
}

void OpenglWindow::RenderLater()
{
    requestUpdate();
}

void OpenglWindow::RenderNow()
{
    if(!isExposed())
        return;

    bool needInitialize = false;

    if(context == nullptr)
    {
        context = new QOpenGLContext(this);
        context->setFormat(requestedFormat());
        context->create();

        needInitialize = true;
    }
    context->makeCurrent(this);

    if(needInitialize)
    {
        initializeOpenGLFunctions();
        Initialize();
    }

    Render();
    context->swapBuffers(this);
}
