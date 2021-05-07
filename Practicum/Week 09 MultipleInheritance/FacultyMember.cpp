#include "FacultyMember.h"

FacultyMember::FacultyMember(std::string name, std::size_t number, std::size_t salary) : Person(name), Student(name, number), Lecturer(name, salary)
{
}

void FacultyMember::print()
{
    std::cout << "Name: " << Person::getName() << std::endl;
    std::cout << "Number: " << Student::getNumber() << std::endl;
    std::cout << "Salary: " << Lecturer::getSalary() << std::endl;
}

void FacultyMember::save(char *fileName)
{
    std::ofstream out(fileName);

    out << getName() << " ";
    out << getNumber() << " ";
    out << getSalary();

    out.close();
}

FacultyMember FacultyMember::read(char *fileName)
{
    std::string name;
    std::size_t number;
    std::size_t salary;

    std::ifstream in(fileName);

    in >> name;
    in >> number;
    in >> salary;

    in.close();

    return FacultyMember(name, number, salary);
}
