#include <iostream>
#include "Person.h"
#include "Car.h"
#include "Parking.h"

using std::cout;
using std::endl;

int main()
{
    Person teo1("Teo1", 19, true), teo2("Teo2", 20, false), teo3("Teo3", 19, true);

    Car car1(teo1, "Honda Civic", "SA 1234 PB", RED), car2(teo2, "BMW E36", "CT TTTT TT", BLACK),
        car3(teo3, "MAZDA CX5", "PB 5656 BT", BLUE), car4(teo1, "TOYOTA AVENSIS", "CT 7749 BT", GRAY),
        car5(teo2, "NISSAN GTR", "SS SSSS SS", BLACK);

    Parking parking;

    parking.addCar(car1);
    parking.addCar(car2);
    parking.addCar(car3);
    parking.addCar(car4);
    parking.addCar(car5);

    parking.printAllCars();
    cout << endl;

    parking.removeCar(2);
    parking.printAllCars();
    cout << endl;

    Person resultPerson = parking.getOwnerByLicensePlate("CT 7749 BT");
    cout << "After searching by license plate...\n";
    resultPerson.printInfo();

    cout << endl;

    size_t resultCount = 0;
    Car *resultCars = parking.getCarsByOwner(teo1, resultCount);
    cout << "After searching by owner...\n";
    for (int i = 0; i < resultCount; ++i)
    {
        cout << "Car #" << i + 1 << ":" << endl;
        resultCars[i].printInfoCar();
        cout << "\n----------------------------------\n";
    }

    return 0;
}