#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "..\Task01\Student.h"

const int INITIAL_CAPACITY = 2;
const int INCREASE_STEP = 2;

class University
{
    Student **studentsArray;
    size_t size;
    size_t capacity;

    void resize();
    void copy(const University &other);
    void deallocate();

public:
    University();
    University(const University &other);
    ~University();

    void addStudent(const char *name, int facultyNumber, bool isEnrolled);
    void addStudent(const Student &student);

    size_t getSize() const;

    University &operator=(const University &other);
    University operator+(const University &other);
    Student &operator[](size_t index);
};

#endif