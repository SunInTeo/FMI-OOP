#include <iostream>
#include "Student.h"
#include "University.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    size_t numberStudents = 3;
    Student* myStudents = new(std::nothrow) Student[3];
    if(!myStudents)
    {
        cout << "Memory problem\n";
        return -1;
    }
    Student student1("Ivan Dragoev", "0142587895", "81103", 6, 5, 5, 6, 4);
    Student student2("Stanimir Sokolov", "0145789652", "81101", 5, 6, 5, 5, 6);
    Student student3("Georgi Furnadzhiev", "0145253695", "81102", 6, 5, 6, 5, 6);
    myStudents[0] = student1;
    myStudents[1] = student2;
    myStudents[2] = student3;

    University university1;
    
    university1.createStudents(myStudents, numberStudents);

    university1.printStudents();
    university1.printSizeCapacity();

    Student student4("Ivanka Peicheva", "0145789525", "81104", 6, 5, 5, 5, 5);

    university1 += student4;

    university1.printStudents();
    university1.printSizeCapacity();

    university1 -= student3;

    university1.printStudents();
    university1.printSizeCapacity();

    Student ivan = university1[0];
    Student stanimir = university1[1];
    Student ivanka = university1[2];
    
    cout << ivan << stanimir << ivanka;

    delete[] myStudents;

    return 0;
}