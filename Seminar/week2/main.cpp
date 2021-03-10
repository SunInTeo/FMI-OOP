#include <iostream>
#include "Book.h"
#include "Library.h"
#include "Utils.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Book b;
    b.initialize();
    b.print();
    return 0;
}