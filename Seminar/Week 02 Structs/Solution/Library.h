#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Utils.h"

struct Library
{
	size_t sizeOfLibrary;
	size_t capacityOfLibrary;
	Book* library;

	void create(size_t capacity);

	void resize();

	void addBook();

	void printBooks();

	void deallocateMemoryLibrary();

	Book& getBestBook();

	void printBookByPrice(priceFilter fn);

};

#endif
