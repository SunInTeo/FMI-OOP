#ifndef QUEUE_H
#define QUEUE_H

#include "Ticket.h"
#include "Consts.h"

/*
	- Queue(int size) - осигурява максималната дължина на опашката
	
    - int getTicket(const char* name, const char* phone) - който добавя нов билет в системата 
    и връща поредния му номер, а ако е запълнен капацитета на опашката хвърля overflow_error;
	
    - да се предефинира оператора [], който спрямо поредния номер връща билета, с този номер; 
    а ако няма намерен билет хвърля invalid_argument
	
    - Ticket next() - изважда следващия от опашката
	
    - bool empty() const
	
    - int getSize() const    */
class Queue
{
    Ticket *ticketsArray;
    size_t currentIndex;
    size_t size;

    void deallocate();
    void copy(const Queue &);

public:
    Queue();
    Queue(int);
    Queue(const Queue &);

    int getTicket(const char *, const char *, const size_t);

    Ticket next();

    bool empty() const;

    int getSize() const;

    Queue &operator=(const Queue &);
    Ticket &operator[](size_t);

    ~Queue();
};

#endif