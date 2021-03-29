#ifndef PERSON_H
#define PERSON_H

/*
Направете клас Person, който има следните данни: име, години, дали има свидетелство за управление на МПС. Да се напишат:

- конструктор по подразбиране;                    // 1
- copy конструктор;                               // 2
- конструктор с параметри;                        // 3
- оператор за присвояване;                        // 4
- деструктор;                                     // 5
- get-ъри и set-ъри;                              // 6
- функция, която принтира информацията за човека. // 7
*/
class Person
{
    char *name;
    unsigned age;
    bool hasLicense;

public:
    Person(); // 1

    Person(Person &); // 2

    Person(const char *, const unsigned, const bool); // 3

    Person &operator=(const Person &p); // 4

    ~Person(); // 5

    char *getName() const;             // ]
    unsigned getAge() const;           // |
    bool getHasLicense() const;        // |
                                        // 6
    void setName(const char *);        // |
    void setAge(const unsigned);       // |
    void setHasLicense(const bool);    // ]

    void printInfo(); // 7
};

#endif