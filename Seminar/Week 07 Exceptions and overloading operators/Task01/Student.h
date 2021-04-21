#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

/*Направете клас Student, който има следните данни: име, факултетен номер и булева променлива, 
индикираща дали студента е записал някаква дисциплина. 
    Да се напишат:

- метод, който принтира името и номера на студента;*/
class Student
{
    char *name;
    int facNum;
    bool isEnrolled;

    void deallocateMemory();
    void copy(const Student &other);
public:
    //Student();
    Student(const char *name, int facNum, const bool isEnrolled);
    Student(const Student &other);
    ~Student();

    Student &operator=(const Student &other);
    friend std::ostream &operator<<(std::ostream &out, Student &other);
};

#endif