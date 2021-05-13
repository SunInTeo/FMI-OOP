#include "Jedi.h"

using std::cout;
using std::endl;

int Jedi::version = 1;

void Jedi::copy(const Jedi &other)
{
    char **buffer = new char *[other.capacity];
    for (std::size_t i = 0; i < other.size; ++i)
    {
        buffer[i] = other.skills[i];
    }

    skills = buffer;
    size = other.size;
    capacity = other.capacity;
    age = other.age;
}

void Jedi::deallocate()
{
    for (std::size_t i = 0; i < size; ++i)
    {
        delete[] skills[i];
    }

    delete[] skills;
}

void Jedi::resize()
{
    char **buffer = new char *[capacity * INCREASE_STEP];
    for (std::size_t i = 0; i < size; ++i)
    {
        buffer[i] = skills[i];
    }

    skills = buffer;
    capacity *= INCREASE_STEP;
}

Jedi::Jedi()
{
    skills = new char *[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
    size = 0;
    age = 0;
}

Jedi::Jedi(const Jedi &other)
{
    copy(other);
}

Jedi::~Jedi()
{
    deallocate();
}

void Jedi::read(const char *filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Cannot open the file" << endl;
    }

    deallocate();

    file >> version >> size >> capacity;
    if (version >= 1)
    {
        file >> age;
    }
    else
    {
        age = 0;
    }

    skills = new char *[capacity];

    for (std::size_t i = 0; i < size; ++i)
    {
        std::size_t skillLength = 0;
        file >> skillLength;

        skills[i] = new char[skillLength + 1];

        file.get();
        file.getline(skills[i], skillLength + 1);
    }

    file.close();
}

void Jedi::write(const char *filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        cout << "Cannot open the file" << endl;
    }

    file << version << " " << size << " " << capacity << " " << age << endl;
    for (std::size_t i = 0; i < this->size; ++i)
    {
        file << strlen(skills[i]) << " " << skills[i] << endl;
    }

    file.close();
}

void Jedi::setAge(int age)
{
    this->age = age;
}

void Jedi::addNewSkill(const char *skill)
{
    if (size == capacity)
    {
        resize();
    }

    skills[size] = new char[strlen(skill) + 1];
    strcpy(skills[size++], skill);
}

Jedi &Jedi::operator=(const Jedi &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Jedi &jedi)
{
    out << jedi.version << " " << jedi.size << " " << jedi.capacity << " " << jedi.age << endl;
    for (std::size_t i = 0; i < jedi.size; ++i)
    {
        out << jedi.skills[i] << endl;
    }

    return out;
}