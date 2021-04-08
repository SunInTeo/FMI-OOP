#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
    char *name;
    unsigned age;
    bool hasLicense;

    void copy(const Person &);
    void deallocate();

public:
    Person(); // 1

    Person(const Person &); // 2

    Person(const char *, const unsigned, const bool); // 3

    Person &operator=(const Person &); // 4
    bool operator==(const Person &) const;

    ~Person(); // 5

    char *getName() const;          // ]
    unsigned getAge() const;        // |
    bool getHasLicense() const;     // |
                                    // 6
    void setName(const char *);     // |
    void setAge(const unsigned);    // |
    void setHasLicense(const bool); // ]

    void printInfo(); // 7
};

#endif