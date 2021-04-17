#include "..\Header files\MyString.h"

void MyString::copy(const MyString &rhs)
{
    char *buffer = new char[m_strlen(rhs.str) + 1];
    m_strcpy(buffer, rhs.str);
    str = buffer;
    length = rhs.length;
}

void MyString::clear()
{
    if (this->str)
    {
        delete[] str;
    }
    length = 0;
}

MyString::MyString()
{
    length = 0;
    str = new char[length + 1];
    str[length] = '\0';
}

MyString::MyString(const char *str)
{
    length = m_strlen(str);
    this->str = new char[length + 1];
    m_strcpy(this->str, str);
}

MyString::MyString(const MyString &rhs)
{
    copy(rhs);
}

MyString::~MyString()
{
    clear();
}

char &MyString::at(std::size_t pos)
{
    if (pos > length)
    {
        throw std::out_of_range("Invalid index");
    }

    return str[pos];
}

const char &MyString::at(std::size_t pos) const
{
    if (pos > length)
    {
        throw std::out_of_range("Invalid index");
    }

    return str[pos];
}

char &MyString::operator[](std::size_t pos)
{
    assert(pos <= length && "Position should be lesser than length");
    return str[pos];
}

const char &MyString::operator[](std::size_t pos) const
{
    assert(pos <= length && "Position should be lesser than length");
    return str[pos];
}

char &MyString::front()
{
    return str[0];
}

const char &MyString::front() const
{
    return str[0];
}

char &MyString::back()
{
    return str[length - 1];
}

const char &MyString::back() const
{
    return str[length - 1];
}

bool MyString::empty() const
{
    return !length;
}

std::size_t MyString::size() const
{
    return length;
}

void MyString::push_back(char c)
{
    char *buffer = new char[length + 2];

    if(!buffer) return;

    for (std::size_t i = 0; i < length; ++i)
    {
        buffer[i] = str[i];
    }
    buffer[length] = c;
    buffer[length + 1] = '\0';

    delete[] str;
    str = buffer;
}

void MyString::pop_back()
{
    assert(length > 0 && "Length should be greater than 0");

    --length;
    str[length] = '\0';
    //str[m_strlen(str) - 1] = '\0';
}

const char *MyString::c_str() const
{
    return str;
}

MyString &MyString::operator=(const MyString &rhs)
{
    if (this != &rhs)
    {
        copy(rhs);
    }

    return *this;
}

MyString &MyString::operator+=(char c)
{
    push_back(c);
    return *this;
}

MyString &MyString::operator+=(const MyString &rhs)
{
    std::size_t newSize = length + rhs.length;

    char *buffer = new char[newSize + 1];

    std::size_t index = 0;
    for (std::size_t i = 0; i < newSize; ++i)
    {
        if (i < length)
        {
            buffer[i] = str[i];
        }
        else
        {
            buffer[i] = rhs.str[index];
            ++index;
        }
    }
    buffer[newSize] = '\0';

    delete[] str;
    str = buffer;

    return *this;
}

MyString MyString::operator+(char c) const
{
    MyString temp;

    temp.str = str;
    temp.length = length;
    temp.push_back(c);

    return temp;
}

MyString MyString::operator+(const MyString &rhs) const
{
    MyString temp(str);

    return temp += rhs;
}

bool MyString::operator==(const MyString &rhs) const
{
    return !m_strcmp(str, rhs.str);
}

bool MyString::operator!=(const MyString &rhs) const
{
    return !(*this == rhs);
}

bool MyString::operator<(const MyString &rhs) const
{
    return m_strcmp(str, rhs.str) < 0;
}