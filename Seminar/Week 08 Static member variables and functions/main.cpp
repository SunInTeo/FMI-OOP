#include <iostream>
#include "Task01\University.h"

int main()
{
    University university1, university2;

    university1.addStudent("Ivan", true);
    university1.addStudent("Pesho", true);
    university1.addStudent("Gosho", false);

    //Student student1("Ivan", true);
    //Student student2("Pesho", true);
    //university1.addStudent(student1);
    //university1.addStudent(student2);

    Student student3("Mario", true);
    Student student4("Alex", false);
    university2.addStudent(student3);
    university2.addStudent(student4);

    University university;
    university = university1 + university2;

    for (std::size_t i = 0; i < university.getSize(); ++i)
    {
        std::cout << "Student #" << i + 1 << ": \n";
        std::cout << university[i] << std::endl;
    }

    

    return 0;
}