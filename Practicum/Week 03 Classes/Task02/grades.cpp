#include <iostream>
#include <cmath>
#include "grades.h"
#include "helpers.h"

using std::cin;
using std::cout;
using std::endl;

const int MAX_STRING_SIZE = 100;

void Grade::addMark()
{
    char buffer[MAX_STRING_SIZE];
    cout << "Subject: ";
    cin.getline(buffer, MAX_STRING_SIZE);

    size_t size = strlen(buffer);
    this->subject = new(std::nothrow) char[size+1];
    if(!subject)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->subject, buffer);

    cout << "Grade: ";
    cin >> this->subGrade;
    cin.ignore();
}

void Grade::removeGrade() 
{
    delete[] subject;
}