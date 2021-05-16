#include "Student.h"

int main ()
{
    Human human1("Ivan", "Ivanov", 19), human2("Strahila", "Strahilova", 30);
    Student student1("Stoqn", "Georgiev", 20, "IS"), student2("Strahil", "Marinov", 19, "KN");

    human1.print();
    human2.print();
    student1.print();
    student2.print();

    return 0;
}