#ifndef OPENGLGRAPH_H
#define OPENGLGRAPH_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>

class OpenGLGraph : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OpenGLGraph(QWidget *parent = nullptr);
    void switchTimer();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    float addRandomPrice();

private:
    std::vector<float> prices;
    int timerUpdatedCount = 0;
    QTimer *timer = new QTimer(this);
    bool timerStarted = false;
};

#endif // OPENGLGRAPH_H
