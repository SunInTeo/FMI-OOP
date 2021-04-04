#include <iostream>
#include "Time.h"

using std::cout;

Time::Time()
{
    this->hour = 0;
    this->minute = 0;
}

Time::Time(const int hour, const int minute)
{
    if(hour >= 0 && hour <= 23)
    {
        this->hour = hour;
    }
    else
    {
        cout << "Incorrect input :(\n";
        this->hour = 0;
    }

    if(minute >= 0 && minute <= 59)
    {
        this->minute = minute;
    }
    else
    {
        cout << "Incorrect input :(\n";
        this->minute = 0;
    }
}

Time &Time::operator=(const Time& other)
{
    if(this != &other) 
    {
        this->hour = other.hour;
        this->minute = other.minute;
    }

    return *this;
}

// 1
Time Time::operator+(const Time &other)
{
    Time temp(this->hour + other.hour, this->minute + other.minute);
    return temp;
} 

// 2
Time &Time::operator+=(const Time &other)
{
    int thisMinutes = this->hour * 60 + this->minute;
    int otherMinutes = other.hour * 60 + other.minute;

    thisMinutes += otherMinutes;

    if(thisMinutes > 24 * 60)
    {
        thisMinutes -= 24*60;
    }

    this->hour = thisMinutes / 60;
    this->minute = thisMinutes % 60;

    return *this;
}

// 3
Time Time::operator+(const int hours)
{
    Time result;
    result.hour = (hour + hours) % 24;
    result.minute = minute % 60; 
    return result;
}

// 4
Time operator+(int hours, const Time &other)
{
    Time result(other.hour + hours, other.minute);

    return result;
}

// 5
bool Time::operator>(const Time &other)
{
    int minutes1 = this->hour * 60 + this->minute;
    int minutes2 = other.hour * 60 + other.minute;

    return minutes1 > minutes2;
}

void Time::print()
{
    cout << this->hour << ":" << this->minute;
}