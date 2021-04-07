#ifndef TIME_H
#define TIME_H

class Time
{
    int hour, minute;

public:

    Time();
    Time(const int, const int);

    Time &operator=(const Time&);

    Time operator+(const Time&);              // 1

    Time &operator+=(const Time&);             // 2

    Time operator+(const int);                 // 3

    bool operator>(const Time&);               // 5

    friend Time operator+(int, const Time&);    // 4

    void print();
}; 

#endif