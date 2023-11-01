#include "TestDialogue.h"
#include "QSurfaceFormat"
#include "RectangleWindow.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QPushButton"
#include "QtGlobal"
#include "ObjectCube.h"

TestDialogue::TestDialogue() :
#ifdef Q_OS_WIN
    QDialog(nullptr, Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint)
#else
    QDialog(nullptr, Qt::Window)
#endif
{
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(4, 3);

    rectWindow = new RectangleWindow(this);
    rectWindow->setFormat(format);

    cubeObject = new ObjectCube();

    vlay = new QVBoxLayout();
    vlay->setContentsMargins(0, 0, 3, 3);
    vlay->setSpacing(0);
    vlay->addWidget(rectWindow);

    hlay = new QHBoxLayout();
    hlay->setContentsMargins(0, 0, 3, 3);

    changeColorBtn = new QPushButton(tr("Change Color"), this);
    connect(changeColorBtn, &QPushButton::clicked, this, &TestDialogue::onChangeColors);

    changeColorAnimationBtn = new QPushButton(tr("Animate Colors"), this);
    connect(changeColorAnimationBtn, &QPushButton::clicked, this, &TestDialogue::onAnimateColors);

    closeBtn = new QPushButton(tr("Close"), this);
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);

    hlay->addWidget(changeColorBtn);
    hlay->addWidget(changeColorAnimationBtn);
    hlay->addStretch();
    hlay->addWidget(closeBtn);

    vlay->addLayout(hlay);
    setLayout(vlay);

    //qsrand(428);
}

TestDialogue::~TestDialogue()
{
    delete rectWindow;
    delete cubeObject;
    delete changeColorBtn;
    delete changeColorAnimationBtn;
    delete closeBtn;
    delete hlay;
    delete vlay;
}

void TestDialogue::onChangeColors()
{
    for(int i = 0; i < 4; ++i)
    {
        rectWindow->vertexColors[i].setRgbF(rand() * 1.0 / RAND_MAX, rand() * 1.0 / RAND_MAX, rand() * 1.0 / RAND_MAX);
    }

    rectWindow->UpdateScene();
}

void TestDialogue::onAnimateColors()
{
    std::vector<QColor> newColors(4);

    for(int i = 0; i < 4; ++i)
    {
        newColors[i].setRgbF(rand() * 1.0 / RAND_MAX, rand() * 1.0 / RAND_MAX, rand() * 1.0 / RAND_MAX);
    }

    rectWindow->AnimateColorsTo(newColors);
}
