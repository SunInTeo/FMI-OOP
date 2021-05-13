#include "University.h"

using std::cout;

void University::copy(const University &other)
{
    Student **buffer = nullptr;
    try
    {
        buffer = new Student *[other.capacity];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (std::size_t i = 0; i < other.capacity; ++i)
    {
        if (i < other.size)
        {
            buffer[i] = new Student(*other.studentsArray[i]);
        }
        else
        {
            buffer[i] = nullptr;
        }
    }

    studentsArray = buffer;
    size = other.size;
    capacity = other.capacity;
}

void University::deallocate()
{
    for (std::size_t i = 0; i < capacity; ++i)
    {
        if (studentsArray[i])
        {
            delete studentsArray[i];
        }
    }

    delete[] studentsArray;
}

void University::resize()
{
    size_t newCapacity = capacity * INCREASE_STEP;

    Student **newStudents = nullptr;
    try
    {
        newStudents = new Student *[newCapacity];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (std::size_t i = 0; i < newCapacity; ++i)
    {
        if (i < size)
        {
            newStudents[i] = new Student(*studentsArray[i]);
        }
        else
        {
            newStudents[i] = nullptr;
        }
    }

    deallocate();
    studentsArray = newStudents;
    capacity = newCapacity;
}

University::University()
{
    try
    {
        studentsArray = new Student *[INITIAL_CAPACITY];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }

    for (std::size_t i = 0; i < INITIAL_CAPACITY; ++i)
    {
        studentsArray[i] = nullptr;
    }

    capacity = INITIAL_CAPACITY;
    size = 0;
}

University::University(const University &other)
{
    copy(other);
}

University::~University()
{
    deallocate();
}

void University::addStudent(const char *name, bool isEnrolled)
{
    if (size >= capacity)
    {
        resize();
    }

    studentsArray[size++] = new Student(name, isEnrolled);
}

void University::addStudent(const Student &student)
{
    if (size >= capacity)
    {
        resize();
    }

    studentsArray[size++] = new Student(student);
}

size_t University::getSize() const
{
    return size;
}

void University::setSubject(int facNum)
{
    int searchedIndex = -1;
    for (std::size_t i = 0; i < size; ++i)
    {
        if (studentsArray[i]->getFacultyNumber() == facNum)
        {
            searchedIndex = i;
            break;
        }
    }

    if (searchedIndex == -1)
    {
        throw std::invalid_argument("Invalid faculty number!");
    }

    studentsArray[searchedIndex]->setEnrollment();
}

University &University::operator=(const University &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

University University::operator+(const University &other)
{
    University result = *this;

    for (std::size_t i = 0; i < other.size; ++i)
    {
        result.addStudent(*other.studentsArray[i]);
    }

    return result;
}

Student &University::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Invalid index");
    }

    return *studentsArray[index];
}
