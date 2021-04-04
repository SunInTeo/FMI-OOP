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
struct Student
{
    const static int EGN_LENGTH = 10;
    const static int FACULTY_NUMBER_LENGTH = 6;
    const static int NUMBER_OF_SUBJECTS = 5;

    char *name;
    char *surname;
    char *family;
    char EGN[EGN_LENGTH];
    char facNum[FACULTY_NUMBER_LENGTH];
    Grade grades[NUMBER_OF_SUBJECTS];

    void input();
    void printStudent();
    void printFacNumAndGrades();
    double averageGrade();
    void clean();
};

#endif