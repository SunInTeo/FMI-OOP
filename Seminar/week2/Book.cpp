#include <iostream>
#include <cstring>
#include "Book.h"
#include "Utils.h"

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 100;

void Book::initialize()
{
    char buffer[MAX_SIZE];

    cout << "Title: ";
    cin.getline(buffer, MAX_SIZE);
    copyStr(buffer, this->title);

    cout << "Author: ";
    cin.getline(buffer, MAX_SIZE);
    copyStr(buffer, this->author);

    cout << "Genre: ";
    cin.getline(buffer, MAX_SIZE);
    copyStr(buffer, this->genre);

    cout << "Price: ";
    cin >> this->price;

    cout << "Number of sales: ";
    cin >> this->numberOfSales;
    cin.ignore();
}

void Book::print()
{
    cout << "Title: " << this->title << endl;
    cout << "Author: " << this->author << endl;
    cout << "Genre: " << this->genre << endl;
    cout << "Price: " << this->price << endl;
    cout << "Number of sales: " << this->numberOfSales << endl;
}

void Book::freeMemory()
{
    delete[] this->title;
    delete[] this->author;
    delete[] this->genre;
}