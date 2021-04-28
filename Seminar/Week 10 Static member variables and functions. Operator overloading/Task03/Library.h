#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <cstring>
#include "..\Task01\Customer.h"
#include "..\Task02\Book.h"

const int INITIAL_CAPACITY = 2;
const int INCREASE_STEP = 2;

class Library
{
    Customer **customers;
    Book **books;
    std::size_t sizeCustomers;
    std::size_t capacityCustomers;
    std::size_t sizeBooks;
    std::size_t capacityBooks;

    void resizeCustomers();
    void resizeBooks();

public:
    Library();
    Library(const Library &other) = delete;
    Library &operator=(const Library &other) = delete;
    ~Library();

    void addCustomer(const char *name, int age);
    void addBook(const char *title, int yearOfIssue, int customerID);
    
    void rentABook(int customerID, int bookID);
    void returnBook(int customerID, int bookID);

    void printNotTakenBooks();

    Customer getYoungestCustomer() const;
    Customer getOldestCustomer() const;

    Book getNewestBook() const;
    Book getOldestBook() const;
};

#endif