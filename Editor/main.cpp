#include <QApplication>
#include <QTimer>
#include "OpenGLWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    OpenGLWindow mainWindow;
    mainWindow.show();

    QSurfaceFormat format;
    format.setSwapInterval(1); // Active VSync
    QSurfaceFormat::setDefaultFormat(format);

    return app.exec();
}
