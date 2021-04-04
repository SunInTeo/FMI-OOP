#include <iostream>
#include "Time.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    /*
    - t1 + t2 // 1
    - t3 = t1 + t2 // 2 
    - t4 = t1 + 5 // 3
    - t5 = 6 + t1 // 4
    - t1 > t2 // 5
    */

    Time t1(3, 5);
    Time t2(10, 23);
    Time result1 = t1 + t2;

    cout << "t1 + t2 = "; 
    result1.print();
    cout << endl;

    Time t3 = t1 + t2;

    cout << "t3 = "; 
    t3.print();
    cout << endl;

    Time t4 = t1 + 5;

    cout << "t4 = "; 
    t4.print();
    cout << endl;

    Time t5 = 6 + t1;
    
    cout << "t5 = "; 
    t5.print();
    cout << endl;

    cout << ((t1>t2) ? "Yes":"No" )<< endl;

    return 0;
}