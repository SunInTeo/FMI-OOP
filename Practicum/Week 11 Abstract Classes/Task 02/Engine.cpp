#include <iostream>
#include "Engine.h"

Engine::Engine()
{
    state = false;
}

void Engine::start()
{
    std::cout << "Engine has started...\n";
    state = true;
}

void Engine::stop()
{
    std::cout << "Engine has stopped...\n";
    state = false;
}