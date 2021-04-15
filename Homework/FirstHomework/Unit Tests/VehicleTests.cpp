#include "..\..\catch2\catch2.hpp"
#include "..\Header files\Vehicle.h"

TEST_CASE("Parameterized constructor check")
{
    MyString vhclLicense("1234");
    MyString vhclDescription("Blue");
    size_t vhclSpace = 5;
    Vehicle vhcl1(vhclLicense.c_str(), vhclDescription.c_str(), vhclSpace);
    
    REQUIRE(!m_strcmp(vhcl1.registration(), vhclLicense.c_str())); 
    REQUIRE(!m_strcmp(vhcl1.description(), vhclDescription.c_str()));
    REQUIRE(vhcl1.space() == vhclSpace);
}