#include <iostream>
#include "DynArray.h"

using std::cout;
using std::endl;

int main() {

	DynArray dynArray = create();

	push_back(dynArray, 10);
	push_back(dynArray, 20);

	cout << get(dynArray, 1) << endl;

	pop_back(dynArray);

	cout << get(dynArray, 0) << endl;
	
	eraseDynMemory(dynArray);

	cout << get(dynArray, 0) << endl;

	return 0;
}