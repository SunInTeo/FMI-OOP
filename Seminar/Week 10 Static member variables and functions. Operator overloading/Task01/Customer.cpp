#include "Customer.h"

int Customer::counter = 100;

void Customer::copy(const Customer &other)
{
    char *buffer = nullptr;

    try
    {
        buffer = new char[strlen(other.name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(buffer, other.name);
    name = buffer;

    age = other.age;
    id = other.id;
}
void Customer::deallocate()
{
    if (name)
    {
        delete[] name;
    }
}
Customer::Customer()
{
    id = -1;
    name = nullptr;
    age = 0;
}
Customer::Customer(const char *name, int age)
{
    id = Customer::counter++;
    this->name = nullptr;
    try
    {
        this->name = new char[strlen(name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->name, name);
    this->age = age;
}
Customer::Customer(const Customer &other)
{
    copy(other);
}
Customer::~Customer()
{
    deallocate();
}
Customer &Customer::operator=(const Customer &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

bool Customer::operator==(const Customer &other) const
{
    return (id == other.id && age == other.age && !strcmp(name, other.name));
}

bool Customer::operator<(const Customer &other) const
{
    return age < other.age;
}

bool Customer::operator>(const Customer &other) const
{
    return age > other.age;
}

std::ostream &operator<<(std::ostream &out, const Customer &other)
{
    out << "Id: " << other.id << "\n";
    out << "Name: " << other.name << "\n";
    out << "Age: " << other.age << "\n";
    return out;
}

int Customer::getID() const
{
    return id;
}