#Debug commands
g++ .\MyStringTests.cpp '..\Source files\MyString.cpp' '..\Source files\Helpers.cpp' ..\..\catch2\catch2.cpp

g++ .\VehicleTests.cpp '..\Source files\Vehicle.cpp' '..\Source files\MyString.cpp' '..\Source files\Helpers.cpp' ..\..\catch2\catch2.cpp

g++ .\GarageTests.cpp '..\Source files\Garage.cpp' '..\Source files\Vehicle.cpp' '..\Source files\MyString.cpp' '..\Source files\Helpers.cpp' ..\..\catch2\catch2.cpp

g++ .\VehicleAllocatorTests.cpp '..\Source files\VehicleAllocator.cpp' '..\Source files\Garage.cpp' '..\Source files\Vehicle.cpp' '..\Source files\MyString.cpp' '..\Source files\Helpers.cpp' ..\..\catch2\catch2.cpp