#include <cstring>
#include "helpers.h"

char* copyDynStr(const char* str) {
	char* res = new char[strlen(str) + 1];
	strcpy(res, str);
	return res;
}