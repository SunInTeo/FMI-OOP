#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <assert.h>
#include "..\Header files\Helpers.h"

class MyString
{
    char *str = nullptr;

    void copy(const MyString &rhs);
    void clear();
    void reallocateMemory();

public:
    MyString(); 
    MyString(const char *str); 
    MyString(const MyString &rhs);
    ~MyString();

    char &at(std::size_t pos); 
    const char &at(std::size_t pos) const; 

    char &operator[](std::size_t pos);             
    const char &operator[](std::size_t pos) const; 

    char &front();             
    const char &front() const; 

    char &back();             
    const char &back() const; 

    bool empty() const; 

    std::size_t size() const; 

    void push_back(char c); 
    void pop_back();                              

    const char *c_str() const; 

    MyString &operator=(const MyString &rhs); 
    MyString &operator+=(char c);              
    MyString &operator+=(const MyString &rhs); 
    MyString operator+(char c) const;
    MyString operator+(const MyString &rhs) const;

    bool operator==(const MyString &rhs) const; 
    bool operator!=(const MyString &rhs) const; 
    bool operator<(const MyString &rhs) const; 

};

#endif