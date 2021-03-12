#include <iostream>
#include "task1.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Library newLibrary;
    int option;

    do
    {
        printMenu();

        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            newLibrary.addBookToList();
        case 2:
            char newNumISBN[14];
            cin.getline(newNumISBN, 14);
            newLibrary.removeBookFromList(newNumISBN);
        case 3:
            newLibrary.printNumberfOfBooks();
        }
    } while (option > 0 || option < 4);

    return 0;
}