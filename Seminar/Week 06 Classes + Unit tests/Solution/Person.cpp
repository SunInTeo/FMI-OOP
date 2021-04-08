#include <iostream>
#include <cstring>
#include "Person.h"

using std::cout;
using std::endl;

void Person::copy(const Person &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->age = other.age;
    this->hasLicense = other.hasLicense;
}

void Person::deallocate()
{
    if (this->name)
    {
        delete[] this->name;
    }
}

Person::Person()
{
    //cout << "Initialized default value" << endl;
    this->name = nullptr;
    this->age = 0;
    this->hasLicense = false;
}

Person::Person(const char *_name, const unsigned _age, const bool _hasLicense)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
    this->age = _age;
    this->hasLicense = _hasLicense;
}

Person::Person(const Person &person)
{
    copy(person);
}

Person &Person::operator=(const Person &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }
    return *this;
}

bool Person::operator == (const Person& other) const
{
    if (!this->name || !other.name)
    {
        return this->name == other.name;
    }

    return strcmp(this->name, other.name) == 0 && this->age == other.age && 
           this->hasLicense == other.hasLicense;
}

Person::~Person()
{
    deallocate();
}

char *Person::getName() const { return this->name; }
unsigned Person::getAge() const { return this->age; }
bool Person::getHasLicense() const { return this->hasLicense; }

void Person::setName(const char *n)
{
    delete[] this->name;
    this->name = new char[strlen(n) + 1];
    strcpy(this->name, n);
}
void Person::setAge(const unsigned _age)
{
    this->age = _age;
}
void Person::setHasLicense(const bool hl)
{
    this->hasLicense = hl;
}

void Person::printInfo()
{
    cout << "name: " << ((this->name) ? this->name : "N/A") << endl;
    cout << "Age: " << this->age << endl;
    cout << "Has driving license: " << ((this->hasLicense) ? "Yes" : "No") << endl;
}






