#include <iostream>
#include <cstring>
#include "WashingMachine.h"

using std::cout;
using std::endl;

WashingMachine::WashingMachine()
{
    for (int i = 0; i < MAX_STRING_LENGTH; ++i)
    {
        this->manufacturer[i] = '\0';
        this->model[i] = '\0';
    }
    this->massLaundry = 0;
    this->electricalConsumption = 0;
    this->waterConsumption = 0;
}

WashingMachine::WashingMachine(const char *manufacturer, const char *model, const int massLaundry,
                               const double electricalConsumption, const int waterConsumption)
{
    strcpy(this->manufacturer, manufacturer);
    strcpy(this->model, model);
    this->massLaundry = massLaundry;
    this->electricalConsumption = electricalConsumption;
    this->waterConsumption = waterConsumption;
}

bool WashingMachine::operator>(const WashingMachine &other)
{
    return (this->massLaundry > other.massLaundry) ||
           (this->massLaundry == other.massLaundry && this->electricalConsumption < other.electricalConsumption) ||

           (this->massLaundry == other.massLaundry && this->electricalConsumption == other.electricalConsumption &&
            this->waterConsumption < other.waterConsumption);
}

std::ostream &operator<<(std::ostream &out, const WashingMachine &washingMachine)
{
    out << "Manufacturer: " << washingMachine.manufacturer << endl;
    out << "Model: " << washingMachine.model;

    return out;
}

std::istream &operator>>(std::istream &in, WashingMachine &washingMachine)
{
    cout << "Manufacturer: ";
    in.getline(washingMachine.manufacturer, MAX_STRING_LENGTH);

    cout << "Model: ";
    in.getline(washingMachine.model, MAX_STRING_LENGTH);

    cout << "Max mass of the laundry: ";
    in >> washingMachine.massLaundry;

    cout << "Electrical consumption: ";
    in >> washingMachine.electricalConsumption;

    cout << "Water consumption: ";
    in >> washingMachine.waterConsumption;
    in.ignore();

    return in;
}