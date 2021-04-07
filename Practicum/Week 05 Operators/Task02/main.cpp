#include <iostream>
#include "WashingMachine.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;

    cout << "Number of washing machines: ";
    cin >> n;
    cin.ignore();

    WashingMachine *washingMachines = new (std::nothrow) WashingMachine[n];
    if (!washingMachines)
    {
        cout << "Memory problem\n";
        return 1;
    }

    cin >> washingMachines[0];
    WashingMachine best = washingMachines[0];

    for (int i = 1; i < n; ++i)
    {
        cin >> washingMachines[i];
        if (washingMachines[i] > best)
        {
            best = washingMachines[i];
        }
    }

    cout << best << endl;

    delete[] washingMachines;
}