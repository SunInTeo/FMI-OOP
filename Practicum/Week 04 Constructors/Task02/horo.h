#ifndef HORO_H
#define HORO_H

/*
Да се състави клас Horo, който да бъде [immutable](https://en.wikipedia.org/wiki/Immutable_object)
със следните член-данни:

- име
- размер (7/8, 2/4...)
- област
*/
class Horo
{
    char *name;
    double tact;
    char *region;

public:
    Horo(const char* name = "N/A",
         const double tact = 20,
		 const char* region = "N/A");

    char *getName() const;
    double getTact() const;
    char *getRegion() const;
};

#endif