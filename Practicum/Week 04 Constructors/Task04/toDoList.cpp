#include <iostream>
#include <cstring>
#include "toDoList.h"

using std::cin;
using std::cout;
using std::endl;

ToDoList::ToDoList()
{
    this->tasksCount = 0;
    this->tasksList = nullptr;
}

ToDoList::ToDoList(Task myTask)
{
    
}

void ToDoList::pushTask(Task myTask)
{

}

void ToDoList::popTask()
{

}

void ToDoList::printSize()
{

}

bool ToDoList::isEmpty()
{

}

ToDoList::~ToDoList()
{
    delete[] this->tasksList;
}