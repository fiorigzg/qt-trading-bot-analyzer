#include "openglgraph.h"
#include "utils.h"
#include "../mainwindow.h"

#include <QTimer>
#include <QTextStream>
#include <QLabel>
#include <QString>
#include <QWheelEvent>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>


OpenGLGraph::OpenGLGraph(QWidget *parent, QLabel *portfolio, QVBoxLayout *ordersContainer)
    : QOpenGLWidget(parent), portfolio(portfolio), ordersContainer(ordersContainer)
{
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

void OpenGLGraph::generatePrices(std::string path)
{
    QTextStream out(stdout);

    std::ifstream file(path);
    size_t rowsCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
    file.seekg(std::ios::beg);
    prices.reserve(rowsCount);
    std::string line, word;

    if (file.is_open()) {
        std::getline(file, line);

        size_t newMaxCandle = 0; 
        float newMaxPrice = 0, newMinPrice = 1e8;
        prices.clear();
        orders.clear();
        
        while (std::getline(file, line)) {
            std::stringstream s(line);
            Price price = Price(0, 0, 0, 0);

            std::getline(s, word, ',');
            std::getline(s, word, ',');
            price.start = std::stof(word);
            std::getline(s, word, ',');
            price.max = std::stof(word);
            std::getline(s, word, ',');
            price.min = std::stof(word);
            std::getline(s, word, ',');
            price.end = std::stof(word);
            std::getline(s, word, ',');
            std::getline(s, word, ',');

            ++newMaxCandle;
            newMaxPrice = std::max(newMaxPrice, price.max);
            newMinPrice = std::min(newMinPrice, price.min);
            prices.push_back(price);
        }

        maxPrice = newMaxPrice;
        minPrice = newMinPrice;
        maxCandle = newMaxCandle;
        currentCandle = 0;
        
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.11, 0.13, 0.20, 1.0);

        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
}

void OpenGLGraph::initializeGL()
{
    // Open gl
    initializeOpenGLFunctions();
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&OpenGLGraph::tickTimer));

    // Prices generation
    generatePrices("../cache/main.csv");
}

void OpenGLGraph::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h); // Set the viewport to cover the entire widget
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

        QLabel *label = new QLabel(QString::number(newOrder.sum), this);
        label->setMaximumHeight(50);
        label->setAlignment(Qt::AlignCenter);
        QFont font("Arial", 14);
        label->setFont(font);

        // Set the style sheet for green background and rounded corners
        std::string backgroundColor = newOrder.sum < 0 ? "#ff304f" : "#4fdb91";
        std::string labelStyle = "background-color: " + backgroundColor + "; color: white; padding: 10px; margin-right: 8px; border: 1px solid black; border-radius: 7px;";
        label->setStyleSheet(QString::fromStdString(labelStyle));

        ordersContainer->insertWidget(0, label);
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
        float priceStart = (thisPrice.start - minPrice) / (maxPrice - minPrice) * 2 - 1;
        float priceEnd = (thisPrice.end - minPrice) / (maxPrice - minPrice) * 2 - 1;
        float priceMin = (thisPrice.min - minPrice) / (maxPrice - minPrice) * 2 - 1;
        float priceMax = (thisPrice.max - minPrice) / (maxPrice - minPrice) * 2 - 1;

        // draw candle
        if(thisPrice.end < thisPrice.start)
            glColor3f(0.31, 0.51, 0.74);
        else
            glColor3f(0.59, 0.78, 1.00);

        glBegin(GL_POLYGON);
        glVertex2f(marginRight, priceStart);
        glVertex2f(marginRight, priceEnd);
        glVertex2f(marginRight + candleWidth, priceEnd);
        glVertex2f(marginRight + candleWidth, priceStart);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(marginRight + candleWidth / 2 - 0.005, priceMin);
        glVertex2f(marginRight + candleWidth / 2 - 0.005, priceMax);
        glVertex2f(marginRight + candleWidth / 2 + 0.005, priceMax);
        glVertex2f(marginRight + candleWidth / 2 + 0.005, priceMin);
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
                glVertex2f(marginRight, priceOrder + candleWidth/2);
                glVertex2f(marginRight, priceOrder - candleWidth/2);
                glVertex2f(marginRight + candleWidth, priceOrder - candleWidth/2);
                glVertex2f(marginRight + candleWidth, priceOrder + candleWidth/2);
                glEnd();
            }
        }

        marginRight -= candleWidth + 0.02;
    }

    glFlush();
}

void OpenGLGraph::wheelEvent(QWheelEvent *event) {
    QPoint numDegrees = event->angleDelta() / 8;
    QPoint numSteps = numDegrees / 15;

    if (numSteps.y() > 0 && candleWidth < 0.2) 
    {
        candleWidth += 0.005; // Zoom in
    } 
    else if(candleWidth > 0.03) 
    {
        candleWidth -= 0.005; // Zoom out
    }
    update(); // Trigger a repaint
}