#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Lecturer.h"
#include "FacultyMember.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string name;
    std::size_t number;
    std::size_t salary;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter number: ";
    cin >> number;

    cout << "Enter salary: ";
    cin >> salary;

   FacultyMember fm1(name, number, salary);

    fm1.save("test.txt");

    FacultyMember readFM = FacultyMember::read("test.txt");

    readFM.print();

    return 0;
}