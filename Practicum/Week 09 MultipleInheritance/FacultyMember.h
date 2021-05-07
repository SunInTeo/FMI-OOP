#ifndef FACULTY_MEMBER_H
#define FACULTY_MEMBER_H

#include <fstream>

#include "Student.h"
#include "Lecturer.h"

class FacultyMember : public Student, public Lecturer
{

public:
    FacultyMember(std::string name, std::size_t number, std::size_t salary);

    void save(char *fileName);
    static FacultyMember read(char *fileName);
    
    void print();
};

#endif