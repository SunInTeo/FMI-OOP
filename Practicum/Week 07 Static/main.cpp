#include <iostream>
#include ".\Task02\ComputerShop.h"
#include ".\Task02\ConsultantUtils.h"

using std::cout;
using std::endl;

int main()
{
    Computer computer1("HP", "i9", "3080", 1024, 5, 7, 3000);
    Computer computer2("HP", "i7", "3070", 512, 5, 5, 2500);
    Computer computer3("Lenovo", "i9", "3080", 1024, 5, 5, 2900);
    Computer computer4("Lenovo", "i7", "3070", 1024, 5, 5, 2490);
    Computer computer5("Dell", "i5", "3060", 512, 3, 10, 1800);
    Computer computer6("Dell", "i5", "3060", 512, 5, 10, 1850);
    Computer computer7("Dell", "i5", "3060", 1024, 5, 10, 2000);

    ComputerShop myShop("asd", 10);
    myShop.addComputer(computer1);
    myShop.addComputer(computer2);
    myShop.addComputer(computer3);
    myShop.addComputer(computer4);
    myShop.addComputer(computer5);
    myShop.addComputer(computer6);
    myShop.addComputer(computer7);

    std::size_t countGoodForGaming;
    Computer *goodForGaming = myShop.filter(ConsultantUtils::isGoodForGaming, countGoodForGaming);

    cout << countGoodForGaming << endl;

    for (std::size_t i = 0; i < countGoodForGaming; ++i)
    {
        cout << goodForGaming[i] << endl;
    }

    std::size_t countGoodForTravel;
    Computer *goodForTravel = myShop.filter(ConsultantUtils::isGoodForTravel, countGoodForTravel);

    cout << countGoodForTravel << endl;

    for (std::size_t i = 0; i < countGoodForTravel; ++i)
    {
        cout << goodForTravel[i] << endl;
    }

    delete[] goodForGaming;
    delete[] goodForTravel;

    return 0;
}