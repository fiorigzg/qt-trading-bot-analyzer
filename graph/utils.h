#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <cstddef>

struct Price
{
    Price(float, float, float, float);
    float start;
    float end;
    float min;
    float max;
};

struct Order
{
    Order(size_t, float, float);
    size_t candle;
    float price;
    float sum;
};

struct Portfolio
{
    Portfolio(float, float);
    float usd;
    float othCur;
};

Order createOrder(Price, size_t);
#endif // UTILS_H
