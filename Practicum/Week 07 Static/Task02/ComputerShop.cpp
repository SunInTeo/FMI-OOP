#include "ComputerShop.h"

using std::cout;
using std::endl;

void ComputerShop::copy(const ComputerShop &rhs)
{
    computersList = rhs.computersList;
    name = rhs.name;
    computersAmount = rhs.computersAmount;
    size = rhs.size;
}

void ComputerShop::deallocate()
{
    if (computersAmount)
    {
        delete[] computersList;
    }
}

ComputerShop::ComputerShop(std::string name, std::size_t size) : name(name)
{
    this->size = size;
    computersList = new Computer[size];
    computersAmount = 0;
}

ComputerShop::ComputerShop(const ComputerShop &rhs)
{
    copy(rhs);
}

ComputerShop::~ComputerShop()
{
    deallocate();
}

void ComputerShop::addComputer(const Computer &computer)
{
    if (computersAmount == size)
    {
        throw std::out_of_range("Cannot add more computers");
    }

    for (std::size_t i = 0; i < computersAmount; ++i)
    {
        if (computersList[i].getBrand() == computer.getBrand())
        {
            computersList[i].increaseQuantity();
            return;
        }
    }

    computersList[computersAmount++] = computer;
}

void ComputerShop::buyComputer(std::string wantedBrand, double money)
{
    for (std::size_t i = 0; i < computersAmount; ++i)
    {
        if (computersList[i].getBrand() == wantedBrand)
        {
            if (computersList[i].getPrice() > money)
            {
                throw std::invalid_argument("Not enough money");
            }
            else
            {
                computersList[i].decreaseQuantity();
                cout << "Successfull purchase" << endl;
            }

            if (computersList[i].getQuantity() == 0)
            {
                std::swap(computersList[i], computersList[computersAmount - 1]);
                --computersAmount;
            }

            return;
        }
    }

    throw std::invalid_argument("This brand does not exist in the shop");
}

Computer *ComputerShop::filter(filterFunction func, std::size_t &resultSize)
{
    resultSize = 0;
    for (std::size_t i = 0; i < computersAmount; ++i)
    {
        if (func(computersList[i]))
        {
            ++resultSize;
        }
    }

    Computer *result = new Computer[resultSize];

    std::size_t counter = 0;
    for (std::size_t i = 0; i < computersAmount; ++i)
    {
        if (func(computersList[i]))
        {
            result[counter++] = computersList[i];
        }
    }

    return result;
}

ComputerShop &ComputerShop::operator=(const ComputerShop &rhs)
{
    if (this != &rhs)
    {
        deallocate();
        copy(rhs);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, const ComputerShop &computerShop)
{
    for (std::size_t i = 0; i < computerShop.computersAmount; ++i)
    {
        out << "ComputerType #" << i + 1 << ":" << std::endl;
        out << computerShop.computersList[i] << std::endl;
    }

    return out;
}