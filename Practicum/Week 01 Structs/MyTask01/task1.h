/*
    Да се направи структура Library, която ще съдържа списък от книги (n <= 1000). 
    Всяка книга се характеризира със заглавие, автор и ISBN номер.
*/

#pragma once

const int MAX_NUMBER_OF_BOOKS = 1000;

struct Book
{
    char title[30];
    char author[30];
    char numISBN[14];

    void readBook();
};

struct Library
{
    Book booksNum[MAX_NUMBER_OF_BOOKS]; // списък с книги
    int numOfBooks = 0;

    void addBookToList();
    void removeBookFromList(char newISBN[]);
    void printNumberfOfBooks();
};

void printMenu();