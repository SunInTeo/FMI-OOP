#include <iostream>
#include "Task02\University.h"

int main()
{
    University university1, university2;

    university1.addStudent("Ivan", 88088, true);
    university1.addStudent("Pesho", 88188, true);
    university1.addStudent("Gosho", 88288, false);

    Student student1("Mario", 88488, true);
    Student student2("Alex", 88588, false);
    university2.addStudent(student1);
    university2.addStudent(student2);

    University university;
    university = university1 + university2;

    for (std::size_t i = 0; i < university.getSize(); ++i)
    {
        std::cout << "Student #" << i + 1 << ": \n";
        std::cout << university[i] << std::endl;
    }
    return 0;
}