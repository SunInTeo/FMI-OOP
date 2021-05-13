#include <iostream>
#include "Set.h"

using std::cout;
using std::endl;

int main ()
{
    Set<int> set1, set2;

    set1.add(1);
    set1.add(2);
    set1.add(3);
    set1.add(4);
    set1.add(5);

    set2.add(10);
    set2.add(11);
    set2.add(12);
    set2.add(13);
    set2.add(14);

    cout << set1 << endl;
    cout << set2 << endl;

    Set<int> set3 = set1 + set2;
    Set<int> set4 = set1 * set2;
    Set<int> set5 = set1 - set2;
    cout << set3 << endl;
    cout << set4 << endl;
    cout << set5 << endl;
    
    set1.writeIntoFile("data.dat");
    Set<int> copyOfSet1;
    copyOfSet1.readFromFile("data.dat");
    cout << "Copy " << copyOfSet1 << endl;

    return 0;
}