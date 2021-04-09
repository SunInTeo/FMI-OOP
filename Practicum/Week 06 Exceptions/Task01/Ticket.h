#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "Consts.h"
/*
	- трябва да пази информация за име (символен низ) и телефон (символен низ) на клиента, както и поредния му номер (уникално целочислено число)
	- реализирайте подходящи конструктор/деструктори и getter/setter методи
	- предефинирайте операторите за вход (*>>*) и изход(*<<*)
	- направете валидация името да съдържа само букви и интервали (' ') иначе да хвърля изключение *invalid_argument*
	- направете валидация телефонния номер да бъде 10 цифри иначе да хвърля изключение *length_error* */
class Ticket
{
    char *name;
    char *mobileNum;
    int uniqueClientNumber;

    void deallocate();
    void copy(const Ticket &);

    void validateName(const char *);
    void validateMobileNumber(const char *);

public:
    Ticket();
    Ticket(const char *, const char *, const int);
    Ticket(const Ticket &);
    ~Ticket();

    char *getName() const;
    char *getMobileNumber() const;
    int getUniqueClientNumber() const;

    void setName(const char *);
    void setMobileNumber(const char *);
    void setUniqueClientNumber(const int);

    Ticket &operator=(const Ticket &);
    friend std::ostream &operator<<(std::ostream &, const Ticket &);
    friend std::istream &operator>>(std::istream &, Ticket &);
};

#endif