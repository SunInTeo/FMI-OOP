#include <iostream>
#include "Jedi.h"

int main ()
{
    Jedi jedi1, jedi2;

    jedi1.addNewSkill("plays football");
    jedi1.addNewSkill("codes");
    jedi1.addNewSkill("eats");
    jedi1.addNewSkill("sleeps");
    jedi1.addNewSkill("plays the guitar");
    jedi1.setAge(19);

    jedi1.write("jedi1.txt");
    
    //jedi2.read("jedi2.txt"); //too lazy to add that file, it's on the TODO list
    //std::cout << jedi2;

    return 0;
}