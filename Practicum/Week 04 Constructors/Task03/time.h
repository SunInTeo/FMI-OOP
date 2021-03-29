#ifndef TIME_H
#define TIME_h

/*
Да се създаде клас Time, който ще пази информация за времето (час и минути) 
в една от следните часови зони: 
New York (UTC -5), London (UTC +0), Sofia (UTC +2), Moscow (UTC +3);
и ще предоставя възможност да получава информация за времето в останалите. 
Да се приложи принципа на енкапсулацията.
*/
class Time
{
    double time;
public:
    Time(double hours, double minutes);

    
};

#endif