#include "../Header files/CommandAllocator.h"

void CommandAllocator::read(std::string fileName)
{
    std::ifstream file(fileName.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error while opening the file";
        return;
    }

    bool keepReading = true;
    do
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
            Command currentCommand(line);
            execCommand(currentCommand, std::cin);
        }

        keepReading = false;

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

    for (size_t i = 0; i < commmandsArray.size(); ++i)
    {
        if (i != 0)
        {
            file << std::endl;
        }

        file << commmandsArray[i].getCommand();
    }

    file.close();
}

void CommandAllocator::execCommand(const Command &myCmd, std::istream &istr)
{
    std::string firstCommand = toUpperCase(myCmd[0]);

    if (!strcmp(firstCommand.c_str(), "STOP"))
    {
        std::cout << "End of program" << std::endl;
        exit(0);
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
            std::size_t id = myAllocator.getType(myCmd[1]);
            bool hasPermission = false;
            switch (id)
            {
            case 1:
            {
                Registration reg(myCmd[1].c_str());
                if (myAllocator.getVehicleByID(reg)->getOwnerPtr())
                {
                    hasPermission = true;
                }
                break;
            }

            case 2:
            {
                if (myAllocator.getPersonByID(stringToInt(myCmd[1]))->ownsAtleastOneVehicle())
                {
                    hasPermission = true;
                }

                break;
            }

            default:
                break;
            }

            if (hasPermission)
            {
                if (&istr == &std::cin)
                {
                    std::cout << "Are you sure you want to use the REMOVE func? (Y/N)\n";
                }
                    
                std::string input;
                getline(istr, input);
                Command currentCommand(input);

                if (!strcmp(toUpperCase(currentCommand[0]).c_str(), "Y"))
                {
                    myAllocator.remove(myCmd[1]);
                    commmandsArray.push_back(myCmd);
                    commmandsArray.push_back(currentCommand);
                }
                else
                {
                    std::cerr << "Incorrect input, no changes were made.\n";
                }
            }
            else
            {
                myAllocator.remove(myCmd[1]);
                commmandsArray.push_back(myCmd);
            }
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
    std::string stopString;

    do
    {
        std::getline(std::cin, input);
        Command currentCommand(input);
        execCommand(currentCommand, std::cin);
        stopString = toUpperCase(currentCommand[0]);
    } while (stopString != "STOP");
}
