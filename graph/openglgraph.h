#ifndef OPENGLGRAPH_H
#define OPENGLGRAPH_H

#include "utils.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QLabel>
#include <GL/gl.h>
// #include <GL/glu.h>
#include <string>

class OpenGLGraph : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OpenGLGraph(QWidget *parent = nullptr, QLabel *portfolio = nullptr);
    void switchTimer();
    void generatePrices(std::string);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void wheelEvent(QWheelEvent *event) override;

private:
    void tickTimer();
    std::vector<Price> prices;
    std::vector<Order> orders;

    size_t currentCandle = 0;
    size_t maxCandle;
    float maxPrice;
    float minPrice;
    float candleWidth = 0.07;
    Portfolio portfolioSum = Portfolio(1000.0, 0.0);
    bool timerStarted = false;

    QLabel *portfolio;
    QTimer *timer = new QTimer(this);
};

#endif // OPENGLGRAPH_H
