#include "CommandController/CommandController.hpp"

int main() {
    std::vector<Person> personArr;
    std::vector<Vehicle> vehiArr;
    
    CommandController cmdCon(&personArr, &vehiArr);
    cmdCon.startReading();
    
    return 0;
}
