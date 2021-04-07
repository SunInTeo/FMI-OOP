#include <iostream>
#include <cstring>
#include "Person.h"

using std::cout;
using std::endl;

// 1
Person::Person() 
{
    cout << "Initialized default value" << endl;
    this->name = nullptr;
    this->age = 0;
    this->hasLicense = false;
}

// 2
Person::Person(Person &p)
{
    this->name = new char[strlen(p.name) + 1];
    strcpy(this->name, p.name);
    this->age = p.age;
    this->hasLicense = p.hasLicense;   
}

// 3
Person::Person(const char* _name, const unsigned _age, const bool _hasLicense)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
    this->age = _age;
    this->hasLicense = _hasLicense;
}

// 4
Person& Person::operator = (const Person &p)
{
    //cout<<"Assignment operator called "<<endl;
    this->setName(p.name);
    this->setAge(p.age);
    this->setHasLicense(p.hasLicense);
    return *this;
}

// 5
Person::~Person()
{
    //cout << "Removed" << endl;
    delete[] this->name;
}

// 6 
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

// 7 
void Person::printInfo()
{
    cout << "Name: " << ((this->name) ? this->name:"N/A") << endl;
    cout << "Age: " << this->age << endl;
    cout << "Has driving license: " << ((this->hasLicense) ? "Yes":"No") << endl;
}
