#pragma once

/*
Да се напише структура "Book", която съдържа следната информация(полета):

- име на книгата
- име на автора
- жанр
- цена
- брой продажби
*/
struct Book
{
    char *title;
    char *author;
    char *genre;
    double price;
    int numberOfSales;

    void initialize();
    void print();
    void freeMemory();
};
