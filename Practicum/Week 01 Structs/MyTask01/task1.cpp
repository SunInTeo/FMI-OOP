/*
    Да се реализират следните функции:

 -  да се добавя книга към списъка като характеристиките се прочитат от стандартния вход. 
    Заглавието трябва да е с главна буква без значение как го е въвел потребителя.
 -  да се премахва книга от списъка по зададен ISBN номер
 -  да се отпечатва броя на книгите
*/

#include <iostream>
#include <cstring>
#include "task1.h"

using std::cin;
using std::cout;
using std::endl;

void Book::readBook()
{
    cin.ignore();
    cout << "Title: ";
    cin.getline(title, 30);
    cout << "Author: ";
    cin.getline(author, 30);
    cout << "ISBN: ";
    cin >> numISBN;
}

void Library::addBookToList()
{
    Book newBook;
    newBook.readBook();

    cout << "\nBook added to library.\n";
    numOfBooks++;
}

void Library::removeBookFromList(char newISBN[])
{
    for(int i = 0; i < numOfBooks; i++)
    {
        if(!strcmp(newISBN, newBook[i].numISBN))
        {
            for(int j = 0; j < numOfBooks - 1; j++)
            {
                array[j] = array[j + 1];
            }
            cout << "\nBook removed from library.\n";
            numOfBooks--;
        }
        else
        {
            cout << "Incorrect ISBN.\n";
        }
    }
}

void Library::printNumberfOfBooks()
{
    cout << "There are " << numOfBooks << "books in the library.\n";
}

void printMenu()
{
    cout << "\n======================Menu======================\n";
    cout << "1. Add new book to library\n";
    cout << "2. Remove book from library(with given ISBN)\n";
    cout << "3. Print total number of books in the library\n";
    cout << "4. Exit\n";
    cout << "================================================\n";
}