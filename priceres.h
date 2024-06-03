#ifndef PRICERES_H
#define PRICERES_H

struct PricesRes
{
    PricesRes(vector<Price>, size_t);
    vector<Price> prices;
    size_t maxCandle;
};

#endif // PRICERES_H
