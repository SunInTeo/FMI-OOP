#ifndef BACKPACK_H
#define BACKPACK_H

#include "Item.h"
#include "Exceptions.h"

/*
	- може да събира различни обекти от **Item** в определения обем и желаното тегло
	- Backpack(double volume, double maxWeight)
	- void add(const Item &item)_ - ако не може да се добави следващия предмет поради недостатъчен обем 
        хвърлете *VolumeOverflow* (дефиниран от вас), а при тегло хвърлете *WeightOverflow* (дефиниран от вас)
	- int size()
	- double leftVolume()
	- double leftWeight()
	- предефинирайте оператора *[]*, ако индекса е по-голям от текущия брой item-и хвърлете *out_of_range*
*/
class Backpack
{
    Item *itemsArray;
    int size;
    double maxVolume, maxWeight;

    void copy(const Backpack &);
    void deallocate();

public:
    Backpack();
    Backpack(double maxVolume = 0.0, double maxWeight = 0.0);
    Backpack(const Backpack &);
    ~Backpack();

    void add(const Item &);

    int getSize() const;
    double leftVolume() const;
    double leftWeight() const;

    Backpack &operator=(const Backpack &);
    Item &operator[](int);
};

#endif