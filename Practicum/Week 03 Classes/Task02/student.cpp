#include <iostream>
#include <cmath>
#include "student.h"
#include "grades.h"
#include "helpers.h"

using std::cin;
using std::cout;
using std::endl;

const int EGN_SIZE = 10;
const int FACNUMBER_SIZE = 6;
const int MAX_STRING_SIZE = 100;
const int MAX_GRADES = 5;

void Student::input()
{
    char buffer[MAX_STRING_SIZE];

    cout << "Name: ";
    cin.getline(buffer, MAX_STRING_SIZE);

    size_t size = strlen(buffer);
    this->name = new(std::nothrow) char[size+1];
    if(!name)
    {
        cout << "Memory problem\n";
        return;
    }
    strcpy(this->name, buffer);

    cout << "EGN: ";
    cin.getline(this->EGN, EGN_SIZE);

    cout << "Faculty number: ";
    cin.getline(this->facNum, FACNUMBER_SIZE);

    for(int i = 0; i < MAX_GRADES; ++i)
    {
        grades[i].addMark();
    }
}

double Student::averageGrade()
{
    
}

void Student::printStudent()
{

}   

void Student::printFacNumAndGrades()
{

}

void Student::removeStudent() 
{
    delete[] name;
}

void Student::clean() 
{
    for (int i = 0; i < MAX_GRADES; i++) {
        grades[i].removeGrade();
    }

    removeStudent();
}