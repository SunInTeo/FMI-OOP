#include "List.h"

int main()
{
    List<int> list1;

    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    
    list1.remove(1);
    
    list1.write("data.dat");

    bool isEmpty = list1.isEmpty();
    std::cout << std::boolalpha << isEmpty << std::endl;

    std::cout << "Size: " << list1.getSize() << std::endl;

    std::cout << "Element at first index is " << list1[0] << std::endl;

    return 0;
}