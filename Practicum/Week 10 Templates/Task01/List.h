#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <fstream>

const int INITIAL_CAPACITY = 2;
const int INCREASE_STEP = 2;

template <class T>
class List
{
private:
    T *data;
    std::size_t size;
    std::size_t capacity;

    void copy(const List<T> &other);
    void deallocate();
    void resize();
    bool contains(T element);

public:
    List();
    List(const List<T> &other);
    ~List();

    void add(T element);
    void remove(std::size_t pos);

    std::size_t getSize();
    bool isEmpty();

    void write(std::string fileName);
    void read(std::string fileName);

    List &operator=(const List<T> &other);
    T &operator[](std::size_t index);
};

template <class T>
void List<T>::copy(const List<T> &other)
{
    size = other.size;
    capacity = other.capacity;
    data = new List[size];
    for (std::size_t i = 0; i < size; ++i)
    {
        data[i] = List(data[i]);
    }
}

template <class T>
void List<T>::deallocate()
{
    if (data)
    {
        delete[] data;
    }
}

template <class T>
void List<T>::resize()
{
    T *buffer = nullptr;
    try
    {
        buffer = new T[capacity * INCREASE_STEP];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (std::size_t i = 0; i < size; ++i)
    {
        buffer[i] = data[i];
    }

    deallocate();
    data = buffer;
    capacity *= INCREASE_STEP;
}

template <class T>
bool List<T>::contains(T element)
{
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
List<T>::List()
{
    size = 0;
    capacity = INITIAL_CAPACITY;

    try
    {
        data = new T[size];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <class T>
List<T>::List(const List<T> &other)
{
    copy(other);
}

template <class T>
List<T>::~List()
{
    deallocate();
}

template <class T>
void List<T>::add(T element)
{
    if (!contains(element))
    {
        if (size >= capacity)
        {
            resize();
        }

        data[size++] = element;
    }
}

template <class T>
void List<T>::remove(std::size_t pos)
{
    if (pos >= size)
    {
        throw std::out_of_range("Invalid index");
    }

    for (std::size_t i = pos; i < size - 1; ++i)
    {
        data[i] = data[i + 1];
    }

    --size;
}

template <class T>
std::size_t List<T>::getSize()
{
    return size;
}

template <class T>
bool List<T>::isEmpty()
{
    return size == 0;
}

template <class T>
void List<T>::write(std::string fileName)
{
    std::ofstream file(fileName.c_str());

    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < size; ++i)
    {
        file << data[i] << std::endl;
    }

    file.close();
}

template <class T>
void List<T>::read(std::string fileName)
{
    std::ifstream file(fileName.c_str());

    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return;
    }

    while (!file.eof())
    {
        T temp;
        file >> temp;
        add(temp);
    }

    file.close();
}

template <class T>
List<T> &List<T>::operator=(const List<T> &other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

template <class T>
T &List<T>::operator[](std::size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("invalid index");
    }

    return data[index];
}

#endif