#include "FamilyCar.h"
#include "SportCar.h"

int main()
{
    double maxSpeed, currentSpeed, price;

    std::cout << "\n==================================\n";
    std::cout << "Car ->\n";
    std::cout << "Max speed: ";
    std::cin >> maxSpeed;

    std::cout << "Current speed: ";
    std::cin >> currentSpeed;

    std::cout << "Price: ";
    std::cin >> price;

    Vehicle *car1 = new Car(maxSpeed, currentSpeed, price);

    car1->startMovement();
    car1->stopMovement();

    double sc_maxSpeed, sc_currentSpeed, sc_price;

    std::cout << "\n==================================\n";
    std::cout << "Sport car ->\n";
    std::cout << "Max speed: ";
    std::cin >> sc_maxSpeed;

    std::cout << "Current speed: ";
    std::cin >> sc_currentSpeed;

    std::cout << "Price: ";
    std::cin >> sc_price;

    Car *car2 = new SportCar(sc_maxSpeed, sc_currentSpeed, sc_price);

    car2->startEngine();
    car2->startMovement();
    car2->accelerate();
    car2->stopMovement();
    car2->stopEngine();

    double fc_maxSpeed, fc_currentSpeed, fc_price;

    std::cout << "\n==================================\n";
    std::cout << "Family car ->\n";
    std::cout << "Max speed: ";
    std::cin >> fc_maxSpeed;

    std::cout << "Current speed: ";
    std::cin >> fc_currentSpeed;

    std::cout << "Price: ";
    std::cin >> fc_price;

    Car *car3 = new FamilyCar(fc_maxSpeed, fc_currentSpeed, fc_price);

    car3->startEngine();
    car3->startMovement();
    car3->accelerate();
    car3->stopMovement();
    car3->stopEngine();

    return 0;
}