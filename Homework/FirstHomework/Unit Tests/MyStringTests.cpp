#define CATCH_CONFIG_MAIN
#include "..\..\catch2\catch2.hpp"
#include "..\Header files\MyString.h"
#include "..\Header files\Helpers.h"

TEST_CASE("Default constructor check")
{
    MyString str;
    REQUIRE(str.empty() == 1);
    REQUIRE(str.size() == 0);
    //REQUIRE(m_strcmp(str.c_str(), nullptr));
}

TEST_CASE("Parametеrized constructor check")
{
    const char array[4] = "asd";
    MyString str(array);
    REQUIRE(str.empty() == 0);
    REQUIRE(str.size() == 3);
    REQUIRE(!m_strcmp(str.c_str(),"asd"));
}

TEST_CASE("Copy constructor check")
{
    const char array[4] = "asd";
    MyString str1(array);
    MyString str2(str1);
    REQUIRE(str2.empty() == 0);
    REQUIRE(str2.size() == 3);
    REQUIRE(!m_strcmp(str2.c_str(), str1.c_str()));
}

TEST_CASE("Return element at given position check")
{
    const char array[4] = "asd";
    MyString str(array);
    REQUIRE(str.at(1) == 's');
}

TEST_CASE("Operator [] check")
{
    const char array[4] = "asd";
    MyString str(array);
    REQUIRE(str[1] == 's');
}

TEST_CASE("Return element at front check")
{
    const char array[4] = "asd";
    MyString str(array);
    REQUIRE(str.front() == 'a');
}

TEST_CASE("Return element at back")
{
    const char array[4] = "asd";
    MyString str(array);
    REQUIRE(str.back() == 'd');
}

TEST_CASE("Push function check")
{
    const char array[4] = "asd";
    MyString str(array);
    char ch = 'x';
    str.push_back(ch);
    REQUIRE(!m_strcmp(str.c_str(), "asdx"));
}

TEST_CASE("Pop function check")
{
    const char array[4] = "asd";
    MyString str(array);
    str.pop_back();
    REQUIRE(!m_strcmp(str.c_str(), "as"));
}

TEST_CASE("Operator = MyString check")
{
    const char array1[4] = "asd";
    MyString str1(array1);
    MyString str2;
    str2 = str1;
    REQUIRE(!m_strcmp(str2.c_str(), "asd"));
}

TEST_CASE("Operator += char check")
{
    const char array[4] = "asd";
    MyString str(array);
    char ch = 'x';
    str += ch;
    REQUIRE(!m_strcmp(str.c_str(), "asdx"));
}

TEST_CASE("Operator += MyString check")
{
    const char array1[4] = "asd";
    const char array2[4] = "qwe";
    MyString str1(array1);
    MyString str2(array2);
    str1 += str2;
    REQUIRE(!m_strcmp(str1.c_str(), "asdqwe"));
}

TEST_CASE("Operator + char check")
{
    const char array[4] = "asd";
    MyString str(array);
    char ch = 'x';
    str = str + ch;
    REQUIRE(!m_strcmp(str.c_str(), "asdx"));
}

TEST_CASE("Operator + MyString check")
{
    const char array1[4] = "asd";
    const char array2[4] = "qwe";
    MyString str1(array1);
    MyString str2(array2);
    str1 = str1 + str2;
    REQUIRE(!m_strcmp(str1.c_str(), "asdqwe"));
}

TEST_CASE("Operator == check")
{
    const char array1[4] = "asd";
    const char array2[4] = "qwe";
    MyString str1(array1);
    MyString str2(array2);
    MyString str3(array1);
    REQUIRE((str1 == str2) == 0);
    REQUIRE((str1 == str3) == 1);
}

TEST_CASE("Operator != check")
{
    const char array1[4] = "asd";
    const char array2[4] = "qwe";
    MyString str1(array1);
    MyString str2(array2);
    MyString str3(array1);
    REQUIRE((str1 != str2) == 1);
    REQUIRE((str1 != str3) == 0);
}

TEST_CASE("Operator < check")
{
    const char array1[4] = "asd";
    const char array2[4] = "qwe";
    MyString str1(array1);
    MyString str2(array2);
    REQUIRE((str1 < str2) == 1);
    REQUIRE((str2 < str1) == 0);
}
