#include "TestDialogue.h"

#include <QApplication>
#include "QWidget"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int Run(int argc, char* argv[])
{
    QApplication app(argc, argv);

    TestDialogue dlg;

    dlg.show();

    return app.exec();
}

int main(int argc, char *argv[])
{
    Run(argc, argv);
    _CrtDumpMemoryLeaks();

    return 0;
}
