#ifndef PACE_H
#define PACE_H

/*Да се състави клас Pace, който се състои от:

конструктор по подразбиране
конструктор приемащ минути и секунди на км
конструктор приемащ скорост в км/ч
селектор връщащ темпото в минути и секунди на км
селектор връщащ скоростта в км/ч
( 6 мин/км = 10 км/ч, 5мин/км = 12км/ч )
*/
class Pace
{
    double pace;
    double velocity;
public:
    Pace();
    ~Pace();
    Pace(double _minutes, double _seconds);
    Pace(double _velocity);
    double getPace() const;
    double getVelocity() const;
};
#endif