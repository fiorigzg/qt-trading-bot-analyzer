#include "utils.h"
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <iostream>
#include <algorithm>


Price::Price(float start, float end, float min, float max) : start{start}, end{end}, min{min}, max{max} {}

Order::Order(size_t candle, float price, float sum) : candle{candle}, price{price}, sum{sum} {}

Portfolio::Portfolio(float usd, float othCur) : usd{usd}, othCur{othCur} {}

// returns new order with current candle
Order createOrder(Price price, size_t currentCandle)
{
    float sum = 0;
    float orderPrice = 0;

    auto now = std::chrono::high_resolution_clock::now();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
    srand(static_cast<unsigned int>(nanos));

    float randNum = ((float)std::rand() / (RAND_MAX));
    if(randNum > 0.9)
    {
        sum = -1100;
        orderPrice = price.end + randNum * 1000;
    }
    if(randNum < 0.1)
    {
        sum = 2000;
        orderPrice = price.end - randNum * 1000;
    }

    return Order(currentCandle, orderPrice, sum);
}
