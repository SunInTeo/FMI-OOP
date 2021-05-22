#ifndef PERSON_AND_VEHICLE_ALLOCATOR
#define PERSON_AND_VEHICLE_ALLOCATOR

#include "./Person.h"
#include "./Utils.h"

class PersonAndVehicleAllocator
{
private:
    std::vector<Person *> personArray;
    std::vector<Vehicle *> vehicleArray;

public:
    ~PersonAndVehicleAllocator();
    void clear();

    void createPerson(std::string name, std::string uid);
    void createVehicle(std::string registration, std::string description);
    void acquire(std::string personID, std::string vehicleRegistration);
    void release(std::string personID, std::string vehicleRegistration);
    void remove(std::string str);
    void show(std::string str);

    bool doesExistP(unsigned int &uid);
    bool doesExistV(Registration &registration);

    // returns a number corresponding to the type of <what> the user inputs
    // helps with the implementation in REMOVE and SHOW functions
    // 0 - nothing
    // 1 - registration
    // 2 - uid
    std::size_t getType(std::string str);
    Person *getPersonByID(const unsigned int &uid);
    Vehicle *getVehicleByID(const Registration &registration);

    void printPeople();
    void printVehicles();
    void printAllInfo();
};

#endif