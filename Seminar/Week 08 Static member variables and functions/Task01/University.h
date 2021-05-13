#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "..\Task01\Student.h"
#include "Consts.h"

class University
{
    Student **studentsArray;
    size_t size;
    size_t capacity;

    void copy(const University &other);
    void deallocate();
    void resize();

public:
    University();
    University(const University &other);
    ~University();

    void addStudent(const char *name, bool isEnrolled);
    void addStudent(const Student &student);

    size_t getSize() const;

    void setSubject(int facNum);

    University &operator=(const University &other);
    University operator+(const University &other);
    Student &operator[](std::size_t index);
};

#endif