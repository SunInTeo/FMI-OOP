#ifndef JEDI_H
#define JEDI_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

const std::size_t INITIAL_CAPACITY = 2;
const std::size_t INCREASE_STEP = 2;

class Jedi
{
    static int version;
    char **skills;
    std::size_t size;
    std::size_t capacity;
    int age;

    void copy(const Jedi &other);
    void deallocate();
    void resize();

public:
    Jedi();
    Jedi(const Jedi &other);
    ~Jedi();

    void read(const char *filename);
    void write(const char *filename);

    void setAge(int age);
    void addNewSkill(const char *skill);

    Jedi &operator=(const Jedi &other);

    friend std::ostream &operator<<(std::ostream &out, const Jedi &jedi);
};

#endif