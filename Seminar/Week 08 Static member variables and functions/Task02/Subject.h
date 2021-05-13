#ifndef SUBJECT_H
#define SUBJECT_H

#include "..\Task01\University.h"
#include "..\Task01\Consts.h"

class Subject
{
    static University *university;
    int *facNums;

    std::size_t size;
    std::size_t capacity;

    void copy(const Subject &other);
    void deallocate();
    void resize();

public:
    static void setUniversity(University *university);

    Subject();
    Subject(const Subject &other);
    ~Subject();

    void addFacultyNumber(int facNum);
    void printUnenrolledStudents();

    std::size_t getSize() const;

    Subject &operator=(const Subject &other);
    Student &operator[](std::size_t index);
};

#endif