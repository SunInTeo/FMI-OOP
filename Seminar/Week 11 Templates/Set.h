#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

template <class T>
class Set
{
private:
    std::vector<T> data;

public:
    Set();

    void add(T element);
    bool contains(T element);
    bool isEmpty();
    void remove(T element);
    std::size_t getSize();

    bool operator==(const Set<T> &other) const;
    Set<T> operator+(Set<T> &other);
    Set<T> operator*(Set<T> &other);
    Set<T> operator-(Set<T> &other);

    void writeIntoFile(std::string fileName);
    void readFromFile(std::string fileName);

    template <typename C>
    friend std::ostream &operator<<(std::ostream &out, Set<C> &set);
};

template <class T>
Set<T>::Set() {}

template <class T>
void Set<T>::add(T element)
{
    if (!contains(element))
    {
        data.push_back(element);
    }
}

template <class T>
bool Set<T>::contains(T element)
{
    std::size_t size = getSize();
    for (std::size_t i = 0; i < size; ++i)
    {
        if (element == data[i])
        {
            return true;
        }
    }

    return false;
}

template <class T>
bool Set<T>::isEmpty()
{
    return data.size() == 0;
}

template <class T>
void Set<T>::remove(T element)
{
    if (contains(element))
    {
        int searchedIndex = -1;
        std::size_t size = getSize();
        for (std::size_t i = 0; i < size; ++i)
        {
            if (element == data[i])
            {
                searchedIndex = i;
                break;
            }
        }

        data.erase(data.begin() + searchedIndex);
    }
}

template <class T>
std::size_t Set<T>::getSize()
{
    return data.size();
}

template <class T>
bool Set<T>::operator==(const Set<T> &other) const
{
    if (getSize() != other.getSize())
    {
        return false;
    }

    std::size_t size = getSize();
    for (std::size_t i = 0; i < size; ++i)
    {
        if (data[i] != other.data[i])
        {
            return false;
        }
    }

    return true;
}

template <class T>
Set<T> Set<T>::operator+(Set<T> &other)
{
    Set<T> result = *this;

    std::size_t sizeOther = other.getSize();
    for (std::size_t i = 0; i < sizeOther; ++i)
    {
        result.add(other.data[i]);
    }

    return result;
}

template <class T>
Set<T> Set<T>::operator*(Set<T> &other)
{
    Set<T> result = *this;

    std::size_t sizeThis = getSize();
    for (std::size_t i = 0; i < sizeThis; ++i)
    {
        if (!other.contains(data[i]))
        {
            result.remove(data[i]);
        }
    }

    return result;
}

template <class T>
Set<T> Set<T>::operator-(Set<T> &other)
{
    Set<T> result = *this;

    std::size_t sizeOther = other.getSize();
    for (std::size_t i = 0; i < sizeOther; ++i)
    {
        if (contains(other.data[i]))
        {
            result.remove(other.data[i]);
        }
    }

    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, Set<T> &set)
{
    std::size_t size = set.getSize();
    out << "Set: ";
    for (std::size_t i = 0; i < size; ++i)
    {
        out << set.data[i] << " ";
    }

    return out;
}

template <class T>
void Set<T>::writeIntoFile(std::string fileName)
{
    std::ofstream file(fileName.c_str());

    if (!file.is_open())
    {
        std::cout << "Error" << std::endl;
        return;
    }

    std::size_t size = getSize();
    for (std::size_t i = 0; i < size; ++i)
    {
        file.write((const char *)&data[i], sizeof(T));
    }

    file.close();
}

template <class T>
void Set<T>::readFromFile(std::string fileName)
{
    std::ifstream file(fileName.c_str());

    if (!file.is_open())
    {
        std::cout << "Error" << std::endl;
        return;
    }

    while (!file.eof())
    {
        T temp;
        file.read((char *)&temp, sizeof(T));
        if (!file.eof())
        {
            add(temp);
        }
    }

    file.close();
}

#endif