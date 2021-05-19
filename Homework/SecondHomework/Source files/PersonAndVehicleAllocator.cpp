#include "../Header files/PersonAndVehicleAllocator.h"

std::size_t PersonAndVehicleAllocator::getType(std::string str)
{
    try
    {
        Registration tempReg(str.c_str());
        return 1;
    }
    catch (const std::exception &e)
    {
        try
        {
            stringToInt(str);
            return 2;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Cannot convert string neither to Registration nor to Person";
            return 0;
        }
    }
}

PersonAndVehicleAllocator::~PersonAndVehicleAllocator()
{
    clear();
}
void PersonAndVehicleAllocator::clear()
{
    for (std::size_t i = 0; i < personArray.size(); ++i)
    {
        delete personArray.at(i);
    }
    for (std::size_t i = 0; i < vehicleArray.size(); ++i)
    {
        delete vehicleArray.at(i);
    }

    personArray.clear();
    vehicleArray.clear();
}

void PersonAndVehicleAllocator::createPerson(std::string name, std::string uid)
{
    if (uid.c_str() == nullptr)
    {
        throw std::invalid_argument("No uid provided");
    }

    unsigned int tempUID = stringToInt(uid);
    if (doesExistP(tempUID))
    {
        throw std::invalid_argument("Vehicle already exists");
    }

    Person *tempPerson = new Person(name, tempUID);
    personArray.push_back(tempPerson);
}
void PersonAndVehicleAllocator::createVehicle(std::string registration, std::string description)
{
    if (description.c_str() == nullptr)
    {
        throw std::invalid_argument("No description provided");
    }

    Registration tempReg(registration.c_str());
    if (doesExistV(tempReg))
    {
        throw std::invalid_argument("Vehicle already exists");
    }

    Vehicle *tempVhcl = new Vehicle(Registration(registration.c_str()), description);
    vehicleArray.push_back(tempVhcl);
}
void PersonAndVehicleAllocator::acquire(std::string personID, std::string vehicleRegistration)
{
    Person *tempPerson = getPersonByID(stringToInt(personID));
    Registration tempReg(vehicleRegistration.c_str());
    Vehicle *tempVhcl = getVehicleByID(tempReg);
    tempPerson->acquire(*tempVhcl);
}
void PersonAndVehicleAllocator::release(std::string personID, std::string vehicleRegistration)
{
    Person *tempPerson = getPersonByID(stringToInt(personID));
    Registration tempReg(vehicleRegistration.c_str());
    tempPerson->release(tempReg);
}
void PersonAndVehicleAllocator::remove(std::string str)
{
    int tempID = getType(str);
    switch (tempID)
    {
        case 1:
        {
            Registration tempReg(str.c_str());
            Vehicle *tempVhcl = getVehicleByID(tempReg);
            tempVhcl->getOwner().release(tempReg);

            for (std::size_t i = 0; i < vehicleArray.size(); ++i)
            {
                if (vehicleArray.at(i)->getReg() == tempReg)
                {
                    delete vehicleArray.at(i);
                    vehicleArray.erase(vehicleArray.begin() + i);
                }
            }
            break;
        }
        case 2:
        {
            unsigned int tempUID = stringToInt(str);
            Person *tempPerson = getPersonByID(tempUID);
            tempPerson->releaseAll();

            for (std::size_t i = 0; i < personArray.size(); ++i)
            {
                if (personArray.at(i)->getUid() == tempUID)
                {
                    delete personArray.at(i);
                    personArray.erase(personArray.begin() + i);
                }
            }
            break;
        }
        default:
        {
            throw std::invalid_argument("Incorrect input");
            break;
        }
    }
}
void PersonAndVehicleAllocator::show(std::string str)
{
    if (!strcmp(toUpperCase(str).c_str(), "PEOPLE"))
    {
        PersonAndVehicleAllocator::printPeople();
    }
    else if (!strcmp(toUpperCase(str).c_str(), "VEHICLES"))
    {
        PersonAndVehicleAllocator::printVehicles();
    }
    else
    {
        std::size_t tempID = getType(str);
        switch (tempID)
        {
            case 1:
                {
                Registration tempReg(str.c_str());
                Vehicle *tempVhcl = getVehicleByID(tempReg);
                tempVhcl->printVehicleAndOwner();
                std::cout << std::endl;
                break;
                }
            case 2:
                {
                unsigned int tempUID = stringToInt(str);
                Person *tempPerson = getPersonByID(tempUID);
                tempPerson->printWithVehicles();
                std::cout << std::endl;
                break;
                }
            default:
                {
                throw std::invalid_argument("Incorrect input");
                break;
                }
        }
    }
}

bool PersonAndVehicleAllocator::doesExistP(unsigned int &uid)
{
    for (std::size_t i = 0; i < personArray.size(); ++i)
    {
        if (personArray.at(i)->getUid() == uid)
        {
            return true;
        }
    }

    return false;
}
bool PersonAndVehicleAllocator::doesExistV(Registration &registration)
{
    for (std::size_t i = 0; i < vehicleArray.size(); ++i)
    {
        if (vehicleArray.at(i)->getReg() == registration)
        {
            return true;
        }
    }

    return false;
}

Person *PersonAndVehicleAllocator::getPersonByID(const unsigned int &uid)
{
    for (std::size_t i = 0; i < personArray.size(); ++i)
    {
        if (personArray.at(i)->getUid() == uid)
        {
            return personArray.at(i);
        }
    }
    throw std::invalid_argument("No such person");
}
Vehicle *PersonAndVehicleAllocator::getVehicleByID(const Registration &registration)
{
    for (std::size_t i = 0; i < vehicleArray.size(); ++i)
    {
        if (vehicleArray.at(i)->getReg() == registration)
        {
            return vehicleArray.at(i);
        }
    }
    throw std::invalid_argument("No such vehicle");
}

void PersonAndVehicleAllocator::printPeople()
{
    for (std::size_t i = 0; i < personArray.size(); ++i)
    {
        personArray.at(i)->print();
        std::cout << std::endl;
    }
}
void PersonAndVehicleAllocator::printVehicles()
{
    for (std::size_t i = 0; i < vehicleArray.size(); ++i)
    {
        vehicleArray.at(i)->print();
        std::cout << std::endl;
    }
}
void PersonAndVehicleAllocator::printAllInfo()
{
    for (std::size_t i = 0; i < personArray.size(); ++i)
    {
        personArray.at(i)->printWithVehicles();
        std::cout << std::endl;
    }
    PersonAndVehicleAllocator::printVehicles();
}