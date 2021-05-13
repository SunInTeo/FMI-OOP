#include "Subject.h"

#include <exception>

using std::cout;
using std::endl;

University *Subject::university;

void Subject::copy(const Subject &other)
{
    int *buffer = nullptr;
    try
    {
        buffer = new int[other.capacity];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }

    for (std::size_t i = 0; i < other.size; ++i)
    {
        buffer[i] = other.facNums[i];
    }

    facNums = buffer;
    capacity = other.capacity;
    size = other.size;
}

void Subject::deallocate()
{
    if (facNums)
    {
        delete[] facNums;
    }
}

void Subject::resize()
{
    int *buffer = nullptr;
    try
    {
        buffer = new int[capacity * INCREASE_STEP];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }

    for (std::size_t i = 0; i < size; ++i)
    {
        buffer[i] = facNums[i];
    }

    deallocate();
    facNums = buffer;
    capacity = capacity * INCREASE_STEP;
}

void Subject::setUniversity(University *university)
{
    Subject::university = university;
}

Subject::Subject()
{
    facNums = nullptr;
    try
    {
        facNums = new int[INITIAL_CAPACITY];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }

    capacity = INITIAL_CAPACITY;
    size = 0;
}

Subject::Subject(const Subject &other)
{
    copy(other);
}

Subject::~Subject()
{
    deallocate();
}

void Subject::addFacultyNumber(int facNum)
{
    if (size < university->getSize())
    {
        if (size == capacity)
        {
            resize();
        }

        facNums[size++] = facNum;
        university->setSubject(facNum);
    }
}

void Subject::printUnenrolledStudents()
{
    int counter = 0;
    for (std::size_t i = 0; i < university->getSize(); ++i)
    {
        if (!(*university)[i].getEnrollment())
        {
            cout << (*university)[i] << endl;
            ++counter;
        }
    }

    if (counter == 0)
    {
        cout << "All students in this university are enrolled" << endl;
    }
}

std::size_t Subject::getSize() const
{
    return size;
}

Subject &Subject::operator=(const Subject &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

Student &Subject::operator[](std::size_t index)
{
    int wantedFacultyNumber = facNums[index];

    for (std::size_t i = 0; i < university->getSize(); ++i)
    {
        if ((*university)[i].getFacultyNumber() == wantedFacultyNumber)
        {
            return (*university)[i];
        }
    }

    throw std::invalid_argument("Invalid index");
}
