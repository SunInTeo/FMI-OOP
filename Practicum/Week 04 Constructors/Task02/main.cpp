#include <iostream>
#include "horo.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Horo h1;
    cout << "Sample example for the default constructor ->\n";
    cout << "Name: " << h1.getName() << "\nTact: " << h1.getTact() << "\nRegion: " << h1.getRegion() << "\n"; 

    Horo h2("Rychenica", 7.8, "ne znam");
    cout << "\n-----------------------------------------------\n";
    cout << "\nSample example for the other constructor ->\n";
    cout << "Name: " << h2.getName() << "\nTact: " << h2.getTact() << "\nRegion: " << h2.getRegion() << "\n"; 
    return 0;
}