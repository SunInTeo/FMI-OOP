#ifndef CAR_H
#define CAR_H

#include "Person.h"
#include "enumColors.h"

/*
Направете клас Car, който има следните данни: марка, регистрационен номер, цвят, собственик(използвайте класа от миналата седмица). Да се напишат:

- конструктор по подразбиране;
- конструктор с параметри;
- деструктор;
- get-ъри и set-ъри;
- функция, която принтира информацията за човека. */
class Car
{
    Person owner;
    char *brand;
    char *licensePlate;
    Color color;

    void copy(const Car &);
    void deallocate();

public:
    Car();
    Car(const Person &, const char *, const char *, const Color);
    Car(const Car &);

    Car &operator=(const Car &);

    Person getOwner() const;
    char *getBrand() const;
    char *getLicensePlate() const;
    Color getColor() const;

    void setOwner(const Person &);
    void setBrand(const char *);
    void setLicensePlate(const char *);
    void setColor(const Color);

    void printInfoCar();

    ~Car();
};

#endif