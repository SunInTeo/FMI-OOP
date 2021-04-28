#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <cstring>

class Customer
{
    static int counter;
    int id;
    int age;
    char *name;

    void copy(const Customer &other);
    void deallocate();

public:
    Customer();
    Customer(const char *name, int age);
    Customer(const Customer &other);
    ~Customer();

    int getID() const;

    Customer &operator=(const Customer &other);
    bool operator==(const Customer &other) const;
    bool operator<(const Customer &other) const;
    bool operator>(const Customer &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Customer &other);
};

#endif