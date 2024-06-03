#ifndef UTILS_H
#define UTILS_H
#include <vector>

struct Price
{
    Price(float, float, float, float);
    float start;
    float end;
    float min;
    float max;
};

struct PricesRes
{
    PricesRes(std::vector<Price>, float, size_t);
    std::vector<Price> prices;
    float maxPrice;
    size_t maxCandle;
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

PricesRes generatePrices();

Order createOrder(Price, size_t);
#endif // UTILS_H
