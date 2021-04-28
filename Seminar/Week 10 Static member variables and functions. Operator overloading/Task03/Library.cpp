#include "Library.h"

void Library::resizeCustomers()
{
    Customer **buffer = nullptr;
    try
    {
        buffer = new Customer *[capacityCustomers * INCREASE_STEP];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    for (std::size_t i = 0; i < sizeCustomers; ++i)
    {
        buffer[i] = new Customer(*customers[i]);
    }

    for (std::size_t i = 0; i < sizeCustomers; ++i)
    {
        delete customers[i];
    }
    delete[] customers;
    customers = buffer;
    capacityCustomers *= INCREASE_STEP;
}

void Library::resizeBooks()
{
    Book **buffer = nullptr;
    try
    {
        buffer = new Book *[capacityBooks * INCREASE_STEP];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    for (std::size_t i = 0; i < sizeBooks; ++i)
    {
        buffer[i] = new Book(*books[i]);
    }

    for (std::size_t i = 0; i < sizeBooks; ++i)
    {
        delete books[i];
    }
    delete[] books;
    books = buffer;
    capacityBooks *= INCREASE_STEP;
}

Library::Library()
{
    customers = nullptr;
    try
    {
        customers = new Customer *[INITIAL_CAPACITY];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    books = nullptr;
    try
    {
        books = new Book *[INITIAL_CAPACITY];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        delete[] customers;
    }

    sizeCustomers = 0;
    sizeBooks = 0;
    capacityCustomers = INITIAL_CAPACITY;
    capacityBooks = INITIAL_CAPACITY;
}

Library::~Library()
{
    for (std::size_t i = 0; i < sizeCustomers; ++i)
    {
        delete customers[i];
    }
    delete[] customers;

    for (std::size_t i = 0; i < sizeBooks; ++i)
    {
        delete books[i];
    }
    delete[] books;
}

void Library::addCustomer(const char *name, int age)
{
    if (sizeCustomers >= capacityCustomers)
    {
        resizeCustomers();
    }

    customers[sizeCustomers++] = new Customer(name, age);
}

void Library::addBook(const char *title, int yearOfIssue, int customerID)
{
    if (sizeBooks >= capacityBooks)
    {
        resizeBooks();
    }

    books[sizeBooks++] = new Book(title, yearOfIssue, customerID);
}

void Library::rentABook(int customerID, int bookID)
{
    int searchedIDCustomer = -1;

    for (std::size_t i = 0; i < sizeCustomers; ++i)
    {
        if (customers[i]->getID() == customerID)
        {
            searchedIDCustomer = i;
            return;
        }
    }

    if (searchedIDCustomer == -1)
    {
        throw std::invalid_argument("Customer with such ID does not exist");
    }

    int searchedIDBook = -1;

    for (std::size_t i = 0; i < sizeBooks; ++i)
    {
        if (books[i]->getID() == bookID)
        {
            searchedIDBook = i;
            return;
        }
    }

    if (searchedIDBook == -1)
    {
        throw std::invalid_argument("Book with such ID does not exist");
    }

    if (books[searchedIDBook]->getCustomerID() != -1)
    {
        throw std::invalid_argument("The book is already taken");
    }

    books[searchedIDBook]->setCustomerID(customerID);
}

void Library::returnBook(int customerID, int bookID)
{
    int searchedIDCustomer = -1;

    for (std::size_t i = 0; i < sizeCustomers; ++i)
    {
        if (customers[i]->getID() == customerID)
        {
            searchedIDCustomer = i;
            return;
        }
    }

    if (searchedIDCustomer == -1)
    {
        throw std::invalid_argument("Customer with such ID does not exist");
    }

    int searchedIDBook = -1;

    for (std::size_t i = 0; i < sizeBooks; ++i)
    {
        if (books[i]->getID() == bookID)
        {
            searchedIDBook = i;
            return;
        }
    }

    if (searchedIDBook == -1)
    {
        throw std::invalid_argument("Book with such ID does not exist");
    }

    if (books[searchedIDBook]->getCustomerID() == -1)
    {
        throw std::invalid_argument("The book is not taken");
    }

    books[searchedIDBook]->setCustomerID(-1);
}

void Library::printNotTakenBooks()
{
    for (std::size_t i = 0; i < sizeBooks; ++i)
    {
        if (books[i]->getCustomerID() == -1)
        {
            std::cout << *books[i] << std::endl;
        }
    }
}

Customer Library::getYoungestCustomer() const
{
    Customer result = *customers[0];

    for (std::size_t i = 0; i < sizeCustomers; ++i)
    {
        if (*customers[i] < result)
        {
            result = *customers[i];
        }
    }

    return result;
}

Customer Library::getOldestCustomer() const
{
    Customer result = *customers[0];

    for (std::size_t i = 0; i < sizeCustomers; ++i)
    {
        if (*customers[i] > result)
        {
            result = *customers[i];
        }
    }

    return result;
}

Book Library::getNewestBook() const
{
    Book result = *books[0];

    for (std::size_t i = 0; i < sizeBooks; ++i)
    {
        if (*books[i] < result)
        {
            result = *books[i];
        }
    }

    return result;
}

Book Library::getOldestBook() const
{
    Book result = *books[0];

    for (std::size_t i = 0; i < sizeBooks; ++i)
    {
        if (*books[i] > result)
        {
            result = *books[i];
        }
    }

    return result;
}