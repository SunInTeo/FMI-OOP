#include <iostream>
#include <cstring>
#include "Book.h"

using std::cin;
using std::cout;
using std::endl;

const int SIZE = 100;

void Book::initialize() {

	char buffer[SIZE];
	size_t size = 0;

	cout << "Title: ";
	cin.getline(buffer, SIZE);
	size = strlen(buffer);
	this->title = new(std::nothrow) char[size + 1];
	if (!this->title)
    {
        cout << "Memory problem!" << endl;
        return;
    }
	strcpy(this->title, buffer);
	title[size] = '\0';

	cout << "Author: ";
	cin.getline(buffer, SIZE);
	size = strlen(buffer);
	this->author = new(std::nothrow) char[size + 1];
	if (!this->author)
    {
        cout << "Memory problem!" << endl;
        return;
    }
	strcpy(this->author, buffer);
	author[size] = '\0';

	cout << "Genre: ";
	cin.getline(buffer, SIZE);
	size = strlen(buffer);
	this->genre = new(std::nothrow) char[size + 1];
	if (!this->genre)
    {
        cout << "Memory problem!" << endl;
        return;
    }
	strcpy(this->genre, buffer);
	genre[size] = '\0';

	cout << "Price: ";
	cin >> this->price;
	
	cout << "Sales: ";
	cin >> this->numberOfSales;
	
	cout << "Rating: ";
	cin >> this->readersRating;
	
	cin.ignore();

}

void Book::print() 
{
	cout << "Title: " << this->title << endl;
	cout << "Author: " << this->author << endl;
	cout << "Genre: " << this->genre << endl;
	cout << "Price: " << this->price << endl;
	cout << "Sales: " << this->numberOfSales << endl;
	cout << "Rating: " << this->readersRating << "/10" << endl;
}

void Book::deallocateMemoryBook() 
{
	delete[] this->title;
	delete[] this->author;
	delete[] this->genre;
}
