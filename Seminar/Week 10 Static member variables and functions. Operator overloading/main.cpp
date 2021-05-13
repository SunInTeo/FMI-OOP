#include <iostream>
#include ".\Task03\Library.h"

using std::cout;
using std::endl;

int main()
{
    Library myLibrary;

    myLibrary.addCustomer("Ivan", 20);
    myLibrary.addCustomer("Georgi", 19);
    myLibrary.addCustomer("Militsa", 21);

    myLibrary.addBook("Test1", 1900, -1);
    myLibrary.addBook("Test2", 1990, -1);
    myLibrary.addBook("Test3", 2010, -1);
    myLibrary.addBook("Test4", 2000, -1);

    myLibrary.printNotTakenBooks();

    myLibrary.rentABook(100, 1000);

    myLibrary.returnBook(100, 1000);

    cout << myLibrary.getOldestCustomer() << endl;
    cout << myLibrary.getYoungestCustomer() << endl;
    cout << myLibrary.getNewestBook() << endl;
    cout << myLibrary.getOldestBook() << endl;

    return 0;
}