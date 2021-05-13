#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
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
    Student(const char *name, bool isEnrolled);
    Student(const Student &other);
    ~Student();

    int getFacultyNumber() const;
    bool getEnrollment() const;

    void setEnrollment();

    Student &operator=(const Student &other);
    friend std::ostream &operator<<(std::ostream &out, const Student &other);
};

#endif