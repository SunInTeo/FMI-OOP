#include <cstring>
#include "Student.h"

using std::cout;
using std::endl;

size_t Student::facNumIdentificator = 88088;

void Student::deallocateMemory()
{
    if (name)
    {
        delete[] name;
    }
}

void Student::copy(const Student &other)
{
    char *buffer;

    try
    {
        buffer = new char[strlen(other.name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    name = buffer;
    strcpy(name, other.name);

    facNum = other.facNum;
    isEnrolled = other.isEnrolled;
}

//Student::Student() : name(nullptr), facNum(), isEnrolled(false)
//{}

Student::Student(const char *name, bool isEnrolled)
{
    char *buffer;

    try
    {
        buffer = new char[strlen(name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    this->name = buffer;
    strcpy(this->name, name);

    facNum = ++facNumIdentificator;
    this->isEnrolled = isEnrolled;
}

Student::Student(const Student &other)
{
    copy(other);
}

Student::~Student()
{
    deallocateMemory();
}

int Student::getFacultyNumber() const
{
    return facNum;
}

bool Student::getEnrollment() const
{
    return isEnrolled;
}

void Student::setEnrollment()
{
    isEnrolled = true;
}

Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        deallocateMemory();
        copy(other);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Student &other)
{
    out << other.name << "{" << other.facNum << "}\n"; //"/ " << ((other.isEnrolled) ? "is enrolled":"is not enrolled") << endl;

    return out;
}