#include <iostream>
#include "Backpack.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Backpack myBackpack(50, 50);

    Item item1("fenerche", 2, 2);
    Item item2("hladilna chanta", 10, 4);

    myBackpack.add(item1);
    myBackpack.add(item2);

    cout << myBackpack.getSize() << endl;
    cout << myBackpack.leftVolume() << endl;
    cout << myBackpack.leftWeight() << endl;

    cout << std::boolalpha << (myBackpack[0] == item1) << endl;
    cout << std::boolalpha << (myBackpack[0] == item2) << endl;

    Item item3("asd", 60, 50);

    cout << myBackpack.leftVolume() << endl;
    cout << myBackpack.leftWeight() << endl;

    myBackpack.add(item3);
    return 0;
}