#ifndef STUDENT_H
#define STUDENT_H

#include "grades.h"

/*
Напишете клас Student, който съдържа:

- име (собствено бащино фамилно, символен низ с точен размер);
- ЕГН (символен низ с точен размер);
- факултетен номер (6 цифри);
- оценките по 5 дисциплини (оценката да бъде структура съдържаща предмет и оценка);

Напишете следните член фунции на класа:

- изчисляване на среден успех на студента;
- печат на студента (име, ЕГН, факултетен номер, среден успех);
- печат на факултетния номер и оценките на студента;
*/
class Student
{
    char *name;
    char EGN[10];
    char facNum[6];
    Grade grades[5];

public:
    void input();
    double averageGrade();
    void printStudent();
    void printFacNumAndGrades();
    void removeStudent();
    void clean();
};

#endif