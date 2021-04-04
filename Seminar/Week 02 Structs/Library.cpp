#include <iostream>
#include "Library.h"
#include "Book.h"

using std::cin;
using std::cout;
using std::endl;

void Library::create(size_t capacity)
{

	this->library = new (std::nothrow) Book[capacity];
	if (!library)
	{
		cout << "Memory problem" << endl;
		return;
	}

	this->capacityOfLibrary = capacity;
	this->sizeOfLibrary = 0;

	cout << "Library created successfully!" << endl;
}

void Library::resize()
{
	Book *oldLibrary = this->library;

	this->capacityOfLibrary *= 2;

	this->library = new (std::nothrow) Book[this->capacityOfLibrary];
	if (!library)
	{
		cout << "Memory problem" << endl;
		return;
	}

	for (size_t i = 0; i < this->sizeOfLibrary; ++i)
	{
		this->library[i] = oldLibrary[i];
	}

	delete[] oldLibrary;
}

void Library::addBook()
{
	Book book;
	book.initialize();

	if (this->sizeOfLibrary == this->capacityOfLibrary)
	{
		resize();
	}

	this->library[this->sizeOfLibrary] = book;
	++this->sizeOfLibrary;
}

void Library::printBooks()
{
	for (int i = 0; i < this->sizeOfLibrary; ++i)
	{
		cout << "Books №" << i + 1 << "-> \n";
		this->library[i].print();
	}
}

void Library::deallocateMemoryLibrary()
{
	for (int i = 0; i < this->sizeOfLibrary; ++i)
	{
		this->library[i].deallocateMemoryBook();
	}

	delete[] this->library;
}

Book &Library::getBestBook()
{
	int maxSales = this->library[0].numberOfSales;

	int pos = 0;
	for (int i = 1; i < this->sizeOfLibrary; ++i)
	{
		if (maxSales < this->library[i].numberOfSales)
		{
			maxSales = this->library[i].numberOfSales;
			pos = i;
		}
	}

	return this->library[pos];
}

void Library::printBookByPrice(priceFilter fn)
{
	double bestBookPrice = this->library[0].price;

	int index = 0;
	for (int i = 1; i < this->sizeOfLibrary; ++i)
	{
		if (fn(this->library[i].price, bestBookPrice))
		{
			bestBookPrice = this->library[i].price;
			index = i;
		}
	}

	library[index].print();
}
