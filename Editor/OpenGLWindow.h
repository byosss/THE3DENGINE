#include "Engine.h"
#include <QOpenGLWindow>
#include <QOpenGLContext>
#include <thread>

class OpenGLWindow : public QOpenGLWindow 
{
public:
    OpenGLWindow();
    ~OpenGLWindow();

    
protected:
    void initializeGL() override;

private:
    Engine engine;
    std::thread engineThread;

    bool initGlad();
};
