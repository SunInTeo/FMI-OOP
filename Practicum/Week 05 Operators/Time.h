#ifndef TIME_H
#define TIME_H

/*
Задача 1
Да се реализира клас Time, който има член-данни hour, minute от целочислен тип. 
Да се предефинират операциите събиране и присвояване за реализиране на следните видове изрази: 
// Time t1, t2, t3, t4, t5;

- t1 + t2 // 1
- t3 = t1 + t2 // 2
- t4 = t1 + 5 // 3
- t5 = 6 + t1 // 4
- t1 > t2 // 5
*/

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