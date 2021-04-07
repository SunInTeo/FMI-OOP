#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Student.h"
#include "Consts.h"
#include "Enums.h"

using sortingFunction = bool (*)(Student, Student, Order);

bool sortByName(Student, Student, Order);

bool sortByFacNum(Student, Student, Order);

bool sortByAverageGrade(Student, Student, Order);

class University
{
private:
    Student *students;
    size_t numberStudents;
    size_t capacity;

    sortingFunction getComparison(Field);

    void resize();

public:
    void createStudents(Student *, size_t);
    void sort(Field, Order);
    void printStudents();

    University &operator+=(const Student &);
    University &operator-=(const Student &);

    Student &operator[](int);

    void printSizeCapacity();
};

#endif