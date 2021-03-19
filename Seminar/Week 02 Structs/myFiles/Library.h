#pragma once

struct Library
{
    Book *books;
    int size;
    int capacity;

    void create();
    void resize();
    void addBook(Book book);
    void removeBook();
};