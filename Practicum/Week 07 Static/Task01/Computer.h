#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <cstring>
#include <string>
/*Създайте клас Computer съдържащ следните полета (можете да ползвате std::string или динамично заделени символни низове):

- serial number - полето се генерира автоматично с последователни числа за всеки нов обект от класа.
- brand
- processor
- video
- hard drive
- weight
- battery life
- price
- quantity

Спазвайте принципа за капсулация на данните. 
Създайте конструктор, който приема всички полета. 
Създайте деструктор, който да изтрива динамично заделените полета. 
Създайте getters и setters за всички полета.*/
class Computer
{
    static std::size_t serialNumberIdentificator;
    int serialNumber;
    std::string brand;
    std::string processor;
    std::string video;
    int hardDrive;
    double weight;
    double batteryLife;
    double price;
    int quantity;

    void copy(const Computer &rhs);

public:
    Computer();
    Computer(std::string brand,
             std::string processor,
             std::string video,
             int hardDrive,
             double weight,
             double batteryLife,
             double price);
    Computer(const Computer &rhs);


    int getSerialNumber() const;
    std::string getBrand() const;
    std::string getProcessor() const;
    std::string getVideo() const;
    int getHardDrive() const;
    double getWeight() const;
    double getBatteryLife() const;
    double getPrice() const;
    int getQuantity() const;

    void setBrand(std::string brand);
    void setProcessor(std::string processor);
    void setVideo(std::string video);
    void setHardDrive(int hardDrive);
    void setWeight(double weight);
    void setBatteryLife(double batteryLife);
    void setPrice(double price);

    void increaseQuantity();
    void decreaseQuantity();

    Computer &operator=(const Computer &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Computer &other);
};

#endif