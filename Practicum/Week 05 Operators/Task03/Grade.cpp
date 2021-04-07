#include <iostream>
#include <cstring>
#include "Grade.h"

using std::cin;
using std::cout;

void Grade::input()
{
    char buffer[100];

    cout << "Subject: ";
    cin.getline(buffer, 100);

    size_t size = strlen(buffer);
    this->subjectName = new (std::nothrow) char[size + 1];
    if (!subjectName)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->subjectName, buffer);
    this->subjectName[size] = '\0';

    cout << "Grade/2-6/: ";
    cin >> this->grade;
    cin.ignore();
}