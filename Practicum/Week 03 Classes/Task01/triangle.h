#ifndef TRIANGLE_H
#define TRIANGLE_H

/*
Напишете клас Triangle съдържащ 3 страни.
Напишете метод в класа триъгълник, който изчислява периметъра и го връща като резултат.
Напишете метод в класа триъгълник, който изчислява лицето и го връща като резултат.
*/
class Triangle
{
    double sideA;
    double sideB;
    double sideC;

    bool validate(double a, double b, double c);

public:
    void input();
    double perimeter();
    double area();
};

#endif