#include "Student.h"

unsigned int Student::counter = 40000;

Student::Student(std::string name, std::string family, unsigned int age, std::string specialty) : Human(name, family, age)
{
    facultyNumber = counter++;
    this->specialty = specialty;
}

void Student::print()
{
    Human::print();
    cout << "Faculty number: " << facultyNumber << endl;
    cout << "Specialty: " << specialty << endl;
}