#include <iostream>
#include "Person.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Person p1("Teodor", 19, true);

    p1.printInfo();

    Person p2;

    p2.printInfo();

    p2 = p1;

    p2.printInfo();

    return 0;
}