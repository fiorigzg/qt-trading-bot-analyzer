#include "utils.h"
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <iostream>
#include <algorithm>


Price::Price(float start, float end, float min, float max) : start{start}, end{end}, min{min}, max{max} {}

PricesRes::PricesRes(std::vector<Price> prices, float maxPrice, size_t maxCandle) : prices{prices}, maxPrice{maxPrice}, maxCandle{maxCandle} {}

Order::Order(size_t candle, float price, float sum) : candle{candle}, price{price}, sum{sum} {}

Portfolio::Portfolio(float usd, float othCur) : usd{usd}, othCur{othCur} {}

// return PriceRes(<allPrices>, <maximum price>, <last candle num>)
PricesRes generatePrices()
{
    size_t maxCandle = 200;
    std::vector<Price> prices;

    float tempStart, start, end, min, max;
    float maxPrice = 0;
    for(size_t i = 0; i < maxCandle; ++i)
    {
        auto now = std::chrono::high_resolution_clock::now();
        auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
        srand(static_cast<unsigned int>(nanos));

        tempStart = start * (((float)std::rand() / (RAND_MAX)) * 2 - 1);
        start = end;
        end = tempStart + (((float)std::rand() / (RAND_MAX)) * 2 - 1) * 1000;

        for (size_t i = 0; i < 6; i++) {
            if(end > 0)
                break;
            end = tempStart + (((float)std::rand() / (RAND_MAX)) * 2 - 1) * 1000;
        }

        if(end < 0)
            end = 0 + ((float)std::rand() / (RAND_MAX)) * 1000;

        min = std::min(start, end) - ((float)std::rand() / (RAND_MAX)) * 100;
        max = std::max(start, end) + ((float)std::rand() / (RAND_MAX)) * 500;
        maxPrice = std::max(max, maxPrice);

        prices.push_back(Price(start, end, min, max));
    }

    return PricesRes(prices, maxPrice, maxCandle);
}

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
