#ifndef BOOK_H
#define BOOK_H

struct Book
{
	char* title;
	char* author;
	char* genre;
	double price;
	int numberOfSales;
	double readersRating;

	void initialize();

	void print();

	void deallocateMemoryBook();
};

#endif
