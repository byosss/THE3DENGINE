#include "Engine.h"
#include <QOpenGLWindow>
#include <QOpenGLContext>
#include <QTimer>

class OpenGLWindow : public QOpenGLWindow 
{
public:
    OpenGLWindow();
    ~OpenGLWindow();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    Engine engine;

    bool initGlad();
};
