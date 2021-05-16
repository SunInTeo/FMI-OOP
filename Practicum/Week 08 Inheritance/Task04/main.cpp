#include "Surgeon.h"
#include "Dentist.h"

int main ()
{
    Surgeon mySurgeon("Dr. Boyadziev");
    Dentist myDentist("Dr. Koleva");

    mySurgeon.performSurgery();
    myDentist.performSurgery();

    return 0;
}