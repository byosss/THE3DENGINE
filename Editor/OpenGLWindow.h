#include "Engine.h"
#include <QOpenGLWindow>
#include <QOpenGLContext>

class OpenGLWindow : public QOpenGLWindow 
{
public:
    OpenGLWindow();
    ~OpenGLWindow();

protected:
    void initializeGL() override;
    void paintGL() override;

private:
    Engine engine;
};
