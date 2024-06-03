#ifndef PRICE_H
#define PRICE_H

struct Price
{
    Price(float, float, float, float);
    float start;
    float end;
    float min;
    float max;
};

#endif // PRICE_H
