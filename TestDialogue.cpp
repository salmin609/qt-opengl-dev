#include "TestDialogue.h"
#include "QSurfaceFormat"
#include "RectangleWindow.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QPushButton"
#include "QtGlobal"

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
    format.setVersion(3, 3);

    rectWindow = new RectangleWindow(this);
    rectWindow->setFormat(format);

    QVBoxLayout* vlay = new QVBoxLayout();
    vlay->setContentsMargins(0, 0, 3, 3);
    vlay->setSpacing(0);
    vlay->addWidget(rectWindow);

    QHBoxLayout* hlay = new QHBoxLayout();
    hlay->setContentsMargins(0, 0, 3, 3);

    QPushButton* changeColorBtn = new QPushButton(tr("Change Color"), this);
    connect(changeColorBtn, &QPushButton::clicked, this, &TestDialogue::onChangeColors);

    QPushButton* changeColorAnimationBtn = new QPushButton(tr("Animate Colors"), this);
    connect(changeColorAnimationBtn, &QPushButton::clicked, this, &TestDialogue::onAnimateColors);

    QPushButton* closeBtn = new QPushButton(tr("Close"), this);
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
