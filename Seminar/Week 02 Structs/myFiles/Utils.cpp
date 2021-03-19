#include <cstring>
#include "Utils.h"

void copyStr(char *buffer, char *&field)
{
    field = new char[strlen(buffer) + 1];
    strcpy(field, buffer);
}
