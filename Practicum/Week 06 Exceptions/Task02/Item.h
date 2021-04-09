#ifndef ITEM_H
#define ITEM_H

/*
    - има член-данни име, тегло и обем
	- Item(const char* label, double weight, double volume)_
	- предефинирайте операторите *==*, *>*, *=* */
class Item
{
    char *name;
    double volume;
    double weight;

    void copy(const Item &);
    void deallocate();

public:
    Item();
    Item(const char *, const double, const double);
    Item(const Item &);
    ~Item();

    char *getName() const;
    double getVolume() const;
    double getWeight() const;

    Item &operator=(const Item &);
    bool operator==(const Item &) const;
    bool operator>(const Item &) const;

};

#endif