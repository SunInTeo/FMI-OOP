#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

int main()
{
    std::size_t counter = 0;
    ifstream file;
    file.open("test.txt");

    if (!file.is_open())
    {
        cout << "Cannot open the file" << endl;
        return 1;
    }

    std::string buffer;
    while (!file.eof())
    {
        getline(file, buffer);
        cout << buffer << endl;
        ++counter;
    }

    file.seekg(0, ios::end); 
    int size = file.tellg(); 
    file.seekg(0, ios::beg); 

    cout << "Lines: " << counter << endl;
    cout << "Size: " << size << " bytes" << endl;

    file.close();

    return 0;
}
