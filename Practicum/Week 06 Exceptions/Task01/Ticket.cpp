#include <iostream>
#include <cstring>
#include "Ticket.h"

using std::cout;
using std::endl;

void Ticket::deallocate()
{
    if (this->name)
    {
        delete[] this->name;
    }

    if (this->mobileNum)
    {
        delete[] this->mobileNum;
    }
}

void Ticket::copy(const Ticket &other)
{
    try
    {
        validateName(other.name);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->name = new char[strlen(other.name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->name, other.name);

    try
    {
        validateMobileNumber(other.mobileNum);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->mobileNum = new (std::nothrow) char[strlen(other.mobileNum) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->mobileNum, other.mobileNum);

    this->uniqueClientNumber = other.uniqueClientNumber;
}

void Ticket::validateName(const char *name)
{
    if(strlen(name) < 1 && name[0] != ' ')
    {
        throw std::length_error("Name must contain more than ");
    }

    for (int i = 0; i < strlen(name) - 1; i++)
    {
        if (!(name[i] >= 'A' && name[i] <= 'Z' || name[i] >= 'a' && name[i] <= 'z' || name[i] == ' '))
        {
            throw std::invalid_argument("Invalid character(not a char).");
        }
    }
}

void Ticket::validateMobileNumber(const char *mobileNum)
{
    if (strlen(mobileNum) != 10)
    {
        throw std::length_error("Mobile number must consist of only 10 digits");
        exit(1);
    }

    for (int i = 0; i < strlen(mobileNum) - 1; i++)
    {
        if (!(mobileNum[i] >= '0' && mobileNum[i] <= '9'))
        {
            throw std::invalid_argument("Invalid character(not a number).");
        }
    }
}

Ticket::Ticket()
{
    this->name = nullptr;
    this->mobileNum = nullptr;
    this->uniqueClientNumber = 0;
}

Ticket::Ticket(const char *name, const char *mobileNum, const int uniqueClientNum)
{
    try
    {
        this->name = new char[strlen(name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->name, name);

    try
    {
        this->mobileNum = new char[strlen(mobileNum) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->mobileNum, mobileNum);

    this->uniqueClientNumber = uniqueClientNum;
}

Ticket::Ticket(const Ticket &other)
{
    copy(other);
}

Ticket::~Ticket()
{
    deallocate();
}

char *Ticket::getName() const { return this->name; }

char *Ticket::getMobileNumber() const { return this->mobileNum; }

int Ticket::getUniqueClientNumber() const { return this->uniqueClientNumber; }

void Ticket::setName(const char *name)
{
    if (this->name)
    {
        delete[] this->name;
    }
    try
    {
        validateName(name);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->name = new char[strlen(name) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    strcpy(this->name, name);
}

void Ticket::setMobileNumber(const char *mobileNum)
{
    if (this->mobileNum)
    {
        delete[] this->mobileNum;
    }

    try
    {
        validateMobileNumber(mobileNum);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->mobileNum = new char[strlen(mobileNum) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    strcpy(this->mobileNum, mobileNum);
}

void Ticket::setUniqueClientNumber(const int uniqueClientNum)
{
    this->uniqueClientNumber = uniqueClientNum;
}

Ticket &Ticket::operator=(const Ticket &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Ticket &person)
{
    out << "Name: " << person.name << endl;
    out << "Mobile number: " << person.mobileNum << endl;
    out << "Unique vlient number: " << person.uniqueClientNumber;

    return out;
}

std::istream &operator>>(std::istream &in, Ticket &ticket)
{
    char buffer[MAX_STRING_LENGTH];

    cout << "Name: ";
    in.getline(buffer, MAX_STRING_LENGTH);

    try
    {
        ticket.validateName(buffer);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        ticket.name = new char[strlen(buffer) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(ticket.name, buffer);

    cout << "Mobile number: ";
    in.getline(buffer, MAX_STRING_LENGTH);
    try
    {
        ticket.validateMobileNumber(buffer);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        ticket.mobileNum = new char[strlen(buffer) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(ticket.mobileNum, buffer);

    cout << "Unique client number: ";
    in >> ticket.uniqueClientNumber;
    in.ignore();

    return in;
}
