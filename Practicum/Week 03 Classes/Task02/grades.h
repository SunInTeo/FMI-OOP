#ifndef GRADES_H
#define GRADES_H

struct Grade
{
    char *subject;
    double subGrade;

    void addMark();
    void removeGrade();
};

#endif