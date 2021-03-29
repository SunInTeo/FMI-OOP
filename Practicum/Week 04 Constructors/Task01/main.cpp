#include <iostream>
#include "pace.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double minutes, seconds, velocity;

    cout << "Sample example of constructor with minutes and second ->\n";
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter seconds: ";
    cin >> seconds;
    Pace p1(minutes, seconds);
    cout << "Pace of p1 " << p1.getPace() << "minutes/km" << endl;
    cout << "Velocity of p1 " << p1.getVelocity() << "km/h" << endl;

    cout << "\n-------------------------------------------------------\n";
    cout << "\nSample example of constructor with velocity ->\n";
    cout << "Enter velocity: ";
    cin >> velocity;
    Pace p2(velocity);
    cout << "Pace of p2 " << p2.getPace() << "minutes/km" << endl;
    cout << "Velocity of p1 " << p2.getVelocity() << "km/h" << endl;

    return 0;
}