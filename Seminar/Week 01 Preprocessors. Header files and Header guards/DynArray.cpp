#include <iostream>
#include "DynArray.h"

using std::cout;
using std::endl;

// 1
DynArray create(size_t capacity)
{
	DynArray dynArray;
	dynArray.capacity = capacity;
	dynArray.size = 0;
	dynArray.array = new int[dynArray.capacity];
	return dynArray;
}

// 2
void push_back(DynArray &dynArray, int element)
{
	if (dynArray.size == dynArray.capacity)
	{
		resize(dynArray);
	}

	dynArray.array[dynArray.size] = element;
	++dynArray.size;
}

// 3
void resize(DynArray &dynArray)
{
	int *oldArray = dynArray.array;
	
	dynArray.capacity *= 2;
	
	dynArray.array = new(std::nothrow) int[dynArray.capacity];


	for (size_t i = 0; i < dynArray.size; ++i)
	{
		dynArray.array[i] = oldArray[i];
	}

	delete[] oldArray;
}

// 4
void pop_back(DynArray &dynArray)
{
	--dynArray.size;
}

// 5
int get(DynArray &dynArray, size_t index)
{
	if (index < 0 || index >= dynArray.size)
	{
		cout << "Not a valid index" << endl;
		return -1;
	}

	return dynArray.array[index];
}

// 6
void remove(DynArray &dynArray, size_t index)
{
	if (index < 0 || index >= dynArray.size)
	{
		cout << "Not a valid index" << endl;
		return;
	}

	for (size_t i = index; i < dynArray.size - 1; ++i)
	{
		dynArray.array[i] = dynArray.array[i + 1];
	}

	--dynArray.size;
}

// 7
void eraseDynMemory(DynArray &dynArray)
{
	delete[] dynArray.array;
}
