#ifndef TASK_H
#define TASK_H

struct Task
{
    const static int MAX_NAME_LENGTH = 32;
    const static int MAX_DESCRIPTION_LENGTH = 32;

    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
};

#endif