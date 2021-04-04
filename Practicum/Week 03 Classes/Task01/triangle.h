#ifndef TRIANGLE_H
#define TRIANGLE_H

/*
Напишете клас Triangle съдържащ 3 страни.
Напишете метод в класа триъгълник, който изчислява периметъра и го връща като резултат.
Напишете метод в класа триъгълник, който изчислява лицето и го връща като резултат.
*/
class Triangle
{
    double a, b, c;
    bool validate();

public:
    void input();
    double perimeter();
    double area();
};

#endif