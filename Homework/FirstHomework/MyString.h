#ifndef MY_STRING_H
#define MY_STRING_H

#include <cstddef> //size_t
#include "helpers.cpp"

class MyString
{
    char *string;
    std::size_t length;

    void copy(const MyString &rhs);
    void resize(int length);
    void clear();
    void reallocateMemory();

public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &rhs);
    ~MyString();

    char &at(std::size_t pos);
    const char &at(std::size_t pos) const;

    char &operator[](std::size_t pos); // assert
    const char &operator[](std::size_t pos) const; // assert

    char &front(); // assert
    const char &front() const; // assert

    char &back(); // assert
    const char &back() const; // assert

    bool empty() const;

    std::size_t size() const;

    void push_back(char c); // strong exception guarentee
    void pop_back(); // assert

    const char *c_str() const;

    MyString &operator=(const MyString &rhs);
    MyString &operator+=(char c); // strong exception guarentee
    MyString &operator+=(const MyString &rhs); // strong exception guarentee
    MyString operator+(char c) const;
    MyString operator+(const MyString &rhs) const;

    bool operator==(const MyString &rhs) const;
    bool operator!=(const MyString &rhs) const;
    bool operator<(const MyString &rhs) const;
};

#endif