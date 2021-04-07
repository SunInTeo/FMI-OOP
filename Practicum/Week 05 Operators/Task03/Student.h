#ifndef STUDENT_H
#define STUDENT_H

#include "Grade.h"
#include "Consts.h"

class Student
{
private:
    char *name;
    char EGN[EGN_LENGTH];
    char facultyNumber[FAC_NUMBER_LENGTH];
    Grade grades[GRADE_LENGTH];

    void deallocateMemory();
    void copy(const Student &);

public:
    Student();
    Student(const char *, const char *, const char *,
            double , double , double , double , double );
    Student(const Student &);

    Student &operator=(const Student &);
    bool operator==(const Student &);
    bool operator!=(const Student &);

    void input();
    double getAverageGrade();
    void print();
    void printFNAndGrades();

    void copyStudent(Student &);

    char *getName();
    char *getFN();

    void setName(const char *);
    void setEGN(const char *);
    void setFacultyNumber(const char *);
    void setGrades(Grade *);

    friend std::ostream &operator<<(std::ostream &, Student &);

    ~Student();
};

#endif