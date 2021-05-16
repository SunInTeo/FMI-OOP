#include "Human.h"

Human::Human(std::string name, std::string family, unsigned int age)
{
    this->name = name;
    this->family = family;
    this->age = age;
}

void Human::print()
{
    cout << "Name: " << name << endl;
    cout << "Family: " << family << endl;
    cout << "Age: " << age << endl;
}