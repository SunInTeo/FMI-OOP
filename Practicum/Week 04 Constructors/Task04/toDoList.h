#ifndef TODOLIST_H
#define TODOLIST_H

#include "task.h"

class ToDoList
{
    int tasksCount;
    Task *tasksList;
public:
    ToDoList();
    ToDoList(Task myTask);
    void pushTask(Task myTask);
    void popTask();
    void printSize();
    bool isEmpty();
    ~ToDoList();
};

#endif