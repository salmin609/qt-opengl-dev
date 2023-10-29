#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QWindow"
#include "QOpenGLFunctions"

class OpenglWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenglWindow(QWindow* parent = 0);

    virtual void Initialize() = 0;
    virtual void Render() = 0;

public slots:
    void RenderNow();
    void RenderLater();

protected:
    bool event(QEvent* event) Q_DECL_OVERRIDE;
    void exposeEvent(QExposeEvent* event) Q_DECL_OVERRIDE;

    QOpenGLContext* context;
private:

};

#endif // MAINWINDOW_H
