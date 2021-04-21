#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student
{
    static size_t facNumIdentificator;

    char *name;
    int facNum;
    bool isEnrolled;

    void deallocateMemory();
    void copy(const Student &other);
public:
    //Student();
    Student(const char *name, const bool isEnrolled);
    Student(const Student &other);
    ~Student();

    Student &operator=(const Student &other);
    friend std::ostream &operator<<(std::ostream &out, Student &other);
};

#endif