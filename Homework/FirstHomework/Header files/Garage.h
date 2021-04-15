#ifndef GARAGE_H
#define GARAGE_H

#include "Vehicle.h"


/*
-Garage(std::size_t size) -- създава гараж с максимално място за паркиране size.
Гарантирайте, че обектите могат да се копират и унищожават коректно. Ако е нужно, 
реализирайте експлицитно всички функции от rule of 3 (бонус: гарантирайте, че работят коректно всички от rule of 5). 
Ако това не е нужно, следвайте rule of 0.
-void insert(Vehicle& v) -- добавя превозното средство v в гаража. Ако операцията не успее 
(например няма достатъчно памет, в гаража няма повече място за паркиране, вече има кола със същия регистрационен номер), 
да се хвърля изключение. Операцията да дава strong exception guarantee.
-void erase(const char* registration) -- премахва колата с регистрационен номер registration от гаража.
Ако такава няма, да не се прави нищо. При премахването на кола от гаража е допустимо да се промени редът на останалите в гаража. 
Това условие ще ви позволи при премахване на елемент да поставите последния елемент от масива на мястото на премахнатия, 
вместо да правите left shift.
-const Vehicle& at(std::size_t pos) const -- достъп до елемента намиращ се на позиция pos. 
Ако такъв няма, да се хвърля изключение std::out_of_range.
-const Vehicle& operator[](std::size_t pos) const -- достъп до елемента намиращ се на позиция pos. 
Функцията да не прави проверка за коректност дали pos е валидна позиция. (В debug режим assert-вайте дали pos е валидна позиция).
-bool empty() const -- Проверява дали гаражът е празен.
-std::size_t size() const -- брой елементи (превозни средства) в гаража.
-void clear() -- изчиства съдържанието на гаража. Това означава, 
че в него не се съдържа нито една кола. Капацитетът му обаче остава непроменен. 
Така в него могат отново да се добавят нови коли.
-const Vehicle* find(const char* registration) const -- намира и връща превозното средство с регистрационен номер registration в гаража. 
Ако такова няма, да се върне nullptr.*/
class Garage
{
    Vehicle **vehicleArray = nullptr;
    std::size_t _capacity;
    std::size_t _sizeTaken;
    std::size_t _numberOfVehicles;

    void copy(const Garage &other);
    void deallocate();
    void resize();
public:
    Garage() = delete;
    Garage(std::size_t size);
    Garage(const Garage &other);
    ~Garage();
    
    void insert(Vehicle& v);

    Garage &operator=(const Garage &other);
};

#endif