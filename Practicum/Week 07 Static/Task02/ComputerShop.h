#ifndef COMPUTER_SHOP_H
#define COMPUTER_SHOP_H

#include "..\Task01\Computer.h"

typedef bool (*filterFunction)(const Computer &computer);

class ComputerShop
{
    Computer *computersList;
    std::string name;
    std::size_t computersAmount;
    std::size_t size;

    void copy(const ComputerShop &rhs);
    void deallocate();

public:
    ComputerShop(std::string name, std::size_t size);
    ComputerShop(const ComputerShop &rhs);
    ~ComputerShop();

    void addComputer(const Computer &other);
    void buyComputer(std::string wantedBrand, double money);

    Computer *filter(filterFunction func, std::size_t &resultSize);
    
    ComputerShop &operator=(const ComputerShop &rhs);
    friend std::ostream &operator<<(std::ostream &out, const ComputerShop &other);
};

#endif