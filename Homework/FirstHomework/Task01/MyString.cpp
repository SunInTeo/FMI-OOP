#include <iostream>
#include "MyString.h"

using std::cout;
using std::endl;

void MyString::copy(const MyString &rhs)
{
    reallocateMemory();
    strcpy(this->string, rhs.string);
    this->length = rhs.length;
}

void MyString::resize(int length)
{
    MyString temp(*this);

    reallocateMemory();
    strcpy(this->string, temp.c_str());
}

MyString::MyString()
{
    this->string = nullptr;
    this->length = 0;
}

MyString::MyString(const char *str)
{
    if (str == nullptr)
    {
        this->string = nullptr;
        this->length = 0;
    }
    else
    {
        this->length = strlen(str);
        this->string = new char[length + 1];
        strcpy(this->string, str);
    }
}

MyString::MyString(const MyString &rhs)
{
    this->copy(rhs);
}

MyString::~MyString()
{
    this->clear();
}

// not sure about this one
char &MyString::at(std::size_t pos)
{
    try
    {
        if (pos > 0 && pos <= strlen(this->string))
        {
            return this->string[pos - 1];
        }
        else
        {
            throw std::out_of_range("Out of range");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

//about this one either
const char &MyString::at(std::size_t pos) const
{
    try
    {
        if (pos > 0 && pos <= strlen(this->string))
        {
            return this->string[pos - 1];
        }
        else
        {
            throw std::out_of_range("Out of range");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

char &MyString::operator[](std::size_t pos) { return this->string[pos - 1]; }

const char &MyString::operator[](std::size_t pos) const { return this->string[pos - 1]; }

char &MyString::front() { return this->string[0]; }

const char &MyString::front() const { return this->string[0]; }

char &MyString::back() { return this->string[this->length]; }

const char &MyString::back() const { return this->string[this->length]; }

bool MyString::empty() const { return !this->length; }

std::size_t MyString::size() const { return this->length; }

void MyString::clear()
{
    if (this->string != nullptr)
    {
        delete[] this->string;
    }
    this->length = 0;
}

void MyString::reallocateMemory()
{
    clear();
    this->string = new char[strlen(this->string) + 1];
}

void MyString::push_back(char c)
{
    int length = strlen(this->string);

    char *buffer = new char[length + 2];

    for (int i = 0; i < length; ++i)
    {
        buffer[i] = this->string[i];
    }
    buffer[length] = c;
    buffer[length + 1] = '\0';

    *this = MyString(buffer);

    delete[] buffer;
}

void MyString::pop_back()
{
    int length = strlen(this->string);
    char *buffer = new char[length];

    for (int i = 0; i < length - 1; ++i)
    {
        buffer[i] = this->string[i];
    }

    buffer[length] = '\0';

    *this = MyString(buffer);

    delete[] buffer;
}

const char *MyString::c_str() const
{
    return this->string;
}

MyString &MyString::operator=(const MyString &rhs)
{
    clear();
    this->length = rhs.length;
    reallocateMemory();
    strcpy(this->string, rhs.string);
}

MyString &MyString::operator+=(char c)
{
    int newSize = strlen(string) + 2;
    resize(newSize);
    this->string[newSize - 1] = c;
    this->string[newSize] = '\0';
    return *this;
}

MyString &MyString::operator+=(const MyString &rhs)
{
    int newSize = strlen(this->string) + strlen(rhs.string) + 1;
    resize(newSize);
    strcat(this->string, rhs.string);
    this->string[newSize] = '\0';
    return *this;
}

MyString MyString::operator+(char c) const
{
    int newSize = 1 + this->length;

    char *buffer = new char[newSize + 1];

    for (int i = 0; i < newSize; ++i)
    {
        if (i < this->length)
        {
            buffer[i] = this->string[i];
        }
        else
        {
            buffer[i] = c;
        }
    }

    buffer[newSize] = '\0';

    MyString temp;
    temp.length = strlen(buffer);
    temp.string = new char[strlen(buffer) + 1];
    strcpy(temp.string, buffer);

    delete[] buffer;

    temp = *this;

    return *this;
}

MyString MyString::operator+(const MyString &rhs) const
{
    int newSize = rhs.length + this->length;

    char *buffer = new char[newSize + 1];

    for (int i = 0; i < newSize; ++i)
    {
        if (i < this->length)
        {
            buffer[i] = this->string[i];
        }
        else
        {
            buffer[i] = rhs.string[i];
        }
    }

    buffer[newSize] = '\0';

    MyString temp;
    temp.length = strlen(buffer);
    temp.string = new char[strlen(buffer) + 1];
    strcpy(temp.string, buffer);

    delete[] buffer;

    temp = *this;

    return *this;
}

bool MyString::operator==(const MyString &rhs) const
{
    return !strcmp(this->string, rhs.string);
}

bool MyString::operator!=(const MyString &rhs) const
{
    return !(*this == rhs);
}

// not sure about the method
bool MyString::operator<(const MyString &rhs) const
{
    return toLower(this->string) < toLower(rhs.string);
}
