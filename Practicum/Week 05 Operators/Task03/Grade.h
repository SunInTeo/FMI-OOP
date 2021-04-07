#ifndef GRADE_H
#define GRADE_H

struct Grade
{
    char *subjectName = nullptr;
    double grade = 2;

    void input();
};

#endif