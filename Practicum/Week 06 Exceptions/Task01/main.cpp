#include <iostream>
#include "Queue.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int maxSize;

    cout << "Size: ";
    cin >> maxSize;

    Queue myQueue(maxSize);

    Ticket ticket1("Ivan","0896222222", 123), ticket2("Georgi","0896454545", 456), ticket3("Alex","0896787878", 789);

    bool isEmpty = myQueue.empty();
    cout << "Before adding tickets ->\n";
    cout << ((isEmpty) ? "Yes":"No");

    myQueue.getTicket("Ivan","0896222222", 123);
    myQueue.getTicket("Georgi","0896454545", 456);
    myQueue.getTicket("Alex","0896787878", 789);

    isEmpty = myQueue.empty();
    cout << "\nAfter adding tickets ->\n";
    cout << ((isEmpty) ? "Yes":"No");

    cout << endl;

    Ticket randTicket = myQueue.next();

    cout << myQueue.getSize() << endl;

    randTicket = myQueue.next();

    cout << myQueue.getSize() << endl;

    randTicket = myQueue.next();

    cout << myQueue.getSize() << endl;

    return 0;
}