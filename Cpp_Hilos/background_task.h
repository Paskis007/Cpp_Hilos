#pragma once
#include <stdio.h>

class background_task
{
public:
    void operator()() const
    {
        do_something();
        do_something_else();
    }
    void do_something() const
    {
        std::cout << "Hello, World cosa!" << std::endl;
    }
    void do_something_else() const
    {
        std::cout << "Hello, World cosa_2!" << std::endl;
    }
};