#include <iostream>
#include "Book.h"
#include "Library.h"
#include "Utils.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Library myLibrary;

	int n;
	cout << "Number of books in library: ";
	cin >> n;

	myLibrary.initialize(n);

	for(int i = 0; i < n; ++i)
	{
		myLibrary.addBook();
	}

    myLibrary.printBooks();

    cout << "\n--------------------------\n";

    Book bestBook = myLibrary.getBestBook();
	
    cout << "Book with most sales:" << endl;
    bestBook.print();

    cout << "\nThe cheapest book:" << endl;
    myLibrary.printBookByPrice(isCheaper);

    cout << "\nThe most expensive book:" << endl;
    myLibrary.printBookByPrice(isMoreExpensive);

    myLibrary.deallocateMemoryLibrary();
    bestBook.deallocateMemoryBook();

	return 0;
}