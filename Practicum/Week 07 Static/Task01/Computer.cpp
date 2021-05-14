#include "Computer.h"

size_t Computer::serialNumberIdentificator = 0;

void Computer::copy(const Computer &rhs)
{
    brand = rhs.brand;
    processor = rhs.processor;
    video = rhs.video;
    hardDrive = rhs.hardDrive;
    weight = rhs.weight;
    batteryLife = rhs.batteryLife;
    price = rhs.price;
    quantity = rhs.quantity;
    serialNumber = rhs.serialNumber;
}

Computer::Computer() : brand(), processor(), video()
{
    hardDrive = 0;
    weight = 0;
    batteryLife = 0;
    price = 0;
    quantity = 0;
    serialNumber = 0;
}

Computer::Computer(std::string brand,
                   std::string processor,
                   std::string video,
                   int hardDrive,
                   double weight,
                   double batteryLife,
                   double price) : brand(brand), processor(processor), video(video)
{
    this->hardDrive = hardDrive;
    this->weight = weight;
    this->batteryLife = batteryLife;
    this->price = price;
    this->quantity = 1;
    this->serialNumber = ++serialNumberIdentificator;
}

Computer::Computer(const Computer &rhs)
{
    copy(rhs);
}

int Computer::getSerialNumber() const
{
    return serialNumber;
}
std::string Computer::getBrand() const
{
    return brand;
}
std::string Computer::getProcessor() const
{
    return processor;
}
std::string Computer::getVideo() const
{
    return video;
}
int Computer::getHardDrive() const
{
    return hardDrive;
}
double Computer::getWeight() const
{
    return weight;
}
double Computer::getBatteryLife() const
{
    return batteryLife;
}
double Computer::getPrice() const
{
    return price;
}
int Computer::getQuantity() const
{
    return quantity;
}

void Computer::setBrand(std::string brand)
{
    this->brand = brand;
}
void Computer::setProcessor(std::string processor)
{
    this->processor = processor;
}
void Computer::setVideo(std::string video)
{
    this->video = video;
}
void Computer::setHardDrive(int hardDrive)
{
    this->hardDrive = hardDrive;
}
void Computer::setWeight(double weight)
{
    this->weight = weight;
}
void Computer::setBatteryLife(double batteryLife)
{
    this->batteryLife = batteryLife;
}
void Computer::setPrice(double price)
{
    this->price = price;
}

void Computer::increaseQuantity()
{
    ++quantity;
}
void Computer::decreaseQuantity()
{
    --quantity;
}

Computer &Computer::operator=(const Computer &rhs)
{
    if (this != &rhs)
    {
        copy(rhs);
    }
    return *this;
}

std::ostream& operator << (std::ostream& out, const Computer& computer)
{
    out << "Brand: " << computer.brand << std::endl;
    out << "Quantity: " << computer.quantity;

    return out;
}