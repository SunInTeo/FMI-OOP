#ifndef UTILS_H
#define UTILS_H

typedef bool (*priceFilter) (double a, double b);

bool isMoreExpensive(double a, double b);

bool isCheaper(double a, double b);

#endif