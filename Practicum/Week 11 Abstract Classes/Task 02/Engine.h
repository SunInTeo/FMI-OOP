#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
    bool state;
public:
    Engine();

    void start();
    void stop();
};

#endif