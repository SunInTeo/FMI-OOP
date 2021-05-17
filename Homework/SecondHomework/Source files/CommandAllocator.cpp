#include "../Header files/CommandAllocator.h"

void CommandAllocator::read(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    std::string input;

    bool keepReading = true;
    do
    {
        getline(std::cin, input);
        if (!file.is_open())
        {
            std::cerr << "Error while opening the file";
            keepReading = false;
        }
        else
        {
            Command currentCommand(input);
            execCommand(currentCommand, keepReading);
        }
    } while (keepReading);

    file.close();
}

void CommandAllocator::save(std::string path)
{
    std::ofstream file(path.c_str());

    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < commmandsArray.size(); ++i)
    {
        if (i != 0)
        {
            file << std::endl;
        }
            
        std::string tempStr = commmandsArray.at(i).getCommand();
        file << tempStr;
    }

    file.close();
}

void CommandAllocator::execCommand(const Command &myCmd, bool &keepReading)
{
    std::string firstCommand = toUpperCase(myCmd[0]);

    if (!strcmp(firstCommand.c_str(), "STOP"))
    {
        keepReading = false;
        std::cout << "End of program" << std::endl;
    }

    else if (!strcmp(firstCommand.c_str(), "VEHICLE"))
    {
        try
        {
            myAllocator.createVehicle(myCmd[1], myCmd[2]);
            commmandsArray.push_back(myCmd);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    else if (!strcmp(firstCommand.c_str(), "PERSON"))
    {
        try
        {
            myAllocator.createPerson(myCmd[1], myCmd[2]);
            commmandsArray.push_back(myCmd);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    else if (!strcmp(firstCommand.c_str(), "ACQUIRE"))
    {
        try
        {
            myAllocator.acquire(myCmd[1], myCmd[2]);
            commmandsArray.push_back(myCmd);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    else if (!strcmp(firstCommand.c_str(), "RELEASE"))
    {
        try
        {
            myAllocator.release(myCmd[1], myCmd[2]);
            commmandsArray.push_back(myCmd);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    else if (!strcmp(firstCommand.c_str(), "REMOVE"))
    {
        try
        {
            myAllocator.remove(myCmd[1]);
            commmandsArray.push_back(myCmd);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    else if (!strcmp(firstCommand.c_str(), "SAVE"))
    {
        try
        {
            save(myCmd[1]);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    else if (!strcmp(firstCommand.c_str(), "SHOW"))
    {
        try
        {
            myAllocator.show(myCmd[1]);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    else
    {
        std::cout << "Command not recognised" << std::endl;
    }
}

CommandAllocator::CommandAllocator()
{
}

CommandAllocator::CommandAllocator(std::string path)
{
    read(path);
}

void CommandAllocator::start()
{
    std::string input;
    bool keepReading = true;

    do
    {
        getline(std::cin, input);
        Command currentCommand(input);
        execCommand(currentCommand, keepReading);
    } while (keepReading);
}