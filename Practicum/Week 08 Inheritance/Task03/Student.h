#ifndef STUDENT_H
#define STUDENT_H

#include "Human.h"

class Student : public Human
{
private:
    static unsigned int counter;
    unsigned int facNum;
    std::string specialty;

public:
    Student(std::string name, std::string family, unsigned int age, std::string specialty);

    void print();
};

#endif