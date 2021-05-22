#include "../Header files/Utils.h"
#include "../Header files/catch2.hpp"

TEST_CASE("toUpperCase() function check")
{
    std::string str1 = "123 This is a sample sentence 123";
    std::string str2 = "123 THIS IS A SAMPLE SENTENCE 123";
    REQUIRE(toUpperCase(str1) == str2);
}

TEST_CASE("strToInt() function check")
{
    SECTION("Correct input")
    {
        std::string str1 = "1234";
        unsigned int intStr = 1234;
        REQUIRE(stringToInt(str1) == intStr);
    }
    SECTION("Incorrect input")
    {
        bool didThrow = false;
        try
        {
            std::string str1 = "a1234";
            stringToInt(str1);
        }
        catch (const std::exception &e)
        {
            didThrow = true;
        }
        REQUIRE(didThrow);
    }
}
