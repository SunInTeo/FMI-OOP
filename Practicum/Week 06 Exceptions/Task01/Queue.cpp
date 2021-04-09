#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

void Queue::deallocate()
{
    if(this->ticketsArray)
    {
        delete[] ticketsArray;
    }

    this->currentIndex = 0;
    this->size = 0;
}

void Queue::copy(const Queue &other)
{
    try
    {
        this->ticketsArray = new Ticket[this->size + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for(int i = 0; i < this->currentIndex; ++i)
    {
        this->ticketsArray[i] = other.ticketsArray[i];
    }

    this->currentIndex = other.currentIndex;
    this->size = other.size;
}

Queue::Queue()
{
    this->ticketsArray = nullptr;
    this->currentIndex = 0;
    this->size = INITIAL_QUEUE_SIZE;
}

Queue::Queue(int size)
{
    try
    {
        this->ticketsArray = new Ticket[this->size + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    this->currentIndex = 0;
    this->size = size;
}

Queue::Queue(const Queue &other)
{
    copy(other);
}

int Queue::getTicket(const char *name, const char *phone, const size_t uniqueClientNum)
{
    try
    {
        if(this->currentIndex == this->size)
        {
            throw std::overflow_error("No space");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Ticket newTicket(name, phone, uniqueClientNum);

    this->ticketsArray[this->currentIndex++] = newTicket;

    return this->currentIndex - 1;
}

Ticket Queue::next()
{
    try
    {
        if(this->currentIndex == 0)
        {
            throw std::out_of_range("Empty queue");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Ticket result;
    result = this->ticketsArray[0];

    for(int i = 0; i < this->currentIndex - 1; ++i)
    {
        this->ticketsArray[i] = this->ticketsArray[i + 1];
    }
    --currentIndex;

    return result;
}

bool Queue::empty() const { return !this->currentIndex; }

Queue &Queue::operator=(const Queue &other)
{
    if(this != &other)
    {
        deallocate();
        copy(other);
    }
    return *this;
}

Ticket &Queue::operator[](size_t indexOfTicket)
{
    try
    {
        if(indexOfTicket >= this->currentIndex)
        {
            throw std::invalid_argument("Invalid index");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return ticketsArray[indexOfTicket];
}

int Queue::getSize() const
{
    return this->currentIndex;
}    

Queue::~Queue()
{
    deallocate();
}