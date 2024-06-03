#ifndef OPENGLGRAPH_H
#define OPENGLGRAPH_H

#include "utils.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QLabel>
// #include <GL/gl.h>
// #include <GL/glu.h>

class OpenGLGraph : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OpenGLGraph(QWidget *parent = nullptr, QLabel *portfolio = nullptr);
    void switchTimer();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    void tickTimer();
    std::vector<Price> prices;
    std::vector<Order> orders;

    size_t currentCandle = 0;
    size_t maxCandle;
    float maxPrice;
    Portfolio portfolioSum = Portfolio(1000.0, 0.0);
    bool timerStarted = false;

    QLabel *portfolio;
    QTimer *timer = new QTimer(this);
};

#endif // OPENGLGRAPH_H
