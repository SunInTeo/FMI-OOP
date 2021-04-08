#define CATCH_CONFIG_MAIN
#include <cstring>
#include "..\..\catch2\catch2.hpp"
#include "..\Solution\Person.h"

TEST_CASE("Person - dafeault cpnstructor")
{
    Person person;
  
    CHECK(person.getAge() == 20);
    CHECK(strcmp(person.getName(), "N/A") == 0);
    CHECK(person.getHasLicense() == false);
}

TEST_CASE("Person - constructor with parameters") 
{

    Person person("Test", 22, true);

    CHECK(person.getAge() == 22);
    CHECK(strcmp(person.getName(), "Test") == 0);
    CHECK(person.getHasLicense() == true);
}


TEST_CASE("Person - copy constructor") 
{

    Person person("Test", 22, true);

    Person person2 = person;

    CHECK(person2.getAge() == person.getAge());
    CHECK(strcmp(person2.getName(), person.getName()) == 0);
    CHECK(person2.getHasLicense() == person.getHasLicense());
}

TEST_CASE("Person - operator= ") 
{

    Person person("Test", 22, true);

    Person person2;

    CHECK(person2.getAge() == 20);
    CHECK(strcmp(person2.getName(), "N/A") == 0);
    CHECK(person2.getHasLicense() == false);

    person2 = person;

    CHECK(person2.getAge() == person.getAge());
    CHECK(strcmp(person2.getName(), person.getName()) == 0);
    CHECK(person2.getHasLicense() == person.getHasLicense());
}