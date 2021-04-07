#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

/*
Задача 1:
Дефинирайте структурата DynArray, която има size, capacity и динамичен масив от тип int. 
Декларирайте следните функции към структурата в header файл и напишете дефинициите им в source файл:

1) create() - създава структурата с подходящ капацитет;
2) push_back() - добавя елемент в края на масива;
3) resize() - помощна функция за преоразмеряване на масива;
4) pop_back() - премахва елемент от края на масива;
5) get() - взима елемент по подаден индекс;
6) remove() - премахва елемент на подаден индекс;
7) eraseDynMemory() - изтрива динамично заделената памет*/
struct DynArray
{
	size_t size;
	size_t capacity;
	int* array;
};

// 1
DynArray create(size_t capacity = 2); 

// 2
void push_back(DynArray& dynArray, int element);

// 3
void resize(DynArray& dynArray);

// 4
void pop_back(DynArray& dynArray);

// 5 
int get(DynArray& dynArray, size_t index); 

// 6
void remove(DynArray& dynArray, size_t index);

// 7
void eraseDynMemory(DynArray& dynArray);

#endif

