#include <QApplication>
#include "OpenGLWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    OpenGLWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
