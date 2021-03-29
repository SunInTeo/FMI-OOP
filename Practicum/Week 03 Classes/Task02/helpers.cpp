#include <iostream>
#include "helpers.h"

int strlen(const char *text)
{
    int len = 0;
    while (text[len])
    {
        ++len;
    }
    return len;
}

void strcpy(char *destination, const char *source)
{
    int pos = 0;
    while (source[pos])
    {
        destination[pos] = source[pos];
        ++pos;
    }
    destination[pos] = '\0';
}