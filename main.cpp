#include "TestDialogue.h"

#include <QApplication>
#include "QWidget"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TestDialogue dlg;

    dlg.setAttribute(Qt::WA_TranslucentBackground, true);
    dlg.setWindowFlag(Qt::FramelessWindowHint, true);

    dlg.show();

    return app.exec();
}
