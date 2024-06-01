#include "openglgraph.h"

#include <QTimer>
#include <QTextStream>


OpenGLGraph::OpenGLGraph(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

void OpenGLGraph::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.11, 0.13, 0.20, 1.0); // Set the clear color to black
}

void OpenGLGraph::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h); // Set the viewport to cover the entire widget
}

void OpenGLGraph::switchTimer()
{
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&OpenGLGraph::update));
    if(timerStarted == false)
    {
        timer->start(400);
    }
    else
    {
        timer->stop();
    }
    timerStarted = !timerStarted;
    QTextStream out(stdout);
    out << "Timer " << (timerStarted ? "started" : "stopped") << "\n";
}

float OpenGLGraph::addRandomPrice()
{
    auto now = std::chrono::high_resolution_clock::now();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
    srand(static_cast<unsigned int>(nanos));
    float newPrice = ((float)std::rand() / (RAND_MAX)) * 2 - 1;
    this->prices.insert(prices.begin(), newPrice);
    return newPrice;
}

void OpenGLGraph::paintGL()
{
    QTextStream out(stdout);
    out << "Updated " << this->timerUpdatedCount << "\n";
    // out << "price " << *this->prices.end() << "\n";

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.11, 0.13, 0.20, 1.0);

    float marginRight = 1;
    float lastPrice = this->addRandomPrice();
    for(const auto price : this->prices)
    {
        if(lastPrice != 3.0) {
            if(price < lastPrice)
                glColor3f(0.31, 0.51, 0.74);
            else
                glColor3f(0.59, 0.78, 1.00);

            glBegin(GL_POLYGON);
            glVertex2f(marginRight, lastPrice);
            glVertex2f(marginRight, price);
            glVertex2f(marginRight + 0.07, price);
            glVertex2f(marginRight + 0.07, lastPrice);
            glEnd();
            marginRight -= 0.09;
        }
        lastPrice = price;
    }

    glFlush();

    this->timerUpdatedCount++;
}
