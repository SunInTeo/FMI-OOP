#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>

class Book
{
    static int counter;
    int id;
    int customerID;
    char *title;
    int yearOfIssue;

    void copy(const Book &other);
    void deallocate();

public:
    Book();
    Book(const char *title, int yearOfIssue, int customerID);
    Book(const Book &other);
    ~Book();

    int getID() const;
    int getCustomerID() const;

    void setCustomerID(int customerID);

    Book &operator=(const Book &other);
    bool operator==(const Book &other) const;
    bool operator<(const Book &other) const;
    bool operator>(const Book &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Book &other);
};

#endif