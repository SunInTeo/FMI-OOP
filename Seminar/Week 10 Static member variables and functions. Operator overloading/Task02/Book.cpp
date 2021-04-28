#include "Book.h"

int Book::counter = 100;

void Book::copy(const Book &other)
{
    char *buffer = nullptr;

    try
    {
        buffer = new char[strlen(other.title) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(buffer, other.title);
    id = other.id;
    title = buffer;
    clientId = other.clientId;
    yearOfIssue = other.yearOfIssue;
}

void Book::deallocate()
{
    if (title)
    {
        delete[] title;
    }
}

Book::Book()
{
    title = nullptr;
    yearOfIssue = 0;
    clientId = -1;
}

Book::Book(const char *title, int yearOfIssue, int customerID)
{
    id = Book::counter++;
    clientId = customerID;
    this->title = nullptr;
    try
    {
        this->title = new char[strlen(title) + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->title, title);
    this->yearOfIssue = yearOfIssue;
}

Book::Book(const Book &other)
{
    copy(other);
}

Book::~Book()
{
    deallocate();
}

Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

bool Book::operator==(const Book &other) const
{
    return (id == other.id && !strcmp(title, other.title) && yearOfIssue == other.yearOfIssue);
}

bool Book::operator<(const Book &other) const
{
    return yearOfIssue < other.yearOfIssue;
}

bool Book::operator>(const Book &other) const
{
    return yearOfIssue > other.yearOfIssue;
}

std::ostream &operator<<(std::ostream &out, const Book &other)
{
    out << "Id: " << other.id << "\n";
    if (other.clientId != -1)
    {
        out << "Customer ID: " << other.clientId << "\n";
    }
    out << "Title: " << other.title << "\n";
    out << "Year of issue: " << other.yearOfIssue << "\n";
    return out;
}

int Book::getID() const
{
    return id;
}

int Book::getCustomerID() const
{
    return clientId;
}

void Book::setCustomerID(int customerID)
{
    clientId = customerID;
}