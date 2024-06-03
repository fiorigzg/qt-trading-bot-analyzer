#include "openglgraph.h"
#include "utils.h"
#include "../mainwindow.h"

#include <QTimer>
#include <QTextStream>
#include <QLabel>
#include <QString>
#include <string>
#include <vector>
#include <algorithm>


OpenGLGraph::OpenGLGraph(QWidget *parent, QLabel *portfolio)
    : QOpenGLWidget(parent), portfolio(portfolio)
{
}

void OpenGLGraph::initializeGL()
{
    // Open gl
    initializeOpenGLFunctions();
    glClearColor(0.11, 0.13, 0.20, 1.0);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&OpenGLGraph::tickTimer));

    // Prices generation
    PricesRes pricesRes = generatePrices();
    prices = pricesRes.prices;
    maxCandle = pricesRes.maxCandle;
    maxPrice = pricesRes.maxPrice;
}

void OpenGLGraph::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h); // Set the viewport to cover the entire widget
}

void OpenGLGraph::switchTimer()
{
    QTextStream out(stdout);
    if(timerStarted == false)
    {
        timer->start(400);
    }
    else
    {
        timer->stop();
    }
    timerStarted = !timerStarted;

    out << "Timer " << (timerStarted ? "started" : "stopped") << "\n";
}

void OpenGLGraph::tickTimer()
{
    if(currentCandle >= maxCandle)
        return;

    QTextStream out(stdout);
    ++currentCandle;

    // orders generation
    // std::vector<Price>(prices.begin(), prices.end() - (maxCandle - currentCandle))
    Order newOrder = createOrder(prices[currentCandle], currentCandle);
    if(newOrder.sum != 0)
    {
        orders.push_back(newOrder);
        portfolioSum.usd += newOrder.sum;
        portfolioSum.othCur += newOrder.sum / newOrder.price;
        out << "Order " << newOrder.price << " " << newOrder.sum << "\n";
    }
    portfolio->setText(QString::number(portfolioSum.usd + portfolioSum.othCur * prices[currentCandle].end));

    OpenGLGraph::update();

    out << "Candle " << currentCandle << "\n";
}

void OpenGLGraph::paintGL()
{
    QTextStream out(stdout);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.11, 0.13, 0.20, 1.0);

    float marginRight = 1;
    std::vector<Price> thisPrices(prices.begin(), prices.end() - (maxCandle - currentCandle));
    std::reverse(thisPrices.begin(), thisPrices.end());

    for(size_t thisCandle = currentCandle; thisCandle != 0; --thisCandle)
    {
        Price thisPrice = prices[thisCandle];
        float priceStart = thisPrice.start / maxPrice * 2 - 1;
        float priceEnd = thisPrice.end / maxPrice * 2 - 1;
        float priceMin = thisPrice.min / maxPrice * 2 - 1;
        float priceMax = thisPrice.max / maxPrice * 2 - 1;

        // draw candle
        if(thisPrice.end < thisPrice.start)
            glColor3f(0.31, 0.51, 0.74);
        else
            glColor3f(0.59, 0.78, 1.00);

        glBegin(GL_POLYGON);
        glVertex2f(marginRight, priceStart);
        glVertex2f(marginRight, priceEnd);
        glVertex2f(marginRight + 0.07, priceEnd);
        glVertex2f(marginRight + 0.07, priceStart);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(marginRight + 0.03, priceMin);
        glVertex2f(marginRight + 0.03, priceMax);
        glVertex2f(marginRight + 0.04, priceMax);
        glVertex2f(marginRight + 0.04, priceMin);
        glEnd();

        // draw orders
        for(const auto order : orders)
        {
            if(order.candle != thisCandle)
                continue;
            else
            {
                float priceOrder = order.price / maxPrice * 2 - 1;

                if(order.sum < 0)
                    glColor3f(1.00, 0.19, 0.46);
                else
                    glColor3f(0.31, 0.86, 0.57);

                glBegin(GL_POLYGON);
                glVertex2f(marginRight, priceOrder + 0.035);
                glVertex2f(marginRight, priceOrder - 0.035);
                glVertex2f(marginRight + 0.07, priceOrder - 0.035);
                glVertex2f(marginRight + 0.07, priceOrder + 0.035);
                glEnd();
            }
        }

        marginRight -= 0.09;
    }

    glFlush();
}
